//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 5E5+7;
ll ptr = 0,comp[DIM],C[DIM],vis[2][DIM],CP[DIM],def[DIM],paint[DIM];
vector<ll> in_col[DIM],G[DIM];
vector<pair<ll,ll> > R[2][DIM];
void dfs(ll v){
    comp[v] = ptr;
    for(ll to:G[v]){
        if (C[to]!=C[v])continue;
        if (comp[to]!=0 && paint[to]!=(paint[v]^1)){
            def[C[to]] = 1;
        }
        if (comp[to]==0){
            paint[to] = paint[v]^1;
            dfs(to);
        }
    }
}
struct node{
    ll a,b,ind;
};
ll flag = 0;
void solve(ll v,ll ind){

    for(auto to:R[ind][v]){
        if (vis[to.second][to.first]!=0){
            if (vis[to.second][to.first]+vis[ind][v]!=3){
                flag = 1;
            }
            continue;
        }
        vis[to.second][to.first] = 3-vis[ind][v];
        solve(to.first,to.second);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    for(ll i = 1;i<=n;++i){
        cin>>C[i];
        in_col[C[i]].push_back(i);
    }
    for(ll i = 1;i<=m;++i){
        ll u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(ll i = 1;i<=n;++i){
        if (comp[i]==0){
            ++ptr;
            dfs(i);
            CP[ptr] = C[i];
        }
    }
    ll base = k;
    for(ll i = 1;i<=k;++i){
        if (def[i])--base;
    }

    ll res = 0;
    for(ll col = 1;col<=k;++col){
        if (def[col])continue;
        ll cnt = base-1;
        map<ll,vector<node> > M;
        for(ll v:in_col[col]){
            for(ll to:G[v]){
                if (comp[to]==comp[v])continue;
                if (!def[CP[comp[to]]])
                    M[CP[comp[to]]].push_back({comp[v],comp[to],1^paint[v]^paint[to]});
            }
        }
        for(auto vec:M){
            set<ll> upd,upd1;
            for(node edg:vec.second){
                R[0][edg.a].push_back({edg.b,edg.ind});
                R[1][edg.a].push_back({edg.b,edg.ind^1});
                R[0][edg.b].push_back({edg.a,edg.ind});
                R[1][edg.b].push_back({edg.a,edg.ind^1});
                upd.insert(edg.a);
                upd1.insert(edg.b);
            }
            for(ll to:upd){
                if (vis[0][to]==0){
                    vis[0][to] = 1;
                    solve(to,0);
                    if (flag){
                        flag = 0;
                        --cnt;
                        break;
                    }
                }
            }
            for(ll to:upd){
                vis[0][to] = vis[1][to] = 0;
                R[0][to].clear();
                R[1][to].clear();
                R[0][to].push_back({to,1});
                R[1][to].push_back({to,0});
            }
            for(ll to:upd1){
                vis[0][to] = vis[1][to] = 0;
                R[0][to].clear();
                R[1][to].clear();
                R[0][to].push_back({to,1});
                R[1][to].push_back({to,0});
            }
        }
        res+=cnt;

    }
    cout<<res/2<<endl;

    return 0;
}