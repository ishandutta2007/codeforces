#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define uniq(x) x.resize(unique(x.begin(), x.end()) - x.begin())
using namespace std;
const int N = 3e6 + 52;
const long long inf = 1e10;
int t[30], a[N];
pair<int, int> p[N];

void addc(int u, int x) {
    if (p[u].fi != x && p[u].fi < x) {
        p[u].se = p[u].fi;
        p[u].fi = x;
    }
    if (p[u].fi != x && p[u].se < x) {
        p[u].se = x;
    }
}

void solve() {
    int i, j, k, b, n;
    t[0] = 1;
    for (i = 1; i <= 21; ++i)
        t[i] = t[i - 1] * 2;
    cin >> n;
    for (i = 0; i < t[21]; ++i)
        p[i] = {-1, -1};
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        addc(a[i], i);
    }
    for (i = t[21] - 1; i >= 0; --i) {
        for (j = 0; j <= 20; ++j)
        if ((i & t[j]) > 0) {
            addc(i - t[j], p[i].fi);
            addc(i - t[j], p[i].se);
        }
    }
    int ans = 0;
    for (i = 1; i <= n - 2; ++i) {
        int tek = 0;
        for (j = 20; j >= 0; --j)
            if ((a[i] & t[j]) == 0)
                if (p[tek + t[j]].se > i) {
                    tek += t[j];
                }
        ans = max(ans, tek + a[i]);
    }
    cout << ans << "\n";
}

signed main() {
    int i, test;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}