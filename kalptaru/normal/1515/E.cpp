#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
ll mod=1e9+7;
ll m;
ll INF=1e18;

ll dp[405][405];
ll fac[405],ifac[405];

ll po(ll a,ll b){
    ll re=1;  
    while(b>0)
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
    // freopen("java2016.in", "r", stdin);
    // freopen("java2016.out", "w", stdout);
    // ll gtest=0;
    // spre
	ll test=1;
	// cin>>test;
	while(test--)
	{
		ll n;
		cin>>n>>m;
		mod=m;
		fac[0]=1;
		ifac[0]=1;
		FOR(i,1,n+2)
		{
			fac[i]=(fac[i-1]*i)%m;
			ifac[i]=(po(2,i-1)*po(fac[i],m-2))%m;
			// cout<<ifac[i]<<' '<<fac[i]<<' '<<(ifac[i]*fac[i])%m<<'\n';
		}
		// FOR(i,0,n)
		// {
		// 	cout<<ifac[i]<<' ';
		// }
		dp[0][1]=1;
		FOR(i,1,n)
		{
			FORD(j,n,0)
			{
				FORD(k,n+1,1)
				{
					dp[j][k]=dp[j][k-1];
				}
				if(j>0)
				{
					dp[j][0]=0;
					FOR(k,1,n+1)
					{
						dp[j][0]=(dp[j][0]+dp[j-1][k]*ifac[k])%m;
					}
				}
			}
		}
		ll ans=0;
		FOR(i,0,n)
		{
			FOR(k,1,n+1)
			{
				ans=(ans+(dp[i][k]*((fac[n-i]*ifac[k])%m)%m))%m;

				// cout<<dp[n-1][i][k]<<' '<<(fac[n-i]*ifac[k])%m<<' '<<(dp[n-1][i][k]*((fac[n-i]*ifac[k])%m)%m<<"      ";
			}
			// cout<<'\n';
		}
		cout<<ans;
		
	}
	return 0;
}