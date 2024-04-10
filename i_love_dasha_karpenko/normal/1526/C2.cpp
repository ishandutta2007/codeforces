//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 200000+7;
pair<ll,ll> A[DIM];
ll T[DIM*4],mod[DIM*4];
void push(ll t){
    for(ll nt = t*2+1;nt<=t*2+2;++nt){
        mod[nt]+=mod[t];
        T[nt]+=mod[t];
    }
    mod[t] = 0;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tl>r || l>tr)
        return;
    if (l<=tl && tr<=r){
        mod[t]+=val;
        T[t]+=val;
        return;
    }
    push(t);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
    T[t] = min(T[t*2+1],T[t*2+2]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)
        cin>>A[i].first,A[i].second = i;
    sort(A+1,A+1+n,greater<pair<ll,ll> >());
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        update(0,1,n,A[i].second,n,A[i].first);
        if (T[0]<0){
            update(0,1,n,A[i].second,n,-A[i].first);
        }
        else
            ++res;
    }
    cout<<res<<endl;
    return 0;
}