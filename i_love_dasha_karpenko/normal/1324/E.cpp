#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2000+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll dp[DIM],olddp[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,h,l,r;
    cin>>n>>h>>l>>r;
    ll res = 0;
    for(ll t = 0;t<h;t++)olddp[t] = dp[t] = -INF;
    olddp[0] = 0;
    forn(i,n){
        ll x;
        cin>>x;
        for(ll t = 0;t<h;t++){
            ll b1 = t+x-1;
            if (b1>=h)b1-=h;
            dp[b1] = max(dp[b1],olddp[t]+(l<=b1 && b1<=r));
            b1++;
            if (b1>=h)b1-=h;
            dp[b1] = max(dp[b1],olddp[t]+(l<=b1 && b1<=r));
        }
        //cout<<dp[21]<<' '<<dp[23]<<endl;
        for(ll t = 0;t<=h;t++){
            olddp[t] = dp[t];
            res = max(res,dp[t]);
            dp[t] = -INF;
        }
    }
    cout<<res<<endl;
    return 0;
}
// a[i]-b[i]>b[j]-a[j]