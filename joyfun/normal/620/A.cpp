#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int dx = x1 - x2;
    if (dx < 0) dx = -dx;
    int dy = y1 - y2;
    if (dy < 0) dy = -dy;
    printf("%d\n", max(dx, dy));
    return 0;
}