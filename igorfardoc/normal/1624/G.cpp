#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;
vector<bool> used;

int dfs(int v) {
    used[v] = true;
    int ans = 1;
    for(int u : g[v]) {
        if(used[u]) continue;
        ans += dfs(u);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> e(m);
        for(int i = 0; i < m; i++) {
            int v, u, w;
            cin >> v >> u >> w;
            --v;
            --u;
            e.push_back({v, u, w});
        }
        int ans = 0;
        for(int b = 29; b >= 0; b--) {
            g.assign(n, vi(0));
            used.assign(n, false);
            vector<array<int, 3>> new1;
            bool ok = true;
            for(const auto& el : e) {
                if(!((el[2] >> b) & 1)) {
                    g[el[0]].push_back(el[1]);
                    g[el[1]].push_back(el[0]);
                    new1.push_back(el);
                }
            }
            if(dfs(0) == n) {
                e = new1;
            } else {
                ans ^= (1 << b);
            }
        }
        cout << ans << '\n';
    }
}