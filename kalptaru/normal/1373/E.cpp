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
int ds[1000016];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dp[151][10];
	memset(dp,-1,sizeof(dp));
	ds[0]=0;
	ds[1]=0;
	FOR(i,1,1000015)
	{
		int u=0;
		int o=i;
		while(o)
		{
			u+=(o%10);
			o/=10;
		}
		ds[i+1]=u+ds[i];
	}
	FOR(i,0,1000000)
	{
		int o=0;
		FOR(j,1,11)
		{
			int k=j-1;
			int n=ds[i+j]-ds[i];
			if(n>150)
			continue;
			if(dp[n][k]==-1)
			dp[n][k]=i;
		}
	}
	int test=1;
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		if(k>1)
		{
			cout<<dp[n][k]<<'\n';
		}
		else if(k==0)
		{
			int cn=n/9;
			if((cn*9)!=n)
			cout<<n%9;
			FOR(i,0,cn)
			{
				cout<<9;
			}
			cout<<'\n';
		}
		else
		{
			n--;
			if((n%2)==0)
			{
				n/=2;
				n++;
				int cn=n/9;
				if((cn*9)!=n)
				{
					if(cn>0)				
					cout<<n%9;
					else
					cout<<n-1;
				}
				FOR(i,1,cn)
				{
					cout<<9;
				}
				if(cn>0)
				cout<<8;
				cout<<'\n';
			}
			else
			{
				n++;
				if(n>=10)
				{
					n-=10;
					n/=2;
					n++;
					int cn=n/9;
					if((cn*9)!=n)
					{
						if(cn>0)				
						cout<<n%9;
						else if(n>1)
						cout<<n-1;
					}
					FOR(i,1,cn)
					{
						cout<<9;
					}
					if(cn>0)
					cout<<8;
					cout<<9;
					cout<<'\n';
				}
				else
				{
					cout<<-1<<'\n';
				}
			}
		}
	}
	return 0;
}