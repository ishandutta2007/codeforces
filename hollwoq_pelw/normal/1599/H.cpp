#include <bits/stdc++.h>

using namespace std;

const int R = 1000000000;

int q(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    ignore = scanf("%d", &x);
    if (x < 0) exit(0);
    return x;
}

int main() {
    int64_t a = q(1, 1);
    int64_t b = q(1, R);
    int y = (a - b + R) / 2;
    int xl = q(1, y);
    int xr = R - q(R, y);
    int yl = q(xl, 1);
    int yr = R - q(xl, R);
    printf("! %d %d %d %d\n", xl + 1, yl, xr, yr + 1);
    fflush(stdout);
    ignore = scanf("%d", &y);
    if (y < 0) return 0;
    
    return 0;
}