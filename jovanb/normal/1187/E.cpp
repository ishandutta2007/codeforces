#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll res[200005];
vector <int> graf[200005];
ll sz[200005];

ll dfs_calc(int v, int p){
    ll tr = 0;
    sz[v] = 1;
    for(auto c : graf[v]){
        if(c == p) continue;
        tr += dfs_calc(c, v);
        sz[v] += sz[c];
    }
    return tr + sz[v];
}

ll mx;

void dfs(int v, int p){
    mx = max(mx, res[v]);
    for(auto c : graf[v]){
        if(c == p) continue;
        res[c] = res[v] + sz[1] - 2*sz[c];
        dfs(c, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    res[1] = dfs_calc(1, 0);
    dfs(1, 0);
    cout << mx;
    return 0;
}