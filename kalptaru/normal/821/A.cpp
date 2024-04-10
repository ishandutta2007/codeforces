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
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n][n];
		FOR(i,0,n)
		{
			FOR(j,0,n)
			cin>>a[i][j];
		}
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				bool f=0;
				if(a[i][j]==1)
				continue;
				FOR(k,0,n)
				{
					FOR(l,0,n)
					{
						if(a[i][j]==(a[i][k]+a[l][j]))
						{
							f=1;
							break;
						}
					}
					if(f==1)
					break;
				}
				if(f==0)
				{
					cout<<"No";
					return 0;
				}
			}
		}
		
		cout<<"Yes";
	}
	return 0;
}