#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E5+7;
const ll INF = 1e18;


vector<ll> G[DIM];
ll res = 0;
ll test = 0;
ll dfs(ll v,ll par){
    ll flag = 0;
    ll r = 0;
    for(ll to:G[v]){
        if (to==par)continue;
        flag = 1;
        if (dfs(to,v)==1)r++;
        else res++;
    }
    if (r>0)res++;
    if (flag==0)return 1;
    return 0;
}
ll Check(ll v,ll par){
    ll st = -1;
    ll ret;
    for(ll to:G[v]){
        if (to==par)continue;
        ret = Check(to,v);
        ret^=1;
        if (st==-1)st = ret;
        if (st!=ret)test = 1;
    }
    if (st==-1)ret = 0;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    ll root = 0;
    forn(i,n){
        if (G[i].size()>=2)root = i;
    }
    dfs(root,root);
    Check(root,root);
    if (test==0)cout<<1<<' ';
    else cout<<3<<' ';
    cout<<res<<endl;
    return 0;
}