#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;
vector<ll> G[DIM];
ll chain[DIM],pos[DIM],sz[DIM],bz[DIM],child[DIM],ich[DIM],vis[DIM],len[DIM];
vector<ll> ver[DIM];
ll n,k;
vector<ll> ans;
void solve(ll root){
    ll cnt = n;
    vector<ll> decap;
    sz[chain[root]]-=len[root];
    if (sz[chain[root]]==0)decap.push_back(chain[root]);
    vis[root] = 1;

    while(!decap.empty()){
        ll cur = decap.back();
        decap.pop_back();
        cnt-=bz[cur];
        for(ll i = 1;i<=bz[cur];++i){
            ans.push_back(ver[cur][i]);
            for(ll to:G[ver[cur][i]]){
                if (vis[to]==0 && chain[to]!=cur){
                    sz[chain[to]]-=len[to];
                    vis[to] = 1;

                    if (sz[chain[to]]==0)decap.push_back(chain[to]);
                }
            }
        }
    }
    if (cnt!=0){
        cout<<0<<endl;
    }
    else{
        for(ll to:ans)cout<<to<<' ';
        cout<<endl;
    }

}
void dfs(ll v,ll par){
    len[v] = 1;
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
        if (chain[to]==chain[v]){
            if (pos[to]<pos[v]){
                cout<<0<<endl;
                exit(0);
            }
            len[v]+=len[to];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>k;
    ll root = 0;
    for(ll i = 1;i<=n;++i){
        ll x;
        cin>>x;
        if (x==0){
            root = i;
            continue;
        }
        G[x].push_back(i);
        G[i].push_back(x);
    }
    for(ll i = 1;i<=k;++i){
        ll x,y;
        cin>>x>>y;
        if (child[x] || ich[y] ){
            cout<<0<<endl;
            return 0;
        }
        ich[y] = 1;
        child[x] = y;
    }
    vector<ll> H;
    for(ll i = 1;i<=n;++i){
        if (ich[i]==0)H.push_back(i);
    }
    ll ptr = 0;
    for(ll to:H){
        ++ptr;
        ll x = to;
        ll cur = 0;
        ver[ptr].push_back(0);
        while(x!=0){
            if (chain[x]!=0){
                cout<<0<<endl;
                return 0;
            }
            chain[x] = ptr;
            pos[x] = ++cur;
            ver[ptr].push_back(x);
            ++sz[ptr];
            x = child[x];
        }
        bz[ptr] = sz[ptr];
    }
    dfs(root,root);
    solve(root);

    return 0;
}