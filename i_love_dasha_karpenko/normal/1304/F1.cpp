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
const ll DIM = 2*10E3+7;
const ll INF = 10E17;
const ll LOG = 21;
ll dp[DIM],ss[DIM],pref[DIM],sm[DIM],pm[DIM],olddp[DIM],A[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    forn(i,n){

        forn(i,m){
            cin>>A[i];
            pref[i] = pref[i-1]+A[i];
        }

        ll sum = 0;
        forn(i,m){
            sum+=A[i];
            if (i>k)sum-=A[i-k];
            ss[i] = sum;
        }
        if (i==1){
            forn(i,m){
                olddp[i] = ss[i];
            }
            continue;
        }
        forn(i,m){
            pm[i] = max(pm[i-1],olddp[i]+ss[i]);
        }
        for(ll i = m;i>=1;i--){
            sm[i] = max(sm[i+1],olddp[i]+ss[i]);
        }
        forn(i,m){
            dp[i] = 0;
            for(ll j = i;j>=max(0ll,i-k);j--){
                dp[i] = max(dp[i],pref[i]-pref[j]+pm[j]);
            }
            for(ll j = i+k;j>=i;j--){
                dp[i] = max(dp[i],pref[j-k]-pref[i-k]+sm[j]);
            }
        }
        forn(i,m){
            //cout<<dp[i]<<' ';
            olddp[i] = dp[i];
            dp[i] = 0;
        }
       // cout<<endl;

    }
    ll res = 0;
    forn(i,m)res = max(res,olddp[i]);
    cout<<res<<endl;
    return 0;
}