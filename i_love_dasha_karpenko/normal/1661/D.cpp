#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
const int N = 3e5+7;
ll T[N*2],mod[N*2];
ll A[N];
void inc(int t,ll val,ll len){
    T[t]+=len*val;
    mod[t]+=val;
}
void push(int t,int tl,int tr){
    int tm = (tl+tr)/2;
    inc(t+1,mod[t],tm-tl+1);
    inc(t+(tm-tl+1)*2,mod[t],tr-tm);
    mod[t] = 0;
}
void update(int t,int tl,int tr,int l,int r,ll val){
    if (tl>r || l>tr)
        return;
    if (l<=tl && tr<=r){
        inc(t,val,tr-tl+1);
        return;
    }
    push(t,tl,tr);
    int tm = (tl+tr)/2;
    update(t+1,tl,tm,l,r,val);
    update(t+(tm-tl+1)*2,tm+1,tr,l,r,val);
    T[t] = T[t+1]+T[t+(tm-tl+1)*2];
}
ll get(int t,int tl,int tr,int l,int r){
    if (l>tr || tl>r)
        return 0;
    if (l<=tl && tr<=r)
        return T[t];
    push(t,tl,tr);
    int tm = (tl+tr)/2;
    return get(t+1,tl,tm,l,r)+get(t+(tm-tl+1)*2,tm+1,tr,l,r);
}
void solve() {
    int n,k;
    cin>>n>>k;
    ll res = 0;
    for(int i = 1;i<=n;++i) cin>>A[i];
    for(int i = n;i>=1;--i){
        ll el = A[i];
        ll cur = get(0,1,n,1,i);
        ll div = min(i,k);
        ll dif = max(0ll,el-cur)/div+(max(0ll,el-cur)%div!=0);
        update(0,1,n,i-div+1,i,dif);
        res+=dif;
    }
    cout<<res<<endl;

}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}