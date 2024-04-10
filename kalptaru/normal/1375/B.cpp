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
		int n,m;
		cin>>n>>m;
		ll a[n][m];
		bool f=1;
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				cin>>a[i][j];
				if(i==0 || i==(n-1))
				{
					if(j==0 || j==(m-1))
					{
						if(a[i][j]>2)
						{
							f=0;
						}
						else
						a[i][j]=2;
					}
					else
					{
						if(a[i][j]>3)
						{
							f=0;
						}
						else
						a[i][j]=3;
					}
				}
				else
				{
					if(j==0 || j==(m-1))
					{
						if(a[i][j]>3)
						{
							f=0;
						}
						else
						a[i][j]=3;
					}
					else
					{
						if(a[i][j]>4)
						{
							f=0;
						}
						else
						a[i][j]=4;
					}
				}
			}
		}
		if(f==0)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			FOR(i,0,n)
			{
				FOR(j,0,m)
				cout<<a[i][j]<<' ';
				cout<<'\n';
			}
		}
	}
	return 0;
}