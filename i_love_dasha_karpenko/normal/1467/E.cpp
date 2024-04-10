#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
ll A[DIM],sz[DIM],tin[DIM],tout[DIM],timer = 0,sum[DIM];
vector<ll> G[DIM];
ll n;
vector<ll> segms[DIM];
void dfs(ll v,ll par){
    sz[v] = 1;
    tin[v] = ++timer;

    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
    tout[v] = timer;
}
void solve(ll v,ll par,map<ll,ll> &S){
    ll big = 0;
    ll cnt = 0,unp;
    for(ll to:G[v]){
        if (to==par)continue;
        if (sz[to]>sz[big])big = to;
    }
    if (big!=0){
        solve(big,v,S);
        if (S.count(A[v])==1){
            ++cnt;
            unp = big;
        }
    }
    for(ll to:G[v]){
        if (to==par || to==big)continue;
        map<ll,ll> ss;
        solve(to,v,ss);
        if (ss.count(A[v])==1){
            ++cnt;
            unp = to;
        }
        for(auto to:ss)S[to.first]+=to.second;;
    }
    if (cnt>1){
        cout<<0<<endl;
        exit(0);
    }
    if (cnt==1){
        segms[1].push_back(tin[v]);
        segms[tout[v]+1].push_back(n);
        for(ll to:G[v]){
            if (to==par || to==unp)continue;
            segms[tin[to]].push_back(tout[to]);
        }
    }
    S[A[v]]++;
    if (sum[A[v]]-S[A[v]]){
        segms[tin[v]].push_back(tout[v]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>n;
    map<ll,ll> renum;
    ll ptr = 0;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        if (renum.count(A[i])==0)renum[A[i]] = ++ptr;
        A[i] = renum[A[i]];
        sum[A[i]]++;
    }
    for(ll i = 1;i<n;++i){
        ll u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    map<ll,ll> dum;
    solve(1,1,dum);
    ll last = 0;
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        for(ll to:segms[i])last = max(last,to);
        if (i>last)++res;
    }
    cout<<res<<endl;
    return 0;
}