#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 1e8;
const ll MOD = 1E9+123;

ll n,k;
ll F(ll x){
    //if (x%2!=0 && x*2>n)return 1>=k;

    if (x>n)return 0;
    ll cnt = 1;
    ll res = 1;
    ll base = x,last = x,mx = x;
    if (x%2==0 && x+1<=n){
        cnt++;
        last++;
        res++;
        mx++;
    }
    while(base*2<=n){
        base*=2;
        mx = mx*2+1;
        res+=min(mx-max(last,base-1),n-max(base-1,last));
       // cnt=min((mx-max(last,base-1))/2,(n-max(base-1,last)+1)/2);


        last = min(n,mx);
    }
    return res>=k;
}
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    //cout<<F(5)<<endl;
    ll l = 1,r = n/2;
    ll res = 1;
    while(l<r){
        ll tm = (l+r+1)/2;
        if (F(tm*2))l = tm;
        else r = tm-1;
    }
    if (F(l*2))
    res = l*2;
    l = 1;r = n/2;
    while(l<r){
        ll tm = (l+r+1)/2;
        if (F(tm*2+1))l = tm;
        else r = tm-1;
    }
    if (F(l*2+1))
    res = max(res,l*2+1);
    cout<<res<<endl;
    return 0;
}