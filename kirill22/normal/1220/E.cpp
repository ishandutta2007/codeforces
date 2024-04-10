#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<unordered_set<int>> g(200100);

signed main() {
    int n,m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    int s;
    cin >> s;
    s--;
    int ans = 0;
    set<pair<int, int>> a;
    vector<int> cost(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == s) {
            a.insert({1000000, i});
            continue;
        }
        int x = g[i].size();
        a.insert({x, i});
    }
    while (a.size() > 0) {
        pair<int, int> x = *a.begin();
        if (x.first > 1) {
            break;
        }
        a.erase(a.begin());
        int y = *g[x.second].begin();
        cost[y] = max(cost[y], cost[x.second] + c[x.second]);
        if (y != s) {
            a.erase({g[y].size(), y});
            a.insert({g[y].size() - 1, y});
        }
        g[y].erase(x.second);
    }
    int tmp = 0;
    for (auto c2 : a) {
        ans += c[c2.second];
        tmp = max(tmp, cost[c2.second]);
    }
    cout << ans + tmp;
}