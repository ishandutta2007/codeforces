#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<set<int>> g;
vector<set<int>> taken;
vi ans;
vector<pair<int, int>> res;


void dfs1(int v) {
    vector<pair<int, int>> st;
    st.push_back({v, -1});
    while(!st.empty()) {
        auto p = st[st.size() - 1];
        int v = p.first;
        int u = p.second;
        if(u != -1) {
            ans.push_back(u);
        }
        if(g[v].empty()) {
            st.pop_back();
            continue;
        }
        u = *(g[v].begin());
        st[st.size() - 1].second = u;
        g[v].erase(u);
        g[u].erase(v);
        st.push_back({u, -1});
    }
}
void dfs(int v) {
    while(!g[v].empty()) {
        int u = *(g[v].begin());
        g[v].erase(g[v].begin());
        g[u].erase(g[u].find(v));
        dfs(u);
        ans.push_back(u);
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
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[v].insert(u);
        g[u].insert(v);
    }
    taken = g;
    for(int i = 1; i <= n; i++) {
        if(g[i].size() % 2 == 1) {
            g[i].insert(0);
            g[0].insert(i);
        }
    }
    for(int i = 0; i <= n; i++) {
        if(g[i].empty()) continue;
        ans.clear();
        dfs1(i);
        /*for(const auto& el : ans) {
            cout << el << ' ';
        }
        cout << endl;*/
        for(int j = 0; j < ans.size(); j+=2) {
            int v = ans[j];
            int u = ans[(j + 1) % ans.size()];
            if(v == 0 || u == 0) {
                continue;
            }
            res.push_back({v, u});
            taken[v].erase(u);
            taken[u].erase(v);
        }
        for(int j = 0; j < ans.size(); j+=2) {
            int v = ans[j];
            int u = ans[(j + 1) % ans.size()];
            if(u == 0) {
                if(!taken[v].empty()) {
                    int u1 = *(taken[v].begin());
                    taken[v].erase(u1);
                    taken[u1].erase(v);
                    res.push_back({v, u1});
                }
            } else if(v == 0) {
                if(!taken[u].empty()) {
                    int u1 = *(taken[u].begin());
                    taken[u].erase(u1);
                    taken[u1].erase(u);
                    res.push_back({u, u1});
                }
            }
        }
    }
    cout << res.size() << '\n';
    for(const auto& el : res) {
        cout << el.first << ' ' << el.second << '\n';
    }
}