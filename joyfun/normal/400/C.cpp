#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n, m, x, y, z, p, i, j;
struct Point {
    int x, y;
} po[100005];

void at(Point &a) {
    int x = a.x, y = a.y;
    a.y = n - x + 1;
    a.x = y;
}

void ht(Point &a) {
    int x = a.x, y = a.y;
    a.y = m - y + 1;
    a.x = x;
}

void ct(Point &a) {
    int x = a.x, y = a.y;
    a.y = x;
    a.x = m - y + 1;
}

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);
    x %= 4;
    y %= 2;
    z %= 4;
    for (i = 0; i < p; i++)
        scanf("%d%d", &po[i].x, &po[i].y);
    for (j = 0; j < x; j++) {
        for (i = 0; i < p; i++) {
            at(po[i]);
        }
        int t = n; n = m; m = t;
    }
    for (j = 0; j < y; j++) {
        for (i = 0; i < p; i++) {
            ht(po[i]);
        }
    }
    for (j = 0; j < z; j++) {
        for (i = 0; i < p; i++) {
            ct(po[i]);
        }
        int t = n; n = m; m = t;
    }
    for (i = 0; i < p; i++)
        printf("%d %d\n", po[i].x, po[i].y);
    return 0;
}