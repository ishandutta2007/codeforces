#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 5e5 + 1;
const int inf = 1e9;

map <int, int> m;
int cnt[N], pr[N], prcnt[N];
vector <int> v[N];

void solve() {
    int i, j, k, n, l, a1, b1;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        ++m[j];
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        ++cnt[(*it).second];
        v[(*it).second].push_back((*it).first);
    }
    pr[0] = 0;
    prcnt[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pr[i] = pr[i - 1] + i * cnt[i];
        prcnt[i] = prcnt[i - 1] + cnt[i];
    }
    int w1 = -inf, ans = 0;
    for (int w = 1; w <= n; ++w) {
        int jj = pr[w] + (prcnt[n] - prcnt[w]) * w;
        if (jj / w >= w)
        if (ans < (jj / w) * w) {
            w1 = w;
            ans = (jj / w) * w;
        }
    }
    cout << ans << "\n";
    int h = ans / w1;
    int w = w1;
    cout << h << ' ' << w1 << "\n";
    vector <vector <int> > an(h);
    vector <pair<int, int> > vv;
    vector <int> g;
    for (i = 0; i < h; ++i)
        an[i].resize(w);
    for (i = 0; i < h; ++i)
    for (j = 0; j < w; ++j)
        vv.push_back({(i + j) % h, j});
    for (i = n; i >= 1; --i)
    for (j = 0; j < v[i].size(); ++j)
    for (l = 0; l < min(i, w); ++l) {
        g.push_back(v[i][j]);
    }
    for (i = 0; i < ans; ++i)
        an[vv[i].fi][vv[i].se] = g[i];
    for (i = 0; i < h; ++i) {
        for (j = 0; j < w; ++j)
            cout << an[i][j] << ' ';
        cout << "\n";
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test;
    solve();
}