#include <iostream>
#include <algorithm>

const int max_size = 2000;
int width, height;
char monitor[max_size][max_size];

int min_x = max_size, min_y = max_size, max_x = 0, max_y = 0;

inline bool is_rect_empty(int left, int right, int top, int bottom) {
    for(int x = left; x <= right; x++)
        for(int y = top; y <= bottom; y++)
            if(monitor[x][y] == 'w')
                return false;
    return true;
}

void draw0(int x, int y) {
    if(monitor[x][y] != 'w')
        monitor[x][y] = '+';
}

void draw(int left, int right, int top, int bottom) {
//    std::cerr << "drawing " << left << " " << right << " " << top << " " << bottom << std::endl;
    for(int x = left; x <= right; x++) {
        draw0(x, top);
        draw0(x, bottom);
    }
    for(int y = top; y <= bottom; y++) {
        draw0(left, y);
        draw0(right, y);
    }
}

bool try_to_solve() {
    if(!is_rect_empty(min_x + 1, max_x - 1, min_y + 1, max_y - 1))
        return false;
    if(max_x - min_x == max_y - min_y) {
        draw(min_x, max_x, min_y, max_y);
        return true;
    } else if(max_x - min_x < max_y - min_y) {
        if(min_x == max_x && !is_rect_empty(min_x, min_x, min_y + 1, max_y - 1)) {
            if(width - 1 - min_x >= max_y - min_y) {
                draw(min_x, min_x + max_y - min_y, min_y, max_y);
                return true;
            }
            if(max_x - 0 >= max_y - min_y) {
                draw(max_x - (max_y - min_y), max_x, min_y, max_y);
                return true;
            }
        } else {
            int e_min_x = min_x, e_max_x = max_x;
            if(is_rect_empty(min_x, min_x, min_y + 1, max_y - 1))
                e_min_x = 0;
            if(is_rect_empty(max_x, max_x, min_y + 1, max_y - 1))
                e_max_x = width - 1;
            if(e_max_x - e_min_x >= max_y - min_y) {
                if(min_x == e_min_x || (max_x != e_max_x && min_x + max_y - min_y < width))
                    draw(min_x, min_x + max_y - min_y, min_y, max_y);
                else
                    draw(e_max_x - (max_y - min_y), e_max_x, min_y, max_y);
                return true;
            }
        }
    } else { /* max_x - min_x > max_y - min_y */
        if(min_y == max_y && !is_rect_empty(min_x + 1, max_x - 1, min_y, min_y)) {
            if(height - 1 - min_y >= max_x - min_x) {
                draw(min_x, max_x, min_y, min_y + max_x - min_x);
                return true;
            }
            if(max_y - 0 >= max_x - min_x) {
                draw(min_x, max_x, max_y - (max_x - min_x), max_y);
                return true;
            }
        } else {
            int e_min_y = min_y, e_max_y = max_y;
            if(is_rect_empty(min_x + 1, max_x - 1, min_y, min_y))
                e_min_y = 0;
            if(is_rect_empty(min_x + 1, max_x - 1, max_y, max_y))
                e_max_y = height - 1;
            if(e_max_y - e_min_y >= max_x - min_x) {
                if(min_y == e_min_y || (max_y != e_max_y && min_y + max_x - min_x < height))
                    draw(min_x, max_x, min_y, min_y + max_x - min_x);
                else
                    draw(min_x, max_x, e_max_y - (max_x - min_x), e_max_y);
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::cin >> height >> width;
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++) {
            std::cin >> monitor[x][y];
            if(monitor[x][y] == 'w') {
                min_x = std::min(min_x, x);
                min_y = std::min(min_y, y);
                max_x = std::max(max_x, x);
                max_y = std::max(max_y, y);
            }
        }
    if(!try_to_solve()) {
        std::cout << "-1" << std::endl;
    } else {
        for(int y = 0; y < height; y++) {
            for(int x = 0; x < width; x++)
                std::cout << monitor[x][y];
            std::cout << std::endl;
        }
    }
}