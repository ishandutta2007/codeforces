#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
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
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		int u=(k+n-1)/n;
		if(k%n==0)
		cout<<0<<'\n';
		else
		cout<<2<<'\n';
		bool ans[n][n];
		memset(ans,0,sizeof(ans));
		FOR(i,0,u)
		{
			FOR(j,i,u)
			{
				ans[i][j-i]=1;
				ans[n-1-j+i][n-i-1]=1;
			}
			FOR(j,0,n-u-1)
			{
				ans[i+j+1][u-i+j]=1;
			}
		}
		if((k%n)!=0)
		{
			int o=n-(k%n);
			if((u%2)==0)
			{
				FOR(i,0,o)
				ans[i+1][i]=0;
			}
			else
			{
				FOR(i,0,o)
				ans[i][i]=0;
			}
		}
		FOR(i,0,n)
		{
			FOR(j,0,n)
			cout<<ans[i][j];
			cout<<'\n';
		}
	}
	return 0;
}