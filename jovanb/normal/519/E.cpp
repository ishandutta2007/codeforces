#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int sz[100005];
int in[100005];
int out[100005];
vector <int> graf[100005];
int par[100005][20];
int depth[100005];
int cnt;

void dfs(int v, int pr){
    in[v] = ++cnt;
    sz[v] = 1;
    depth[v] = depth[pr]+1;
    par[v][0] = pr;
    for(int i=1; i<=18; i++){
        par[v][i] = par[par[v][i-1]][i-1];
    }
    for(auto c : graf[v]){
        if(c == pr) continue;
        dfs(c, v);
        sz[v] += sz[c];
    }
    out[v] = cnt;
}

bool parent(int a, int b){
    return in[a] <= in[b] && out[b] <= out[a];
}

int lca(int a, int b){
    if(parent(a, b)) return a;
    if(parent(b, a)) return b;
    for(int i=18; i>=0; i--){
        if(!parent(par[a][i], b) && par[a][i] > 0) a = par[a][i];
    }
    //cout << a << endl;
    return par[a][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1, 0);
    int m;
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        if(a == b){cout << n << "\n"; continue;}
        if(depth[a] < depth[b]) swap(a, b);
        int x = lca(a, b);
        //cout << "je lca " << x << endl;
        int dis = depth[a]+depth[b]-2*depth[x];
        if(dis%2){cout << "0\n"; continue;}
        int treba = (depth[a]+2*depth[x]-depth[b])/2;
        int v = a;
        for(int i=18; i>=0; i--){
            if(depth[v]-(1<<i) >= treba) v = par[v][i];
        }
        int res = sz[v];
        //cout << sz[v] << " " << v << endl;
        for(int i=18; i>=0; i--){
            if(depth[a]-(1<<i) > treba)  a = par[a][i];
        }
        res -= sz[a];
        if(v == x){
            for(int i=18; i>=0; i--){
                if(depth[b]-(1<<i) > treba) b = par[b][i];
            }
            res -= sz[b];
            res += n-sz[v];
        }
        cout << res << "\n";
    }
    return 0;
}