#include <bits/stdc++.h>

using namespace std;

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (max(l1, l2) <= min(r1, r2))
            printf("%d\n", max(l1, l2));
        else
            printf("%d\n", l1 + l2);
    }
    return 0;
}