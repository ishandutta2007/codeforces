#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef int ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 fdgfdgf
#define y1 fdhfdgfdg
#define endl '\n'
const ll DIM = 1E5+7;
const ll INF = 1E18;
ll A[DIM],T[DIM*4],L[DIM],R[DIM],need[DIM],ans[DIM];
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t] = A[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t] = __gcd(T[t*2+1],T[t*2+2]);
}
ll query(ll t,ll tl,ll tr,ll l,ll r){
    if (l>tr || tl>r)return 0;
    if (l<=tl && tr<=r){
        return T[t];
    }
    ll tm = (tl+tr)/2;
    ll a = query(t*2+1,tl,tm,l,r);
    ll b = query(t*2+2,tm+1,tr,l,r);
    return __gcd(a,b);
}
vector<ll> V[DIM];
ll fen[DIM];
void add(ll pos,ll delta){
    for(ll i = pos;i<DIM;i+=(i&-i))
        fen[i]+=delta;
}
ll get(ll pos){
    ll ret = 0;
    for(ll i = pos;i>0;i-=(i&-i)){
        ret+=fen[i];
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
    }
    buildtree(0,1,n);
    ll t;
    cin>>t;
    map<ll,ll> M;
    ll ptr = 0;
    for(ll i = 1;i<=t;++i){
        cin>>L[i]>>R[i];
        need[i] = query(0,1,n,L[i],R[i]);
        V[L[i]].push_back(-i);
        V[R[i]+1].push_back(i);
        if (M.count(need[i])==0)M[need[i]] = ++ptr;
        need[i] = M[need[i]];
    }
    for(ll i = 1;i<=n+1;++i){

        for(ll to:V[i]){
            if (to<0){
                ans[-to]+=-(get(need[-to])-get(need[-to]-1));
            }
            else{
                ans[to]+=get(need[to])-get(need[to]-1);
            }
        }
        if (M.count(A[i]))
            add(M[A[i]],1);
        //cout<<M[A[i]]<<' '<<get(1)<<' '<<get(2)<<endl;
    }
    cout<<endl;
    for(ll i = 1;i<=t;++i)
        cout<<R[i]-L[i]+1-ans[i]<<endl;
    return 0;
}