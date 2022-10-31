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
const ll DIM = 1E6+7;
const ll INF = 1E18;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    map<ll,ll> M;

    for(ll i = 1;i<=n;++i){
        ll a,b;
        cin>>a>>b;
        if (M.count(a)==0)M[a] = a;
        if (M.count(b)==0)M[b] = b;
        swap(M[a],M[b]);
    }
    super_set base;
    for(auto to:M){
        base.insert(to.second);
    }
    super_set S;
    ll res = 0;
    for(auto to:M){
        res+=abs(to.second-to.first)-abs(ll(base.order_of_key(to.first))-ll(base.order_of_key(to.second)));
        res+=S.size()-S.order_of_key(to.second);
        S.insert(to.second);
    }
    cout<<res<<endl;
    return 0;
}