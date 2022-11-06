#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

pll operator-(pll a, pll b) {
    return pii(a.fs - b.fs, a.se - b.se);
}

int ccw(pll a, pll b) {
    llong v = a.fs * b.se - a.se * b.fs;
    if (v < 0) return -1;
    if (v > 0) return 1;
    return 0;
}

int n;
pll P[2501];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> P[i].fs >> P[i].se;
    }
    llong ans = n * (n - 1ll) * (n - 2) * (n - 3) * (n - 4) / 24;
    for (int i = 1; i <= n; ++i) {
        vector<pll> S;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            S.push_back(P[j] - P[i]);
        }
        sort(S.begin(), S.end(), [&](pll a, pll b) {
            if (a.se == 0 && b.se == 0) return a.fs > b.fs;
            if (a.se * b.se < 0) return a.se > 0;
            return ccw(a, b) > 0;
        });
        for (int j = 0, k = 1; j < n - 1; ++j) {
            while (j != k && ccw(S[j], S[k]) > 0) k = (k + 1) % (n - 1);
            llong cnt = (k - j + n + n - 3) % (n - 1);
            ans -= cnt * (cnt - 1) * (cnt - 2) / 6;
        }
    }
    printf("%lld\n", ans);
    return 0;
}