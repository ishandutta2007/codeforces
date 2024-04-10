#include <cstdio>
#include <iostream>

int main() {
    int N;
    scanf("%d", &N);
    int minr1 = 1337133713, minr2 = 1337133713, maxl1 = 0, maxl2 = 0;
    int l, r;
    while (N--) {
        scanf("%d%d", &l, &r);
        minr1 = std::min(minr1, r);
        maxl1 = std::max(maxl1, l);
    }
    int M;
    scanf("%d", &M);
    while (M--) {
        scanf("%d%d", &l, &r);
        minr2 = std::min(minr2, r);
        maxl2 = std::max(maxl2, l);
    }
    printf("%d", std::max(0, std::max(maxl1 - minr2, maxl2 - minr1)));
    return 0;
}