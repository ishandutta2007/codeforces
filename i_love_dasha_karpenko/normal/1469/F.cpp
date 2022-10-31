#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
const ll DIM = 1E6+7;
const ll MAXH = 1E6;
const ll INF = 1E18;
ll A[DIM],T[DIM*4],add[DIM*4];
void push(ll t,ll tl,ll tr){
    ll tm = (tl+tr)/2;
    T[t*2+1]+=(tm-tl+1)*add[t];
    T[t*2+2]+=(tr-tm)*add[t];
    add[t*2+1]+=add[t];
    add[t*2+2]+=add[t];
    add[t] = 0;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll delta){
    if (l>tr || tl>r)return;
    if (l<=tl && tr<=r){
        T[t]+=delta*(tr-tl+1);
        add[t]+=delta;
        return;
    }
    push(t,tl,tr);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,delta);
    update(t*2+2,tm+1,tr,l,r,delta);
    T[t] = T[t*2+1]+T[t*2+2];
}
ll get(ll t,ll tl,ll tr,ll pos){
    if (tl>pos || tr<pos)return 0;
    if (tl==tr)return T[t];
    push(t,tl,tr);
    ll tm = (tl+tr)/2;
    return get(t*2+1,tl,tm,pos)+get(t*2+2,tm+1,tr,pos);
}
ll query(ll t,ll tl,ll tr,ll &need){
    if (T[t]<need){
        need-=T[t];
        return -1;
    }
    if (tl==tr){
        need = max(0ll,need-T[t]);
        if (need==0)return tl;
        return -1;
    }
    push(t,tl,tr);
    ll tm = (tl+tr)/2;
    ll v = query(t*2+1,tl,tm,need);
    if (need==0)return v;
    return query(t*2+2,tm+1,tr,need);
}
int main()
{
    ll n,k;
    cin>>n>>k;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
    }
    sort(A+1,A+1+n,greater<ll>());
    ll ptr = 1;
    update(0,1,MAXH,1,1,1);
    ll res = INF;
    for(ll i = 1;i<=n;++i){
        while(get(0,1,MAXH,ptr)==0)++ptr;
        ll len = (A[i]-1)/2;
        if (len>0)
        update(0,1,MAXH,ptr+2,ptr+1+len,1);
        len = A[i]-1-len;
        if (len>0)
        update(0,1,MAXH,ptr+2,ptr+1+len,1);
        update(0,1,MAXH,ptr,ptr,-1);
        ll k1 = k;
        ll ret = query(0,1,MAXH,k1);
        if (ret!=-1)res = min(res,ret);
    }
    if (res==INF)
        cout<<-1<<endl;
    else cout<<res-1<<endl;

    return 0;
}