#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    vector<pair<int, int>> edges;
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n), rev(n);
    vector<int> topo(n);
    for(int i = 0; i < m; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        x--; y--;
        edges.push_back({x, y});
        if(c == 1) {
            adj[x].insert(y);
            rev[y].insert(x);
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(rev[i].size() == 0) q.push(i);
    }
    int z = 0;
    while(q.size()) {
        int x = q.front(); q.pop();
        topo[x] = z++;
        for(int g : adj[x]) {
            rev[g].erase(x);
            if(rev[g].size() == 0) q.push(g);
        }
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(rev[i].size() > 0) ok = false;
    }
    if(!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto p : edges) {
        int x, y;
        tie(x, y) = p;
        if(topo[x] > topo[y]) swap(x, y);
        cout << x+1 << ' ' << y+1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}