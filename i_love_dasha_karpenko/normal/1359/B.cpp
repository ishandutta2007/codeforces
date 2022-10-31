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
const ll DIM = 100+7;
const ll INF = 1E16;

ll A[DIM][DIM*10],dp[2][DIM][DIM*10];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;

    while(t--){
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        ll cnt = 0;
        forn(i,n){
            forn(j,m){
                char ch;
                cin>>ch;
                if (ch=='.')A[i][j] = 1;
                if (A[i][j]==1)++cnt;
            }
        }

        ll res = 0;
        forn(i,n){
            forn(j,m){
                if (A[i][j]==0){
                    if (j!=1)
                        dp[1][i][j] = dp[1][i][j-1];
                    else
                        dp[1][i][j] = dp[1][i-1][m];
                    dp[0][i][j] = INF;
                    continue;
                }
                if (j==1){
                    dp[0][i][j] = dp[1][i-1][m];
                    dp[1][i][j] = dp[1][i-1][m]+x;
                }
                else{
                    dp[0][i][j] = dp[1][i][j-1];
                    dp[1][i][j] = min(dp[0][i][j-1]+y,dp[1][i][j-1]+x);
                }
            }
        }
        cout<<dp[1][n][m]<<endl;
        forn(i,n){
            forn(j,m){
                A[i][j] = dp[0][i][j] = dp[1][i][j] = 0;
            }
        }
    }
    return 0;
}