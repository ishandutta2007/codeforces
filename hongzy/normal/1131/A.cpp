#include <algorithm>
#include <cstdio>

int w1, h1, w2, h2;

int main() {
    scanf("%d%d%d%d", &w1, &h1, &w2, &h2);
    printf("%d\n", w1 + 2 + 2 * h1 + w2 + 2 + 2 * h2 + w1 - w2);
    return 0;
}