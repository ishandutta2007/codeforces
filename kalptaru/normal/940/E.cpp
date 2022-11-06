#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
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
	int test=1;
//	cin>>test;
//	cout<<('a'-'`');
	while(test--)
	{
		int n,c,l;
		cin>>n>>c;
		ll a[20][n];
		ll s=0;
		FOR(i,0,n)
		{
			cin>>a[0][i];
			s+=a[0][i];
		}
		l=n;
		int j=1;
		int k=1;
		while(l>0)
		{
			FOR(i,0,n)
			{
				a[j][i]=min(a[j-1][i],a[j-1][min(n-1,i+k)]);
			}
			l>>=1;
			k<<=1;
			j++;
		}
		j=log2(c);
		k=po(2,j);
		ll dp[n]={0};
		dp[c-1]=min(a[j][0],a[j][c-k]);
//		cout<<j<<'k';
		FOR(i,c,n)
		{
			dp[i]=max(dp[i-1],min(a[j][i-c+1],a[j][i-k+1])+dp[i-c]);
//			cout<<min(a[j][i-c+1],a[j][i-k+1])<<' ';
		}
//		FOR(i,0,n)
//		cout<<dp[i]<<' ';
		cout<<s-dp[n-1];
	}
	return 0;
}