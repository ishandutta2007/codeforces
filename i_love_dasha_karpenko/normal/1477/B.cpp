#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
ll A[DIM],B[DIM];
ll T[DIM*4];
ll upd[DIM*4];
pair<ll,ll> Q[DIM];
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = A[tl];
        upd[t] = -1;
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = T[t*2+1]+T[t*2+2];
    upd[t] = -1;
}
void push(ll t,ll tl,ll tr){
    if (upd[t]==-1)return;
    ll tm = (tl+tr)/2;
    T[t*2+1] = (tm+1-tl)*upd[t];
    T[t*2+2] = (tr-tm)*upd[t];
    upd[t*2+1] = upd[t*2+2] = upd[t];
    upd[t] = -1;
}
void update(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (l>tr || tl>r)return;
    if (l<=tl && tr<=r){
        T[t] = (tr-tl+1)*val;
        upd[t] = val;
        return;
    }
    push(t,tl,tr);
    ll tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,val);
    update(t*2+2,tm+1,tr,l,r,val);
    T[t] = T[t*2+1]+T[t*2+2];
}
ll get(ll t,ll tl,ll tr,ll l,ll r){
    if (l>tr || tl>r)return 0;
    if (l<=tl && tr<=r)return T[t];
    push(t,tl,tr);
    ll tm = (tl+tr)/2;
    return get(t*2+1,tl,tm,l,r)+get(t*2+2,tm+1,tr,l,r);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            B[i] = ch-'0';
        }
        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            A[i] = ch-'0';
        }
        buildtree(0,1,n);

        for(ll i = 1;i<=q;++i)
            cin>>Q[i].first>>Q[i].second;
        ll flag = 0;
        for(ll i = q;i>=1;--i){
            ll l = Q[i].first,r = Q[i].second;
            ll sum = get(0,1,n,l,r);
            if ((r-l+1)-sum==sum){
                flag = 1;
                break;
            }
            if ((r-l+1)-sum<sum){
                update(0,1,n,l,r,1);
            }
            else{
                update(0,1,n,l,r,0);
            }
        }
        for(ll i = 1;i<=n;++i){
            if (get(0,1,n,i,i)!=B[i])flag = 1;
        }
        if (flag==0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}