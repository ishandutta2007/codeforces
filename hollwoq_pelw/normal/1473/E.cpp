#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 5;

struct dst {
    int u, w, add, sub;
    dst () {}
    dst (int _u, int _w, int _add, int _sub)
        : u(_u), w(_w), add(_add), sub(_sub) {
        
    }
    
    bool operator < (const dst & oth) const {
        return w > oth.w;
    }
};

vector<pair<int, int>> adj[MAXN];
int dist[MAXN][2][2], n, m;
priority_queue<dst> pq;

signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                dist[i][j][k] = 1e18;
            }
        }
    }
    pq.push({1, dist[1][0][0] = 0, 0, 0});
    
    while(!pq.empty()){
        auto [u, d, add, sub] = pq.top(); pq.pop();
        if (dist[u][add][sub] != d) continue;
        for (auto [v, w] : adj[u]){
            for (int na = 0; na <= (add ^ 1); na ++){
                for (int ns = 0; ns <= (sub ^ 1); ns ++){
                    int nadd = add | na, nsub = sub | ns;
                    if (dist[v][nadd][nsub] > d + (1 - na + ns) * w){
                        pq.push({v, dist[v][nadd][nsub] = d + (1 - na + ns) * w, nadd, nsub});
                    }
                }
            }
        }
    }
    for (int i = 2; i <= n; i++){
        cout << dist[i][1][1] << ' ';
    }
}