#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int res[300005];
vector <int> graf[300005];
int sz[300005];
int par[300005];

void dfs(int v){
    int mx = 0;
    sz[v] = 1;
    for(auto c : graf[v]){
        dfs(c);
        if(sz[c] >= sz[mx]) mx = c;
        sz[v] += sz[c];
    }
    if(graf[v].empty()){
        res[v] = v;
        return;
    }
    res[v] = res[mx];
    while(sz[res[v]] <= sz[v]/2) res[v] = par[res[v]];
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, q;
    cin >> n >> q;
    for(int i=2; i<=n; i++){
        cin >> par[i];
        graf[par[i]].push_back(i);
    }
    dfs(1);
    while(q--){
        int x;
        cin >> x;
        cout << res[x] << "\n";
    }
    return 0;
}