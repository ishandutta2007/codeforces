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
const ll DIM = 1000+7;
const ll INF = 1e18;

ll ask(ll type,ll a,ll b,ll c){
    cout<<type<<' '<<a<<' '<<b<<' '<<c<<endl;
    cout.flush();
    ll ret;
    cin>>ret;
    return ret;
}
pp H[DIM];
ll S[DIM],side[DIM],vis[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 3;i<=n;++i){
        H[i].fi = ask(1,1,2,i)*ask(2,1,2,i)*(-1);
        H[i].sc = i;

    }

    H[1].sc = 1;
    H[2].sc = 2;
    sort(H+1,H+1+n);
    ll ptr = 0;
    vis[1] = vis[n]  = 1;
    for(ll i = 2;i<n;++i){
        if (ask(2,H[1].sc,H[n].sc,H[i].sc)==-1)vis[i] = 1;
    }
    forn(i,n){
        if(vis[i]==1)S[++ptr] = H[i].sc;
    }
    for(ll i = n-1;i>1;--i){

        if (vis[i]==0)S[++ptr] = H[i].sc;
    }

    ll st = 0;
    forn(i,n){
        if (S[i]==1){
            st = i;
            break;
        }
    }
    cout<<"0 ";
    for(ll i = st;i<=n;i++)cout<<S[i]<<' ';
    forn(i,st-1)cout<<S[i]<<' ';
    cout<<endl;

    return 0;
}