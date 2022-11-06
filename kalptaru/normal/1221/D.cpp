#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
ll inf=1000000000000000002;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		ll n;
		cin>>n;
		ll a[n],b[n];
		ll dp[3],tp[3];
		FOR(i,0,n)
		{
			cin>>a[i]>>b[i];
		}
		dp[0]=0;
		dp[1]=b[0];
		dp[2]=b[0]*2;
		ll mi;
		FOR(i,1,n)
		{
			FOR(j,0,3)
			{
				mi=inf;
				FOR(k,0,3)
				{
					if((a[i-1]+k)!=(a[i]+j))
					mi=min(dp[k],mi);
				}
				tp[j]=(mi+b[i]*j);
			}
			FOR(i,0,3)
			dp[i]=tp[i];
		}
		mi=inf;
		FOR(i,0,3)
		mi=min(dp[i],mi);
		cout<<mi<<'\n';
	}
	return 0;
}