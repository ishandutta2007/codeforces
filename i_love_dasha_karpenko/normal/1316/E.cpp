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
const ll DIM = 100000+7;
const ll INF = 10E16;
const ll masksz = po(7);
ll n,p,k,dp[DIM][masksz];
pair<ll,vector<ll> > A[DIM];
bool mc(pair<ll,vector<ll> > &a,pair<ll,vector<ll> > &b){
    return a.fi>b.fi;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    cin>>n>>p>>k;
    forn(i,n){
        cin>>A[i].fi;
        A[i].sc.resize(p+1);
    }
    forn(i,n){
        forn(j,p)cin>>A[i].sc[j];
    }
    sort(A+1,A+1+n,mc);
    ll sz = po(p)-1;
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    forn(i,n){
        for(ll mask = 0;mask<=sz;mask++){
            ll bitcnt = __builtin_popcount(mask);
            if (dp[i-1][mask]!=-1){
                dp[i][mask] = dp[i-1][mask];
                if (i-bitcnt<=k)
                dp[i][mask] += A[i].fi;
            }
            for(ll bit = 1;bit<=p;bit++){
                if (po(bit-1)&mask && dp[i-1][mask^po(bit-1)]!=-1){
                    dp[i][mask] = max(dp[i][mask],dp[i-1][mask^po(bit-1)]+A[i].sc[bit]);
                }
            }
        }
    }
    cout<<dp[n][sz]<<endl;
    return 0;
}