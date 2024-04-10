// Hydro submission #623c5b06f7716b87f5f0596d@1648122630801
#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}

#define INF (1e9 + 7)
int a[200010];

signed main() {
    for (int T = read(); T --;) {
        int n = read(), k = read(), Mx = -INF, Mn = INF;
        for (int i = 1; i <= n; i ++) {
            a[i] = read();
            Mx = max(Mx, a[i]);
            Mn = min(Mn, a[i]);
        }
        if (k & 1) {
            for (int i = 1; i <= n; i ++) {
                printf("%lld ", Mx - a[i]);
            }
        } else {
            for (int i = 1; i <= n; i ++) {
                printf("%lld ", a[i] - Mn);
            }
        }
        puts("");
    }
    return 0;
}