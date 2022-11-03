#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<vector<int>> edges;
vector<int> v;
vector<int> val;
vector<vector<int>> g;

bool dfs(int w){
    for(auto e: g[w]){
        int u = edges[e][0] ^ edges[e][1] ^ w;
        if(val[u] == -1){
            val[u] = val[w] ^ v[e];
            if(!dfs(u)){
                return false;
            }
        }else if(val[u] != (val[w] ^ v[e])){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int m, n, k, x;
    cin >> m >> n;
    edges.resize(m);
    v.resize(m);
    g.resize(n);
    for(int i = 0; i < m; ++i){
        cin >> v[i];
        v[i] ^= 1;
    }
    for(int i = 0; i < n; ++i){
        cin >> k;
        g[i].resize(k);
        for(int j = 0; j < k; ++j){
            cin >> g[i][j];
            --g[i][j];
            edges[g[i][j]].push_back(i);
        }
    }
    val.resize(n, -1);
    for(int i = 0; i < n; ++i){
        if(val[i] == -1){
            val[i] = 0;
            if(!dfs(i)){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}