#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 10 +7;
const ll INF = 10E17+7;

ll n,m,c[DIM],d[DIM],cap[DIM],need[DIM],dp[DIM][1007];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>c[0]>>d[0];
    cap[0] = INF;
    need[0] = 0;
    for(ll i = 0;i<=n;i++){
        if (i%c[0]==0)dp[0][i] = i/c[0]*d[0];
        else dp[0][i] = -INF;
    }
    forn(i,m){
        cin>>cap[i]>>need[i]>>c[i]>>d[i];
        ll can = cap[i]/need[i];
        for(ll left = 0;left<=n;left++)dp[i][left] = dp[i-1][left];
        for(ll took = 1;took<=can;++took){
            for(ll left = 0;left+took*c[i]<=n;left++){
                dp[i][left+took*c[i]] = max(dp[i][left+took*c[i]],dp[i-1][left]+took*d[i]);
            }
        }
    }
    ll res = 0;
    for(ll i = 0;i<=n;i++)res = max(res,dp[m][i]);
    cout<<res<<endl;
    return 0;
}