#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;
vector<map<int, int>> adj2;
vector<bool> taken;
vector<int> best, ct;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    taken.resize(n, false);
    best.resize(n, 999999);
    ct.resize(n, 0);
    adj.resize(n);
    adj2.resize(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(x == n) continue;
        x--; y--;
        adj[x].push_back(y);
        adj2[y][x]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> bfs;
    bfs.push({0, n-1});
    while(bfs.size()) {
        pair<int, int> g = bfs.top();
        bfs.pop();
        int x, d;
        tie(d, x) = g;
        if(taken[x]) continue;
        best[x] = d;
        taken[x] = true;
        for(auto p : adj2[x]) {
            int ne = p.first, co = p.second;
            ct[ne] += co;
            bfs.push({d + 1 + adj[ne].size() - ct[ne], ne});
        }
    }
    cout << best[0] << '\n';
}