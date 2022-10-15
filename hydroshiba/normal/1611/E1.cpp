#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5 + 6;
const int maxl = 19;

struct graph{
    vector<int> depth;
    vector<vector<int>> par, g;
    vector<int> leaves;

    graph(int n){
        depth.resize(n + 1);
        par.resize(n + 1);
        g.resize(n + 1);

        for(vector<int> &i : par) i.resize(maxl);
    }

    void add(int u, int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void root(int u = 1, int p = 0){
        par[u][0] = p;
        depth[u] = depth[p] + 1;
        for(int v : g[u]) if(v != p) root(v, u);

        if(g[u].size() == 1 && p != 0) leaves.push_back(u);
    }

    void build(){
        for(int i = 1; i < maxl; ++i){
            for(int j = 1; j < g.size(); ++j) par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }

    int kthPar(int u, int k){
        int res = u;
        for(int i = maxl - 1; i >= 0; --i){
            if((k >> i) & 1) res = par[res][i];
        }
        return res;
    }

    int lca(int u, int v){
        int d = min(depth[u], depth[v]);
        u = kthPar(u, depth[u] - d);
        v = kthPar(v, depth[v] - d);

        if(u == v) return u;

        for(int i = maxl - 1; i >= 0; --i){
            while(par[u][i] != par[v][i]){
                u = par[u][i];
                v = par[v][i];
            }
        }

        return par[u][0];
    }

    int dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

void solve(){
    int n, k;
    cin >> n >> k;

    set<int> enemies;
    for(int i = 0; i < k; ++i){
        int val;
        cin >> val;
        enemies.insert(val);
    }

    graph myGraph(n);
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        myGraph.add(u, v);
    }

    myGraph.root();
    myGraph.build();

    if(n == 1){
        cout << "NO\n";
        return;
    }

    if(enemies.empty()){
        cout << "YES\n";
        return;
    }

    for(int u : myGraph.leaves) if(enemies.find(u) == enemies.end()){
        bool flag = true;
        for(int v : enemies) if(myGraph.dist(1, u) >= myGraph.dist(v, u)){
            flag = false;
            break;
        }

        if(flag){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}