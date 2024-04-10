#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
map<int, multiset<int>> g;
vi ans;

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
    int n;
    cin >> n;
    vi b(n), c(n);
    for(int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> c[i];
        g[c[i]].insert(b[i]);
        g[b[i]].insert(c[i]);
        if(b[i] > c[i]) {
            cout << -1;
            return 0;
        }
    }
    int am1 = 0;
    int nechet = b[0];
    for(const auto& el : g) {
        if(el.second.size() % 2 == 1) {
            nechet = el.first;
            ++am1;
        }
    }
    if(am1 != 2 && am1 != 0) {
        cout << -1;
        return 0;
    }
    dfs(nechet);
    ans.push_back(nechet);
    if(ans.size() != n) {
        cout << -1;
        return 0;
    }
    for(const auto& el : ans) {
        cout << el << ' ';
    }
}