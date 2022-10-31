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
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 1000+7;
const ll INF = 10E17;
const ll MOD = 10E8+7;
ll dp[17][DIM],dp1[17][DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;cin>>n>>m;
    dp[0][n] = 1;
    dp1[0][1] = 1;
    forn(i,m){
        ll pref = 0;
        for(ll j = n;j>=1;j--){
            pref=(pref+dp[i-1][j])%MOD;
            dp[i][j] = pref;
        }
    }
    forn(i,m){
        ll pref = 0;
        for(ll j = 1;j<=n;j++){
            pref=(pref+dp1[i-1][j])%MOD;
            dp1[i][j] = pref;
        }
    }
    ll res = 0;

    forn(i,n){
        for(ll j = i;j<=n;j++){
            res = (res+dp1[m][i]*dp[m][j])%MOD;
        }
    }
    cout<<res<<endl;
    return 0;
}