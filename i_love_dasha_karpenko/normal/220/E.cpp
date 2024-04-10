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
ll A[DIM],T[2][DIM];
void add(ll ind,ll pos,ll delta){
    for(ll i = pos;i<DIM;i+=(i&-i))
        T[ind][i]+=delta;
}
ll get(ll ind,ll pos){
    ll ret = 0;
    for(ll i = pos;i>0;i-=(i&-i))
        ret+=T[ind][i];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll cur = 0;
    set<ll> S;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        S.insert(A[i]);
    }
    map<ll,ll> M;
    ll ptr = 0;
    for(ll to:S){
        M[to] = ++ptr;
    }
    for(ll i = 1;i<=n;++i){
        A[i] = M[A[i]];
        cur+=i-1-get(1,A[i]);
        add(1,A[i],1);
    }
    ll l = 0;
    ll res = 0;
    for(ll r = 2;r<=n;++r){

        cur-=l-get(0,A[r-1])+get(1,A[r-1]-1);
        add(1,A[r-1],-1);
        while(l+1<r && l-get(0,A[l+1])+get(1,A[l+1]-1)+cur<=k){
            ++l;
            cur+=l-1-get(0,A[l])+get(1,A[l]-1);
            add(0,A[l],1);
        }
        if (cur<=k)res+=l;
    }
    cout<<res<<endl;
    return 0;
}