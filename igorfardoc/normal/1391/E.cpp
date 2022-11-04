#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m;
vvi g;
vi st;
vi d;
vector<bool> used;

bool dfs(int v, int depth) {
    used[v] = true;
    st.push_back(v);
    d[v] = depth;
    if(st.size() >= (n - 1) / 2 + 1) {
        return true;
    }
    for(int u : g[v]) {
        if(used[u]) continue;
        if(dfs(u, depth + 1)) {
            return true;
        }
    }
    st.pop_back();
    return false;
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
        cin >> n >> m;
        g.assign(n, vi(0));
        for(int i = 0; i < m; i++) {
            int v, u;
            cin >> v >> u;
            --v;
            --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        st.clear();
        d.resize(n);
        used.assign(n, false);
        if(dfs(0, 0)) {
            cout << "PATH\n";
            cout << st.size() << '\n';
            for(int i = 0; i < st.size(); i++) {
                cout << st[i] + 1 << ' ';
            }
            cout << '\n';
            continue;
        }
        vvi d1(n);
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++) {
            d1[d[i]].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            while(d1[i].size() > 1) {
                pair<int, int> p = {0, 0};
                p.first = d1[i][d1[i].size() - 1];
                d1[i].pop_back();
                p.second = d1[i][d1[i].size() - 1];
                d1[i].pop_back();
                ans.push_back(p);
            }
        }
        cout << "PAIRING\n";
        cout << ans.size() << '\n';
        for(auto& el : ans) {
            cout << el.first + 1 << ' ' << el.second + 1 << '\n';
        }
    }


}