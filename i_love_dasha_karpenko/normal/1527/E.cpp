//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef int ll;
#define endl '\n'
const ll DIM = 35E3+7;
const ll INF = 1E9;

struct tree{
    ll T[DIM*4],mod[DIM*4];
    void push(ll t){
        for(ll nt = t*2+1;nt<=t*2+2;++nt){
            T[nt]+=mod[t];
            mod[nt]+=mod[t];
        }
        mod[t] = 0;
    }
    void update(ll t,ll tl,ll tr,ll l,ll r,ll val){
        if (tl>r || l>tr)
            return;
        if (l<=tl && tr<=r){
            T[t]+=val;
            mod[t]+=val;
            return;
        }
        push(t);
        ll tm = (tl+tr)/2;
        update(t*2+1,tl,tm,l,r,val);
        update(t*2+2,tm+1,tr,l,r,val);
        T[t] = min(T[t*2+1],T[t*2+2]);
    }
    void put(ll t,ll tl,ll tr,ll pos,ll val){
        if (pos<tl || pos>tr)
            return;
        if (tl==tr){
            T[t] = min(T[t],val);
            return;
        }
        push(t);
        ll tm = (tl+tr)/2;
        put(t*2+1,tl,tm,pos,val);
        put(t*2+2,tm+1,tr,pos,val);
        T[t] = min(T[t*2+1],T[t*2+2]);
    }
    ll val(){
        return T[0];
    }
    void init(ll n){
        for(ll i = 0;i<=n*4+1;++i){
            T[i] = INF;
        }
    }
};
const ll K = 107;
tree T[K];
ll A[DIM],near[DIM],last[DIM],S[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    --k;
    for(ll i = 1;i<=n;++i)
        cin>>A[i];
    for(ll i = 0;i<=k;++i)
        T[i].init(n);
    T[0].put(0,0,n,0,0);
    //map<ll,ll> last;
    for(ll i = 1;i<=n;++i){
        if (last[A[i]]==0)
            last[A[i]] = i;
        near[i] = last[A[i]];
        S[last[A[i]]+1]+=i-last[A[i]];
        last[A[i]] = i;
    }
    ll cur = 0,sum = 0;
    for(ll i = 1;i<=n;++i){
        cur+=S[i];
        sum+=S[i];
        for(ll j = 0;j<=k;++j){
            T[j].put(0,0,n,i,T[j].val()+cur);
        }
        for(ll j = k;j>0;--j){
            T[j].put(0,0,n,i,T[j-1].val());
        }
        for(ll j = 0;j<=k;++j){
            if (near[i]<i)
            T[j].update(0,0,n,near[i]+1,i,near[i]-i);
        }
        cur-=i-near[i];
    }
    ll res = 0;
    for(ll j = 0;j<=k;++j)
        res = min(res,T[j].val());
    cout<<sum+res<<endl;
    return 0;
}