//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E5+7;
int pr[N];
int F(int x){
    return x==pr[x]?x:pr[x] = F(pr[x]);
}
int unite(int a,int b){
    a = F(a);
    b = F(b);
    if (a==b)
        return 0;
    pr[a] = b;
    return 1;
}
vector<pair<int,int> > G[N];
const int LOG = 21;
ll dist[N],P[N][LOG],timer = 0,tin[N],tout[N];
void dfs(int v,int par){
    P[v][0] = par;
    tin[v] = ++timer;
    for(int i = 1;i<LOG;++i)
        P[v][i] = P[P[v][i-1]][i-1];
    for(auto [to,d]:G[v]){
        if (to==par)
            continue;
        dist[to] = dist[v]+d;
        dfs(to,v);
    }
    tout[v] = timer;
}
bool is_par(int a,int b){
    return tin[a]<=tin[b] && tout[b]<=tout[a];
}
int lca(int a,int b){
    if (is_par(a,b))
        return a;
    if (is_par(b,a))
        return b;
    for(int i = LOG-1;i>=0;--i)
        if (!is_par(P[a][i],b))
            a = P[a][i];
    return P[a][0];
}
ll D(int a,int b){
    return dist[a]+dist[b]-2*dist[lca(a,b)];
}
int pos[N];
int in_pos[N];
const int DIF = 45;
const ll INF = 1E18;
ll MD[DIF][DIF],ND[2][DIF];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        pr[i] = i;
    vector<tuple<int,int,int>> edges;
    for(int i = 1;i<=m;++i){
        int u,v,d;
        cin>>u>>v>>d;
        if (!unite(u,v)){
            edges.push_back({u,v,d});
        }
        else{
            G[u].push_back({v,d});
            G[v].push_back({u,d});
        }
    }
    dfs(1,1);
    int ptr = 0;
    for(auto [u,v,d]:edges){
        if (!pos[u]){
            pos[u] = ++ptr;
            in_pos[ptr] = u;
        }
        if (!pos[v]){
            pos[v] = ++ptr;
            in_pos[ptr] = v;
        }
    }
    for(int i = 1;i<=ptr;++i)
        for(int j = i;j<=ptr;++j)
            MD[i][j] = MD[j][i] = D(in_pos[i],in_pos[j]);
    for(auto [u,v,d]:edges){
        MD[pos[u]][pos[v]] = MD[pos[v]][pos[u]] = min(MD[pos[u]][pos[v]],ll(d));
    }
    for(int k = 1;k<=ptr;++k)
        for(int i = 1;i<=ptr;++i)
            for(int j = 1;j<=ptr;++j)
                MD[i][j] = min(MD[i][j],MD[i][k]+MD[k][j]);
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        for(int i = 1;i<=ptr;++i){
            ND[0][i] = D(u,in_pos[i]);
            ND[1][i] = D(v,in_pos[i]);
        }
        ll res = D(u,v);
        for(int i = 1;i<=ptr;++i){
            for(int j = 1;j<=ptr;++j){
                res = min(res,ND[0][i]+MD[i][j]+ND[1][j]);
            }
        }
        cout<<res<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}