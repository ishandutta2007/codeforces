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
const ll DIM = 100+14;
const ll INF = 1E19;

ll dp[DIM][DIM],A[DIM][DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        ll n,m;
        cin>>n>>m;

        set<ll> S;
        forn(i,n){

            forn(j,m){
                cin>>A[i][j];
                S.insert(A[i][j]-i+1-j+1);
            }
        }


        ll res = INF;
        for(ll val:S){
            forn(i,n){
                forn(j,m)dp[i][j] = -1;
            }
            if (A[1][1]<val)continue;
            dp[1][1] = A[1][1]-val;
            forn(i,n){
                forn(j,m){
                    if (i==1 && j==1)continue;
                    if (A[i][j]-i-j+2<val)continue;
                    ll base = A[i][j]-j-i+2-val;
                    ll as = INF;
                    if (i>1 && dp[i-1][j]!=-1){
                        as = min(as,dp[i-1][j]+base);
                    }
                    if (j>1 && dp[i][j-1]!=-1){
                        as = min(as,dp[i][j-1]+base);
                    }
                    if (as!=INF)dp[i][j] = as;
                }
            }
            if (dp[n][m]!=-1)res = min(res,dp[n][m]);

        }
        cout<<res<<endl;
    }

    return 0;
}