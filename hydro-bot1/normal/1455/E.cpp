// Hydro submission #614449f647029aa933ff0ca5@1631865334678
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[4], b[4], c[4];
int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        for (int i = 0; i < 4; i++) {
            scanf("%d%d", &a[i], &b[i]);
            c[i] = i;
        }
        LL ans = 1e18;
        while (1) {
            LL x0 = a[c[0]], y0 = b[c[0]];
            LL x1 = a[c[1]], y1 = b[c[1]];
            LL x2 = a[c[2]], y2 = b[c[2]];
            LL x3 = a[c[3]], y3 = b[c[3]];
            LL now = abs(x0 - x2) + abs(x1 - x3) + abs(y0 - y1) + abs(y2 - y3);
            LL r1 = max(x1, x3) - min(x0, x2), l1 = min(x1, x3) - max(x0, x2);
            LL r2 = max(y0, y1) - min(y2, y3), l2 = min(y0, y1) - max(y2, y3);
            now += 2 * max(0LL, max(l1, l2) - min(r1, r2));
            if (r1 >= 0 && r2 >= 0)
                ans = min(ans, now);
            if (next_permutation(c, c + 4) == 0) break;
        }
        cout << ans << endl;
    }
    return 0;
}