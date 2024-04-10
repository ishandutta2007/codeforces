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
const ll DIM = 2E5+7;
const ll INF = 1e9;

ll p[DIM],c[DIM],vis[DIM];
ll tr(ll i,vector<ll> &V){
    vector<ll> vv;
    vv.resize(V.size());
    for(ll pos = 0;pos+i<V.size();pos++){
        if (vv[pos]==-1 || c[V[pos]]!=c[V[pos+i]] ){
            vv[pos] = -1;
            vv[pos+i] = -1;
        }
    }
    for(ll pos = V.size()-i;pos<V.size();pos++)if (vv[pos]!=-1)return i;
    return INF;
}
ll solve(vector<ll> &V,ll depth){
    ll col =  c[V[0]];
    ll flag = 0;
    for(ll to:V){
        if (c[to]!=col){
            flag = 1;
            break;
        }
    }
    if (flag==0)return depth;
    ll div = 0;
    ll sq = sqrt(V.size());
    ll r = INF;
    for(ll i = 2;i<=sq;i++){
        if (V.size()%i==0){
            r = min(r,tr(i,V)+depth-1);
            r = min(r,tr(V.size()/i,V)+depth-1);
        }
    }
    r = min(r,V.size()-1+depth);
    return r;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        forn(i,n)cin>>p[i];
        forn(i,n)cin>>c[i];
        ll res = INF;
        forn(i,n){
            if (vis[i]==1)continue;
            vis[i] = 1;
            vector<ll> cyc;
            cyc.pb(i);
            ll x = p[i];
            while(x!=i){
                vis[x] = 1;
                cyc.pb(x);
                x = p[x];
            }
            res = min(res,solve(cyc,1));
        }
        cout<<res<<endl;
        forn(i,n)vis[i] = 0;
    }
    return 0;
}