#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;
const int LOG = 20;

vector <int> graf[N+5];
int par[N+5][LOG+1];
int depth[N+5];
int in[N+5], out[N+5];
int tjm;

vector <int> vec[N+5];

void dfs(int v, int p, int d){
    in[v] = ++tjm;
    par[v][0] = p;
    depth[v] = d;
    vec[depth[v]].push_back(v);
    for(int j=1; j<=LOG; j++) par[v][j] = par[par[v][j-1]][j-1];
    for(auto c : graf[v]) if(c != p) dfs(c, v, d + 1);
    out[v] = tjm;
}

bool is_parent(int a, int b){
    return a == 0 || (in[a] <= in[b] && out[b] <= out[a]);
}

int lca(int a, int b){
    if(is_parent(a, b)) return a;
    for(int j=LOG; j>=0; j--) if(!is_parent(par[a][j], b)) a = par[a][j];
    return par[a][0];
}

int dist(int a, int b){
    return depth[a] + depth[b] - 2*depth[lca(a, b)];
}

int mxl[N+5];

void solve(){
    int n;
    cin >> n;
    for(int i=0; i<=n; i++) graf[i].clear(), vec[i].clear();
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    tjm = 0;
    dfs(1, 0, 0);
    int d1 = 0, d2 = 0;
    for(int sme=n-1; sme>=1; sme--){
        for(auto c : vec[sme+1]){
            if(d1 == 0) d1 = d2 = c;
            else{
                int mx = max(dist(d1, c), max(dist(d1, d2), dist(d2, c)));
                if(dist(d1, c) == mx) d2 = c;
                else if(dist(d2, c) == mx) d1 = c;
            }
        }
        int dm = (dist(d1, d2) + 1)/2;
        mxl[sme] = sme - dm;
        if(d1 == 0) mxl[sme] = n;
    }
    mxl[n] = n;
    int j = 1;
    for(int i=1; i<=n; i++){
        while(mxl[j] < i) j++;
        cout << j << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}