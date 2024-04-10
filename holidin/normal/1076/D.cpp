#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;
set <pair<long long, pair<int, int> > > s;
vector <pair<int, pair<int, int> > > e[N];
long long d[N];
bool use[N];

int main() {
    int i, j, n, m, k, x, y, w;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (i = 1; i <= m; ++i) {
        cin >> x >> y >> w;
        e[x].push_back({y, {w, i}});
        e[y].push_back({x, {w, i}});
    }
    vector <int> ans;
    use[1] = true;
    d[1] = 0;
    for (i = 0; i < e[1].size(); ++i)
    s.insert({(long long)e[1][i].se.fi, {e[1][i].fi, e[1][i].se.se}});
    while (ans.size() < k && s.size() > 0) {
        pair<long long, pair<int, int> > p = *s.begin();
        s.erase(p);
        if (use[p.se.fi])
            continue;
        int u = p.se.fi;
        d[u] = p.fi;
        use[u] = true;
        ans.push_back(p.se.se);
        for (i = 0; i < e[u].size(); ++i)
        s.insert({d[u] + e[u][i].se.fi, {e[u][i].fi, e[u][i].se.se}});
    }
    cout << ans.size() << "\n";
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
}