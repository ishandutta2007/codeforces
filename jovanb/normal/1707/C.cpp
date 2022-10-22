#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200005;

ll h[N+5];

bool moze[N+5];
vector <int> graf[N+5];
int ea[N+5], eb[N+5];

ll treba = 0;

int in[N+5], out[N+5];
int tjm;

set <pair <int, int>> q[N+5];

void dfs_calc(int v, int p){
    in[v] = ++tjm;
    for(auto c : graf[v]){
        if(c != p){
            dfs_calc(c, v);
            q[v].insert({out[c], c});
        }
    }
    out[v] = ++tjm;
}

int bal[N+5];

void dfs(int v, int p, ll th){
    th += h[v];
    if(th == treba){
        moze[v] = 1;
    }
    for(auto c : graf[v]){
        if(c == p) continue;
        dfs(c, v, th);
    }
}

bool is_parent(int a, int b){
    return in[a] <= in[b] && out[b] <= out[a];
}

int par[N+5];
int sz[N+5];
bool good[N+5];

int root(int x){ return (par[x] == x ? x : par[x] = root(par[x])); }

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        sz[i] = 1;
        par[i] = i;
    }
    for(int i=1; i<=m; i++){
        cin >> ea[i] >> eb[i];
        int a1 = root(ea[i]);
        int b1 = root(eb[i]);
        if(a1 == b1) continue;
        good[i] = 1;
        if(sz[a1] < sz[b1]) swap(a1, b1);
        sz[a1] += sz[b1];
        par[b1] = a1;
        graf[ea[i]].push_back(eb[i]);
        graf[eb[i]].push_back(ea[i]);
    }
    dfs_calc(1, 0);
    for(int i=1; i<=m; i++){
        if(good[i]) continue;
        if(is_parent(ea[i], eb[i])){
            int v = q[ea[i]].lower_bound({in[eb[i]], 0})->second;
            h[v]--;
            h[eb[i]]++;
        }
        else if(is_parent(eb[i], ea[i])){
            int v = q[eb[i]].lower_bound({in[ea[i]], 0})->second;
            h[v]--;
            h[ea[i]]++;
        }
        else{
            h[ea[i]]++;
            h[eb[i]]++;
            treba++;
        }
    }
    dfs(1, 0, 0);
    for(int i=1; i<=n; i++) cout << moze[i];
    cout << "\n";
    return 0;
}

/*
5 5
1 2
2 3
3 4
2 5
1 3
*/