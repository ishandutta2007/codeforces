#include <cstdio>
#include <algorithm>

int maxX, maxY;

int main() {
    int N;
    scanf("%d", &N);
    char c;
    int x, y;
    while (N--) {
        scanf(" %c", &c);
        scanf("%d%d", &x, &y);
        if (x < y)
            std::swap(x, y);
        if (c == '+') {
            maxX = std::max(maxX, x);
            maxY = std::max(maxY, y);
        } else {
            if (x < maxX || y < maxY) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        }
    }
    return 0;
}