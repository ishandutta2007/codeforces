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

int n, m;
vector<pll> edge[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        edge[x].emplace_back(y, c);
        edge[y].emplace_back(x, -c);
    }
    for (int x = 1; x <= n; ++x) {
        sort(edge[x].begin(), edge[x].end());
        vector<pll> nedge;
        for (auto i : edge[x]) {
            if (!nedge.empty() && nedge.back().fs == i.fs) {
                nedge.back().se += i.se;
            }
            else nedge.push_back(i);
        }
        edge[x] = nedge;
        vector<pll> inc, dec;
        for (auto i : edge[x]) {
            if (i.se > 0) {
                inc.emplace_back(i.fs, i.se);
            }
            else if (i.se < 0) {
                dec.emplace_back(i.fs, -i.se);
            }
        }
        while (!inc.empty() && !dec.empty()) {
            pll a = inc.back();
            pll b = dec.back();
            llong val = min(a.se, b.se);
            edge[a.fs].emplace_back(b.fs, -val);
            edge[a.fs].emplace_back(x, val);
            edge[b.fs].emplace_back(a.fs, val);
            edge[b.fs].emplace_back(x, -val);
            edge[x].emplace_back(a.fs, -val);
            edge[x].emplace_back(b.fs, val);
            if (a.se < b.se) {
                inc.pop_back();
                dec.back().se -= a.se;
            }
            else if (a.se > b.se) {
                dec.pop_back();
                inc.back().se -= b.se;
            }
            else {
                inc.pop_back();
                dec.pop_back();
            }
        }
    }
    for (int x = 1; x <= n; ++x) {
        sort(edge[x].begin(), edge[x].end());
        vector<pll> nedge;
        for (auto i : edge[x]) {
            if (!nedge.empty() && nedge.back().fs == i.fs) {
                nedge.back().se += i.se;
            }
            else nedge.push_back(i);
        }
        edge[x] = nedge;
    }
    vector<pii> ans;
    vector<llong> V;
    for (int i = 1; i <= n; ++i) {
        for (auto j : edge[i]) {
            if (j.se <= 0) continue;
            ans.emplace_back(i, j.fs);
            V.push_back(j.se);
        }
    }
    printf("%u\n", ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d %d %lld\n", ans[i].fs, ans[i].se, V[i]);
    }
    return 0;
}