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
const ll DIM = 131072+7;
const ll INF = 10E10;

ll vis[DIM],dp[20][DIM][2][2];
vector<ll> upper,lower;
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    forn(i,k){
        ll x;
        cin>>x;
        vis[x] = 1;
    }
    ll sz = po(n);
    for(ll i = 2;i<=sz;i+=2){
        ll sum = vis[i]+vis[i-1];
        if (sum==2){
            dp[1][i][1][1] = 1;
            dp[1][i][1][0]=dp[1][i][0][1]=dp[1][i][0][0]=-INF;
        }
        else if (sum==1){
            dp[1][i][1][0] = 1;
            dp[1][i][0][1] = 1;
            dp[1][i][1][1]=dp[1][i][0][0] = -INF;
        }
        else{
            dp[1][i][1][1]=dp[1][i][1][0]=dp[1][i][0][1] = -INF;
        }
    }
    for(ll level = 2;level<=n;level++){
        ll step = po(level);
        for(ll i = step;i<=sz;i+=step){
            ll s = dp[level-1][i-step/2][1][0]+dp[level-1][i][1][0];
            s = max(s,dp[level-1][i-step/2][0][0]+dp[level-1][i][1][0]);
            s = max(s,dp[level-1][i-step/2][1][0]+dp[level-1][i][0][0]);
            dp[level][i][1][0] = s+1;
            s = dp[level-1][i-step/2][0][1]+dp[level-1][i][0][1];
            s = max(s,dp[level-1][i-step/2][0][0]+dp[level-1][i][0][1]);
            s = max(s,dp[level-1][i-step/2][0][1]+dp[level-1][i][0][0]);
            dp[level][i][0][1] = s+2;
            s = dp[level-1][i-step/2][0][0]+dp[level-1][i][0][0];
            dp[level][i][0][0] = s;
            s = dp[level-1][i-step/2][1][1]+dp[level-1][i][1][1];
            s = max(s,dp[level-1][i-step/2][1][0]+dp[level-1][i][1][1]);
            s = max(s,dp[level-1][i-step/2][1][1]+dp[level-1][i][0][1]);
            s = max(s,dp[level-1][i-step/2][1][0]+dp[level-1][i][0][1]);
            s = max(s,dp[level-1][i-step/2][0][1]+dp[level-1][i][1][0]);
            s = max(s,dp[level-1][i-step/2][1][1]+dp[level-1][i][0][0]);
            s = max(s,dp[level-1][i-step/2][0][0]+dp[level-1][i][1][1]);
            s = max(s,dp[level-1][i-step/2][0][1]+dp[level-1][i][1][1]);
            s = max(s,dp[level-1][i-step/2][1][1]+dp[level-1][i][1][0]);
            dp[level][i][1][1] = s+3;
        }
    }
    //n--;
    cout<<max(max(dp[n][sz][1][1],dp[n][sz][0][0]),max(dp[n][sz][1][0],dp[n][sz][0][1]))+(k!=0)<<endl;
    return 0;
}