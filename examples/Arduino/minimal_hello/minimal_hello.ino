/**
 * Minimal "hello" sketch for the UEDX46460015-MD50E display.
 */

#include <Arduino.h>
#include <esp_display_panel.hpp>
#include <lvgl.h>

#include "lvgl_v8_port.h"

using namespace esp_panel::board;

void setup()
{
    Serial.begin(115200);
    Serial.println("Initializing board");

    Board *board = new Board();
    board->init();
    assert(board->begin());

    Serial.println("Initializing LVGL");
    lvgl_port_init(board->getLCD(), board->getTouch());

    lvgl_port_lock(-1);
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello, MD50E!");
    lv_obj_center(label);
    lvgl_port_unlock();
}

void loop()
{
    delay(1000);
}
