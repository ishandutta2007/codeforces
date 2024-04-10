#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 1;
const int mod = 1e9 + 7;
const long double eps = 1e-9;

long double xl[N], xr[N], y[N];


void solve() {
    int n, i, j, k;
    vector <pair<long double, int> > v;
    cin >> n;
    int sminx = 0, sminy = 0, smaxx = 0, smaxy = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> xl[i] >> xr[i] >> y[i];
        if (y[i] > sminy || (y[i] == sminy && xl[i] < sminx)) {
            sminx = xl[i];
            sminy = y[i];
        }
        if (y[i] < smaxy || (y[i] == smaxy && xr[i] > smaxx)) {
            smaxx = xr[i];
            smaxy = y[i];
        }
    }

    if (sminy == smaxy) {
        cout << smaxx - sminx << endl;
        return;
    }
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        if (y[i] > y[j]) {
            long double l = (xl[j] - xr[i]) / (y[i] - y[j]);
            long double r = (xr[j] - xl[i]) / (y[i] - y[j]);
            v.push_back({l, 1});
            v.push_back({r, -1});
            v.push_back({(xr[j] - xr[i]) * 1.0 / (y[i] - y[j]), 10 + i});
            v.push_back({(xl[j] - xl[i]) * 1.0 / (y[i] - y[j]), 10 + j});
        }
    }
    sort(v.begin(), v.end());
    i = 0;
    int balance = 0;
    long double ans = 1e18;
    while (i < v.size()) {
        int j = i;
        int open = 0, closed = 0;
        while (j < v.size() && abs(v[i].fi - v[j].fi) < eps) {
            if (v[j].se == 1)
                ++open;
            if (v[j].se == -1)
                ++closed;
            if (v[j].se >= 5) {
                int u = v[j].se - 10;
                long double c = v[i].fi;
                if (sminx + sminy * (c + eps) > xl[u] + y[u] * (c + eps)) {
                    sminx = xl[u];
                    sminy = y[u];
                }
                if (0)
                if (abs(c) < 1e-8 && u == 2)
                    cout << u << endl;
                if (smaxx + smaxy * (c + eps) < xr[u] + y[u] * (c + eps)) {
                    smaxx = xr[u];
                    smaxy = y[u];
                }
            }
            ++j;
        }
        if (balance <= closed) {
            if (0)
            for (int u = 0; u < n; ++u) {
                long double c = v[i].fi;
                if (sminx + sminy * c + eps > xl[u] + y[u] * c) {
                    sminx = xl[u];
                    sminy = y[u];
                }
                if (smaxx + smaxy * c < eps + xr[u] + y[u] * c) {
                    smaxx = xr[u];
                    smaxy = y[u];
                }
            }
            //cout << v[i].fi << ' '  << smaxy << ' ' << smaxx << endl;
            ans = min(ans, smaxx + v[i].fi * smaxy - sminx - v[i].fi * sminy);
        }
        balance += open - closed;
        i = j;
    }
    cout << fixed << setprecision(12) << ans << "\n";
}

signed main() {
    #ifdef local
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    int test = 0;
    solve();
}