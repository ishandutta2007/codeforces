#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define double long double
using namespace std;
const int N = 3e5 + 1;
const int mod = 1e9 + 7;


double h[N], r[N], R[N], H[N];

double willR(int h, int R, int r, double x) {
    if (x >= h)
        return 0;
    else
        return (x / h) * (R - r) + r;
}

double newh(double xwas, double hwas, double Rwas, double rwas, double h, double R, double r) {
    double x = 0;
    if (rwas < r)
        if (r >= Rwas)
            x = max(x, hwas);
        else
            x = max(x, ((r - rwas) * 1.0 / (Rwas - rwas)) * hwas);
    if (rwas < R)
        if (R >= Rwas)
            x = max(x, hwas - h);
        else
            x = max(x, ((R - rwas) * 1.0 / (Rwas - rwas)) * hwas - h);
    if (Rwas < R)
        if (Rwas < r) {
            x = max(x, hwas);
        } else
            x = max(x, hwas - (1 - (R - Rwas) / (R - r)) * h);
    return x + xwas;
}


void solve() {
    int i, j, k, n, m, q;
    cin >> n;
    double ans = 0;
    for (i = 0; i < n; ++i) {
        cin >> h[i] >> r[i] >> R[i];
        H[i] = 0;
        for (j = 0; j < i; ++j)
            H[i] = max(H[i], newh(H[j], h[j], R[j], r[j], h[i], R[i], r[i]));
        ans = max(ans, H[i] + h[i]);
    }
    cout << fixed << setprecision(15) << ans;
}

signed main() {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}