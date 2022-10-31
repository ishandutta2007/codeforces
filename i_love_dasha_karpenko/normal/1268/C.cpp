#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
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
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll INF = 2E9;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll pos[DIM],D[DIM],T[DIM*4],add[DIM*4],cnt[DIM*4],vv[DIM*4],mm[DIM*4];
void push(ll t){

    T[t*2+1]+=add[t]*cnt[t*2+1];
    T[t*2+2]+=add[t]*cnt[t*2+2];
    add[t*2+1]+=add[t];
    add[t*2+2]+=add[t];
    vv[t*2+1]+=add[t];
    vv[t*2+2]+=add[t];
    mm[t*2+1]+=add[t];
    mm[t*2+2]+=add[t];
    add[t] = 0;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tl>r || l>tr)return;
    if (l<=tl && tr<=r){
        add[t]+=val;
        T[t]+=val*cnt[t];
        vv[t]+=val;
        mm[t]+=val;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
    T[t] = T[t*2+1]+T[t*2+2];
    cnt[t] = cnt[t*2+1]+cnt[t*2+2];
    vv[t] = max(vv[t*2+1],vv[t*2+2]);
    mm[t] = min(mm[t*2+1],mm[t*2+2]);
}
ll query(ll t,ll tl,ll tr,ll l,ll r){
    if(tl>r || tr>l)return 0;
    if (l<=tl && tr<=r)return T[t];
    push(t);
    ll tm = (tl+tr)/2;
    return query(t*2+1,tl,tm,l,r)+query(t*2+2,tm+1,tr,l,r);
}
void del(ll t,ll tl,ll tr,ll pos){
    if (tl>pos || tr<pos)return;
    if (tl==tr){
        T[t] = 0;
        cnt[t] = 0;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    del(t*2+1,tl,tm,pos);
    del(t*2+2,tm+1,tr,pos);
    T[t] = T[t*2+1]+T[t*2+2];
    cnt[t] = cnt[t*2+1]+cnt[t*2+2];
}
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        cnt[t] = 1;
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    cnt[t] = cnt[t*2+1]+cnt[t*2+2];
}
ll k;
ll calc(ll t,ll tl,ll tr,ll val){
    if (mm[t]>val)return k*cnt[t]-T[t];
    if (vv[t]<=val)return T[t];
    push(t);
    ll tm = (tl+tr)/2;
    return calc(t*2+1,tl,tm,val)+calc(t*2+2,tm+1,tr,val);

}
ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    ll n;
    cin>>n;
    super_set S;
    forn(i,n){
        ll x;
        cin>>x;
        A[i] = x;
        pos[x] = i;


    }
    for(ll i = n;i>=1;--i){
        D[i] = S.order_of_key(A[i]);
        S.insert(A[i]);
    }
    buildtree(0,1,n);
    ll res = 0;

    forn(i,n){
        res+=D[pos[i]];

        update(0,1,n,pos[i],n,1);
        del(0,1,n,pos[i]);

        k = i;
        ll sum = calc(0,1,n,i/2);
        cout<<res+sum<<' ';
    }

    return 0;
}
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,