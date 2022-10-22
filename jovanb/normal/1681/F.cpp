#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

int last[N+5];
int pcol[N+5];
int col[N+5];

int sz[N+5];
int dole[N+5];
int gore[N+5];

vector <pair <int, int>> graf[N+5];
vector <int> gcol[N+5];

int n;

void dfs_calc(int v, int p){
    sz[v] = 1;
    pcol[v] = last[col[v]];
    gcol[pcol[v]].push_back(v);
    last[col[v]] = v;
    for(auto pr : graf[v]){
        int c = pr.first, d = pr.second;
        if(c == p) continue;
        col[c] = d;
        dfs_calc(c, v);
        sz[v] += sz[c];
    }
    dole[v] += sz[v];
    dole[pcol[v]] -= sz[v];
    last[col[v]] = pcol[v];
}

void dfs(int v){
    int h = sz[v];
    for(auto c : gcol[v]){
        h -= sz[c];
    }
    for(auto c : gcol[v]){
        gore[c] = h;
        dfs(c);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    for(int i=1; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    for(int i=1; i<=n; i++){
        last[i] = n + i;
        sz[n + i] = n;
    }
    dfs_calc(1, 0);
    for(int i=1; i<=n; i++) dfs(n + i);
    ll res = 0;
    for(int i=1; i<=n; i++){
        //cout << i << " " << gore[i] << " " << dole[i] << endl;
        res += 1LL*gore[i]*dole[i];
    }
    cout << res << "\n";
    return 0;
}