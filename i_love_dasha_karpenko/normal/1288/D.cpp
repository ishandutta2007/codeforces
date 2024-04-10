#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef int ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 3*10E4+7;
const ll INF = 10E17;
const ll masksz = po(8)-1;
ll dp[256+7],P[256+7];
ll A[DIM][10];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m; cin>>n>>m;
    if (n==1){
        cout<<1<<' '<<1<<endl;
        return 0;
    }
    forn(i,n){
        forn(j,m)cin>>A[i][j];
    }
    for(ll mask = 1;mask<masksz;mask++){
        dp[mask] = -INF;
        forn(i,n){
            ll mi = INF;
            ll x = mask;
            forn(j,m){
                if (x&1)
                    mi = min(mi,A[i][j]);
                x/=2;
            }
            if (mi>dp[mask]){
                dp[mask] = mi;
                P[mask] = i;
            }
        }
    }
    ll res = -INF;
    pp ans ;
    for(ll mask = 1;mask<=masksz;mask++){
        forn(i,n){
            ll mi = INF;
            ll x = mask;
            forn(j,m){
                if (x&1)
                    mi = min(mi,A[i][j]);
                x/=2;
            }

            ll submask = masksz^mask;
            mi = min(mi,dp[submask]);
            if (mi>res){
                res = mi;
                ans = {i,P[submask]};
            }
        }
    }
    cout<<ans.fi<<' '<<ans.sc<<endl;
   // cout<<res<<endl;
    return 0;
}