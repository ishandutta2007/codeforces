#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

set <pair <ll, int>> q;
vector <pair <int, int>> graf[300005];
ll val[300005];
int sz[300005];
int par[300005];

int root(int x){
    if(x == par[x]) return x;
    return par[x] = root(par[x]);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    ll x;
    cin >> n >> m >> x;
    ll sum = 0;
    for(int i=1; i<=n; i++){
        cin >> val[i];
        sz[i] = 1;
        par[i] = i;
        sum += val[i];
        q.insert({val[i], i});
    }
    if((n-1)*x > sum){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back({b, i});
        graf[b].push_back({a, i});
    }
    for(int turns=1; turns<=n-1; turns++){
        pair <ll, int> g = *q.rbegin();
        q.erase(*q.rbegin());
        int v = g.second;
        val[v] -= x;
        while(root(graf[v].back().first) == root(v)) graf[v].pop_back();
        int u = graf[v].back().first;
        cout << graf[v].back().second << "\n";
        u = root(u);
        q.erase({val[u], u});
        if(sz[u] > sz[v]) swap(u, v);
        while(!graf[u].empty()){
            graf[v].push_back(graf[u].back());
            graf[u].pop_back();
        }
        sz[v] += sz[u];
        val[v] += val[u];
        par[u] = v;
        q.insert({val[v], v});
    }
    return 0;
}