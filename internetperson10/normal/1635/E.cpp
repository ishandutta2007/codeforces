#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> ij;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> adj2;
vector<int> indeg;

bool dfs(int x, int par = -1) {
    if(par == -1) ij[x] = 0;
    for(auto p : adj[x]) {
        if(p.first == par) continue;
        if(ij[p.first] == -1) {
            ij[p.first] = 1 - ij[x];
            dfs(p.first, x);
        }
        else if(ij[x] == ij[p.first]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    adj2.resize(n);
    indeg.resize(n);
    ij.resize(n, -1);
    for(int i = 0; i < m; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        x--; y--;
        adj[x].push_back({y, t-1});
        adj[y].push_back({x, t-1});
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(ij[i] == -1) ok &= dfs(i);
    }
    if(!ok) {
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(auto p : adj[i]) {
            if(p.second == ij[i]) {
                adj2[i].push_back(p.first);
                indeg[p.first]++;
            }
        }
    }
    vector<int> ord(n, -1);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) q.push(i);
    }
    int ind = 1;
    while(q.size()) {
        int x = q.front(); q.pop();
        ord[x] = ind++;
        for(int g : adj2[x]) {
            indeg[g]--;
            if(!indeg[g]) q.push(g);
        }
    }
    for(int i = 0; i < n; i++) if(ord[i] == -1) ok = false;
    if(!ok) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            cout << (ij[i] ? "R" : "L") << ' ' << ord[i] << '\n';
        }
    }
}