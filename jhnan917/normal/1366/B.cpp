#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, m;
        scanf("%d %d %d", &n, &x, &m);
        int L = x, R = x;
        while (m--) {
            int l, r;
            scanf("%d %d", &l, &r);
            if (R < l || r < L) continue;
            L = min(L, l);
            R = max(r, R);
        }
        printf("%d\n", R - L + 1);
    }
}