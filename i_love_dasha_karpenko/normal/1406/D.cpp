#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;

const ll MOD = 1e9+7;

const ll INF = 1E19+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}


ll T[DIM*4],add[DIM*4],A[DIM];
ll n;
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = A[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
}
void push(ll t){
    forn(i,2){
        T[t*2+i]+=add[t];
        add[t*2+i]+=add[t];
    }
    add[t] = 0;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (l>tr || tl>r)return;
    if (l<=tl && tr<=r){
        T[t]+=val;
        add[t]+=val;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
}
ll get(ll t,ll tl,ll tr,ll pos){
    if (tl>pos || tr<pos)return -INF;
    if (tl==tr){
        return T[t];
    }
    push(t);
    ll tm = (tl+tr)/2;
    return max(get(t*2+1,tl,tm,pos),get(t*2+2,tm+1,tr,pos));
}
ll df(ll pos){
    if (pos==1 || pos>n)return 0;
    return get(0,1,n,pos)-get(0,1,n,pos-1);
}
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>n;
    ll s = 0;
    forn(i,n){
        cin>>A[i];
        if (i>1)
        s+=max(0ll,A[i]-A[i-1]);
    }
    buildtree(0,1,n);
    ll q;
    cin>>q;
    {
         ll frs = get(0,1,n,1);
        ll st = frs-s;
        ll rr = INF;
        for(ll vl = st/2-1;vl<=st/2+1;++vl){
            rr = min(rr,max(frs-vl,vl+s) );
        }
        cout<<rr<<endl;
    }
    while(q--){
        ll l,r,x;
        cin>>l>>r>>x;
        ll dif = df(l);
        if (l!=1){
            if (dif>0)s-=dif;
            dif+=x;
            if (dif>0)s+=dif;
        }
        dif = df(r+1);
        if (r!=n){
            if (dif>0)s-=dif;
            dif-=x;
            if (dif>0)s+=dif;
        }
        update(0,1,n,l,r,x);
        ll frs = get(0,1,n,1);
        ll st = frs-s;
        ll rr = INF;
        for(ll vl = st/2-1;vl<=st/2+1;++vl){
            rr = min(rr,max(frs-vl,vl+s) );
        }
        cout<<rr<<endl;



    }
    return 0;

}