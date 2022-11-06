#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
const ll mod=998244353;
// const ll mod=1e9+7;
ll INF=1e18;
const ll N=300005;
ll po(ll a,ll b)
{
    ll re=1;  
    while(b)
    {
        if(b%2==1)
        {
            re=(re*a);
            re%=mod;
        }
        a=(a*a);
        a%=mod;
        b>>=1;
    }
    return re;
}
ll ncr[505][505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    
    ll test=1;
    // int gt=0;
    // cin>>test;
    while(test--)
    {
        ll n,x,c;
        cin>>n>>x;
        FOR(i,1,n+1)
        {
            c=1;
            FOR(j,0,i+1)
            {
                ncr[i][j]=c;
                c=(c*(i-j))%mod;
                c=(c*po(j+1,mod-2))%mod;
            }
        }
        ll dp[n+1][x+1];
        memset(dp,0,sizeof(dp));
        FOR(i,0,x+1)
        {
            dp[0][i]=1;
        }
        FOR(i,2,n+1)
        {
            FOR(j,1,x+1)
            {
                if(j<i)
                {
                    dp[i][j]=po(j,i);
                }
                else
                {
                    FOR(k,0,i+1)
                    {
                        dp[i][j]=(dp[i][j]+((ncr[i][k]*po(i-1,k))%mod)*dp[i-k][j-(i-1)])%mod;
                    }
                }
                
                // cout<<dp[i][j]<<' ';
            }
            // cout<<'\n';
        }
        cout<<dp[n][x];
    }
    return 0;
}