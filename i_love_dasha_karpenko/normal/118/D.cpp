#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 100  +7;
const ll INF = 10E10;
const ll MOD = 10E7;
ll n,m,k1,k2,dp[2*DIM][2][DIM][DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k1>>k2;
    dp[0][0][0][0] = dp[0][1][0][0] = 1;
    forn(i,n+m){
        forn(j,i){
            forn(k,n){
                if (j>k1 || k>n)break;
                dp[i][0][j][k]+=dp[i-1][0][j-1][k-1];
                dp[i][0][j][k]%=MOD;
                forn(ii,k2){
                    if (j!=1)break;
                    dp[i][0][j][k] += dp[i-1][1][ii][k-1];
                    dp[i][0][j][k]%=MOD;
                }
            }
            for(ll k = 0;k<=n;k++){
                if (j>k2)break;
                if (i-k>m)continue;
                dp[i][1][j][k]+=dp[i-1][1][j-1][k];
                dp[i][1][j][k]%=MOD;
                forn(ii,k1){
                    if (j!=1)break;
                    dp[i][1][j][k]+=dp[i-1][0][ii][k];
                    dp[i][1][j][k]%=MOD;
                }
            }
        }
    }
    ll res = 0;
    //cout<<dp[1][1][1][0]<<' '<<dp[1][0][1][1]<<' '<<dp[2][1][1][1]<<' '<<dp[3][0][1][2]<<endl;
    forn(i,DIM-1){
        res=(res+dp[n+m][1][i][n]+dp[n+m][0][i][n])%MOD;
       // cout<<dp[n+m][1][i][n]<<' '<<dp[n+m][0][i][n]<<endl;
    }
    cout<<res<<endl;
    return 0;
}

// 1 2 3
//