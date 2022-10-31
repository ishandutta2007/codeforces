#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
//template<typename TN>
//typedef tree<TN,null_type,less<TN>,rb_tree_tag,tree_order_statistics_node_update> super_set<TN>;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 5000 +7;
const ll INF = 10E17;
const ll MAXN = 10E5;
struct node{
    ll a,b,c;
};
node A[DIM];
vector<pp> G[DIM];
ll val[DIM];
ll dfs(ll v,ll par,ll need,ll va){
    if (v==need)return 1;
    for(pp to:G[v]){
        if (to.fi==par)continue;
        ll ret = dfs(to.fi,v,need,va);
        if (ret==1){
            val[to.sc] = max(val[to.sc],va);
            return 1;
        }
    }
    return 0;
}
pp check(ll v,ll par,ll need){
    if (v==need)return {INF,1};
    for(pp to:G[v]){
        if (to.fi==par)continue;
        pp ret = check(to.fi,v,need);
        if (ret.sc==1){
            ret.fi = min(ret.fi,val[to.sc]);
            return ret;
        }
    }
    return {INF,0};
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb({y,i});
        G[y].pb({x,i});
    }
    ll m;
    cin>>m;
    forn(i,m){
        ll a,b,g;
        cin>>a>>b>>g;
        dfs(a,-1,b,g);
        A[i] = {a,b,g};
    }
    forn(i,n-1){
        if (val[i]==0)val[i] = MAXN;
    }
    forn(i,m){
        pp t = check(A[i].a,-1,A[i].b);
        if (t.fi!=A[i].c){
            cout<<-1<<endl;
            return 0;
        }
    }
    forn(i,n-1)cout<<val[i]<<' ';
    cout<<endl;
    return 0;
}