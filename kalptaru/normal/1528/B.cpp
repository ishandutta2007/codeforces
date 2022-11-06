#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
#define cintree(t,n) int u,v; FOR(i,1,n){cin>>u>>v;u--;v--;t[v].pb(u);t[u].pb(v);}
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
const ll mod=998244353;
// const ll mod=1e9+7;
ll INF=1e18;
const ll N=100005;
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
        int n;
        cin>>n;
        ll dp[n+1]={0};
        FOR(i,1,n+1)
        {
            for(int j=i;j<=n;j+=i)
            {
                dp[j]++;
            }
        }
        ll s=0;
        FOR(i,1,n+1)
        {
            dp[i]=(dp[i]+s)%mod;
            s=(s+dp[i])%mod;
        }
        cout<<dp[n];

    }

    return 0;
}