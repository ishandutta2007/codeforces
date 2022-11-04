#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<vector<pair<int, int>>> g;
vi ans;

void dfs(int v, int p, int val) {
    for(auto& u1 : g[v]) {
        int u = u1.first;
        int id1 = u1.second;
        if(u == p) continue;
        ans[id1] = val;
        dfs(u, v, 5 - val);
    }
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
        int n;
        cin >> n;
        ans.resize(n - 1);
        g.assign(n, vector<pair<int, int>>(0));
        for(int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[v].push_back({u, i});
            g[u].push_back({v, i});
        }
        bool ok = true;
        int start = 0;
        for(int i = 0; i < n; i++) {
            if(g[i].size() > 2) ok = false;
            if(g[i].size() == 1) start = i;
        }
        if(!ok) {
            cout << -1 << '\n';
            continue;
        }
        dfs(start, -1, 2);
        for(const auto& el : ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}