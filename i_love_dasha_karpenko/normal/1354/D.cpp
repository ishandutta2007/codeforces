#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E6+14;
const ll INF = 1E17;

ll T[DIM*4];
ll query(ll t,ll tl,ll tr,ll pos,ll beh = 0){
    if (beh>=pos)return 0;
    if (T[t]+beh<pos)return 0;
    if (tl==tr)return tl;
    ll tm = (tl+tr)/2;
    return max(query(t*2+1,tl,tm,pos,beh),query(t*2+2,tm+1,tr,pos,T[t*2+1]+beh));
}
void update(ll t,ll tl,ll tr,ll pos,ll val){
    if (tl>pos || tr<pos)return;
    if (tl==tr){
        T[t]+=val;
        return;
    }
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,pos,val);
    update(t*2+2,tm+1,tr,pos,val);
    T[t] = T[t*2+1]+T[t*2+2];
}
void del(ll t,ll tl,ll tr,ll pos,ll beh = 0){
    if (beh>=pos)return ;
    if (T[t]+beh<pos)return;
    if (tl==tr){
        T[t]--;
        return;
    }
    ll tm = (tl+tr)/2;
    del(t*2+2,tm+1,tr,pos,T[t*2+1]+beh);
    del(t*2+1,tl,tm,pos,beh);

    T[t] = T[t*2+1]+T[t*2+2];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,q;
    cin>>n>>q;
    forn(i,n){
        ll x;
        cin>>x;
        update(0,1,n,x,1);
    }
    forn(i,q){
        ll x;
        cin>>x;
        if (x>0){
            update(0,1,n,x,1);
            continue;
        }
        x*=-1;
        del(0,1,n,x);

    }
    if (T[0]==0)cout<<"0\n";
    else
    cout<<query(0,1,n,1)<<endl;;
    return 0;
}