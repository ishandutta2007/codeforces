#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 2E5+7;
const long long INF = 1E9+7;
ll A[DIM],upd[DIM*4];
pair<ll,ll> T[DIM*4];
void push(ll t,ll tl,ll tr){
    if (upd[t]==0)return;
    ll tm = (tl+tr)/2;

    T[t*2+1].first = min(INF,(long long)(tm+1-tl)*(long long)upd[t]);
    T[t*2+2].first = min(INF,(long long)(tr-tm)*(long long)upd[t]);
    if (T[t*2+1].second>upd[t] || T[t*2+2].second>upd[t])t/=0;
    T[t*2+1].second = T[t*2+2].second = upd[t];
    upd[t*2+1] = upd[t*2+2] = upd[t];
    upd[t] = 0;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tl>r || l>tr)return;
    if (l<=tl && tr<=r){
        long long vv = (long long)(tr-tl+1)*(long long)val;
        vv = min(vv,INF);
        T[t].first = vv;
        if (T[t].second>val)t/=0;
        T[t].second = val;
        upd[t] = max(upd[t],val);
        return;
    }
    push(t,tl,tr);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
    T[t].first=  min(int(INF),T[t*2+1].first+T[t*2+2].first);
    T[t].second = min(T[t*2+1].second,T[t*2+2].second);
}
ll get(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tl>r || l>tr)return 0;
    if (T[t].second>val)return 0;
    if (tl==tr)return tl;

    push(t,tl,tr);
    ll tm = (tl+tr)/2;
    ll pos = get(t*2+1,tl,tm,l,r,val);
    if (pos!=0)return pos;
    return get(t*2+2,tm+1,tr,l,r,val);
}
ll solve(ll t,ll tl,ll tr,ll l,ll r,ll &sum){
    if (tl>r || l>tr)return -1;
    if (T[t].second>sum)return 0;
    if (l<=tl && tr<=r && sum>=T[t].first){
        sum-=T[t].first;
        return tr;
    }
    push(t,tl,tr);
    ll tm = (tl+tr)/2;
    ll pos = solve(t*2+1,tl,tm,l,r,sum);
    if (pos!=-1 && pos!=tm)return pos;
    ll p1 = solve(t*2+2,tm+1,tr,l,r,sum);
    return max(pos,p1);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,q;
    cin>>n>>q;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
    }
    for(ll i = 1;i<=n;++i){
        update(0,1,n,i,i,A[i]);
    }
    while(q--){
        ll t,x,y;
        cin>>t>>x>>y;

        if (t==1){
            ll pos = get(0,1,n,1,n,y);
            if (pos<=x && pos!=0)update(0,1,n,pos,x,y);
        }
        else{
            ll cur = x;
            ll sum = y;
            ll res = 0;
            ll cnt = 0;
            while(cur<=n){
                ll pos = get(0,1,n,cur,n,sum);
                if (pos==0)break;
                ll p1 = solve(0,1,n,pos,n,sum);

                res+=(p1-pos+1);
                cur = p1+1;
                ++cnt;
                if (cnt>60)n/=0;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}