// Hydro submission #62908beb37e0de7afd39a417@1653640172253
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define r(i, a, b) for (int i = (a); i <= (b); i ++)
int n, a[N], b[N], v[N], s, x;
int d(int x) { v[x] = 0;
    if (!v[b[x]]) return 1;
    else return d(b[x]) + 1;
}
int $() { cin >> x; return x; }
signed main() {
    for (int T = $(); T --;) { n = $();
        r(i, 1, n) a[$()] = i, v[i] = 1;
        r(i, 1, n) b[i] = a[$()]; s = 0;
        r(i, 1, n) s += v[i] * d(i) / 2;
        cout << 2ll * s * (n - s) << endl;
    }
    return 0;
}