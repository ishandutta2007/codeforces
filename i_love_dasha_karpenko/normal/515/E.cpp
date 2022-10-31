#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
#define endl '\n'
const ll DIM = 2E5+7;
const ll INF = 1E15;
ll A[DIM],D[DIM];
struct node{
    ll len,a,b;
} T[DIM*4];
node un(node a,node b){
    node ret;
    ret.len = max({a.len,b.len,a.a+b.b});
    ret.a = max(a.a,b.a);
    ret.b = max(a.b,b.b);
    return ret;
}
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t].a = A[tl]*2-D[tl-1];
        T[t].b = A[tl]*2+D[tl-1];
        T[t].len = 0;
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = un(T[t*2+1],T[t*2+2]);
}
node query(ll t,ll tl,ll tr,ll l,ll r){
    if (tl>r || l>tr)return {-INF,-INF,-INF};
    if (l<=tl && tr<=r)
        return T[t];
    ll tm = (tl+tr)/2;
    return un(query(t*2+1,tl,tm,l,r),query(t*2+2,tm+1,tr,l,r));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(ll i = 0;i<DIM*4;++i)T[i].len = T[i].a = T[i].b = -INF;
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i<=n;++i){
        cin>>D[i];
    }
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
    }
    for(ll i = n+1;i<=n*2;++i){
        A[i] = A[i-n];
        D[i] = D[i-n];
    }
    for(ll i = 1;i<=n*2;++i){
        D[i] = D[i-1]+D[i];
    }
    buildtree(0,1,n*2);
    ll last = 0;
    for(ll i = 1;i<=m;++i){
        ll l,r;
        cin>>l>>r;
        if (r<l)r+=n;
        ll res = 0;
        if (l>1 && max(1ll,r-n+1)<=l-1){
            node v1 = query(0,1,n*2,max(1ll,r-n+1),l-1);
            res = max(res,v1.len);
        }
        if (r+1<=l-1+n){
            node v1 = query(0,1,n*2,r+1,l-1+n);
            res = max(res,v1.len);
        }
        cout<<res<<endl;
    }
    return 0;
}