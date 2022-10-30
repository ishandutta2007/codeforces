#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 3E5+7;
const ll INF = 1E8;
const ll MAXN = 50;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll tim[DIM],add[DIM*4],A[DIM];
pp T[DIM*4];
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = {INF,tl};;
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = {INF,tl};
}
void push(ll t){
    T[t*2+1].fi+=add[t];
    T[t*2+2].fi+=add[t];
    add[t*2+1]+=add[t];
    add[t*2+2]+=add[t];
    add[t] = 0;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tl>r ||l>tr)return;
    if (l<=tl && tr<=r){
        T[t].fi+=val;
        add[t]+=val;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
    T[t] = min(T[t*2+1],T[t*2+2]);

}
void put(ll t,ll tl,ll tr,ll pos,ll val){
    if (tl>pos || pos>tr)return;
    if (tl==tr){
        T[t]={val,tl};
        add[t] = 0;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    put(t*2+1,tl,tm,pos,val);
    put(t*2+2,tm+1,tr,pos,val);
    T[t] = min(T[t*2+1],T[t*2+2]);
}
pp get(ll t,ll tl,ll tr,ll l,ll r){
    if (l>tr || tl>r)return {INF,0};
    if (l<=tl && tr<=r)return T[t];
    push(t);
    ll tm = (tl+tr)/2;
    return min(get(t*2+1,tl,tm,l,r),get(t*2+2,tm+1,tr,l,r));
}
vector<ll> TT[DIM*4];
void bt(ll t,ll tl,ll tr){
    if (tl==tr){
        TT[t].pb(tim[tl]);
        return;
    }
    ll tm = (tl+tr)/2;
    bt(t*2+1,tl,tm);
    bt(t*2+2,tm+1,tr);
    merge(TT[t*2+1].begin(),TT[t*2+1].end(),TT[t*2+2].begin(),TT[t*2+2].end(),back_inserter(TT[t]));
}
ll cnt(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if(tl>r || l>tr)return 0;
    if (l<=tl && tr<=r){
        ll pos = lower_bound(TT[t].begin(),TT[t].end(),val)-TT[t].begin();
        return ll(TT[t].size())-pos;
    }
    ll tm = (tl+tr)/2;
    return cnt(t*2+1,tl,tm,l,r,val)+cnt(t*2+2,tm+1,tr,l,r,val);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,q;
    cin>>n>>q;
    forn(i,n)cin>>A[i];
    buildtree(0,1,n);
    priority_queue<ll> Q;
    for(ll i = n;i>=1;--i){
        if (A[i]==i){
            update(0,1,n,i,n,-1);
            tim[i] = i;
        }
        else if (A[i]<i){
            put(0,1,n,i,i-A[i]);
        }
        while(1){
            pp val = get(0,1,n,i,n);

            if (val.fi>0)break;
            tim[val.sc] = i;
            put(0,1,n,val.sc,INF);
            update(0,1,n,val.sc,n,-1);
        }
    }

    bt(0,1,n);
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll l = x+1,r = n-y;
        if (l>r){
            cout<<0<<endl;
        }
        else
        cout<<cnt(0,1,n,l,r,l)<<endl;
    }



    return 0;
}