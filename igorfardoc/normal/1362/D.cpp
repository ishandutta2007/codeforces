#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vvi g;



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
    g.resize(n);
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    vector<pair<int, int>> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i].first;
        t[i].second = i;
    }
    sort(t.begin(), t.end());
    vi now(n, 0);
    for(int i = 0; i < n; i++) {
        int v = t[i].second;
        vector<bool> used(g[v].size() + 2, false);
        for(int u : g[v]) {
            used[now[u]] = true;
        }
        int here = -1;
        for(int i = 1; i < used.size(); i++) {
            if(!used[i]) {
                here = i;
                break;
            }
        }
        if(here != t[i].first) {
            cout << -1;
            return 0;
        }
        now[v] = t[i].first;
    }
    for(int i = 0; i < n; i++) {
        cout << t[i].second + 1 << ' ';
    }
}