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
const ll DIM = 1500+7;
const ll INF = 10E16;
ll n,m,dp[DIM][DIM],A[DIM][DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    forn(i,n)
        forn(j,m)
            cin>>A[i][j];
    forn(i,n)forn(j,m)dp[i][j] = -INF;
    dp[1][0] = 0;
    forn(i,m){
        dp[1][i] = dp[1][i-1]+A[1][i];
    }
    for(ll i = 2;i<=n;i++){
        if (i%2==1){
            ll mx = -INF,sum = A[i][1];
            for(ll j = 2;j<=m;j++){
                mx = max(mx,dp[i-1][j-1]);
                sum+=A[i][j];
                dp[i][j] = mx+sum;
            }
        }
        else{
            ll sum = 0;
            forn(j,m-1)sum+=A[i][j];
            ll mx = -INF;
            for(ll j = m-1;j>=1;j--){
                mx = max(mx,dp[i-1][j+1]);
                dp[i][j] = mx+sum;
                sum-=A[i][j];
            }
        }
    }
    ll res = -INF;
    forn(i,m)res = max(res,dp[n][i]);
    cout<<res<<endl;
    return 0;
}

// 1 2 3
//