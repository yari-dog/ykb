#include "quantum.h"
#include "qp.h"
#include "graphics/yama.qgf.h"
painter_device_t display;

void display_init_kb(void) {
	// Set up the display
	display = qp_gc9a01_make_spi_device(240,240, DISPLAY_CS, DISPLAY_DC, DISPLAY_RST, 2, 0);
	painter_image_handle_t yama;
	yama = qp_load_image_mem(gfx_yama); // Load the image into memory
	qp_drawimage(display, 0, 0, yama); // Draw the image to the display
}

void keyboard_post_init_kb(void) {
	display_init_kb();
	keyboard_post_init_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	return process_record_user(keycode, record);
}
