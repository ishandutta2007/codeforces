#include <cstdio>
#include <iostream>

int main() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d);
        if (d < l)
            printf("%d\n", d);
        else if (r % d != 0) {
            printf("%d\n", r + ((d - r) % d + d) % d);
        } else
            printf("%d\n", r + d);
    }
    return 0;
}