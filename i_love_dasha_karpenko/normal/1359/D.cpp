#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E5+7;
const ll INF = 1E16;
ll base = 30;
ll A[DIM],dp[71];
ll res = 0;
void solve(ll l,ll r){
    ll tm = (l+r)/2;
    if (l==r)return;
    solve(l,tm);
    solve(tm+1,r);
    for(ll i = 0;i<=70;++i)dp[i] = 0;
    ll mx = -30;
    ll sum = 0;
    for(ll i = tm+1;i<=r;++i){
        sum+=A[i];
        mx = max(mx,A[i]);
        for(ll j = mx+base;j<=70;++j){
            dp[j] = max(dp[j],sum);
        }
    }
    sum = 0;
    mx = -30;
    for(ll i = tm;i>=l;--i){
        sum+=A[i];
        mx = max(mx,A[i]);
        res = max(res,sum+dp[mx+base]-mx);
        for(ll j = mx+base+1;j<=70;++j){
            res = max(res,sum+dp[j]-j+base);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n)cin>>A[i];
    solve(1,n);
    cout<<res<<endl;
    return 0;
}