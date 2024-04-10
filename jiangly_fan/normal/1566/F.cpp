#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, m;
        cin >> n >> m;
        vector<LL> v(n);
        for (LL& x : v) cin >> x;
        sort(v.begin(), v.end());
        vector<pair<LL, LL>> vp(m);
        for (auto& [l, r] : vp) {
            cin >> l >> r;
            r = -r;
        }
        sort(vp.begin(), vp.end());
        vector<pair<LL, LL>> p;
        for (auto [l, r] : vp) {
            r = -r;
            while (not p.empty() and p.back().second > r) p.pop_back();
            p.push_back({l, r});
        }
        m = p.size();
        vector<vector<pair<LL, LL>>> pre(n + 1);
        for (int i = 0, j = 0; i < m; i += 1) {
            while (j < n and v[j] < p[i].first) j += 1;
            if (j < n and p[i].first <= v[j] and v[j] <= p[i].second) continue;
            pre[j].push_back(p[i]);
        }
        vector<LL> f(n), g(n);
        if (pre[0].size() != 0) {
            f[0] = v[0] - pre[0][0].second;
            g[0] = f[0] * 2;
        }
        for (int i = 1; i < n; i += 1) {
            if (pre[i].empty())
                f[i] = g[i] = min(f[i - 1], g[i - 1]);
            else {
                f[i] = g[i] = LLONG_MAX;
                for (int j = 0; j <= (int)pre[i].size(); j += 1)
                    for (int frm = 0; frm < 2; frm += 1)
                        for (int cur = 0; cur < 2; cur += 1) {
                            LL x = (frm ? g : f)[i - 1];
                            if (j) x += (frm ? 1 : 2) * (pre[i][j - 1].first - v[i - 1]);
                            if (j != (int)pre[i].size()) x += (cur ? 2 : 1) * (v[i] - pre[i][j].second); 
                            if (cur) g[i] = min(g[i], x);
                            else f[i] = min(f[i], x);
                        }
            }
            //cout << f[i] << " " << g[i] << "\n";
        }
        if (pre[n].empty()) cout << min(f.back(), g.back()) << "\n";
        else cout << min(f.back() + 2 * (pre.back().back().first - v.back()), g.back() + (pre.back().back().first - v.back())) << "\n";
    }
    return 0;
}