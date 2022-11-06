#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
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
		}
		a=(a*a);
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
		int n;
		cin>>n;
		int a[n];
		FOR(i,0,n)
		cin>>a[i];
		int p=1,j=n,c;
		bool f=1;
		FOR(i,0,n)
		{
			if(a[n-i-1]==p)
			{
				c=1;
				FOR(k,(n-i),j)
				{
					if(a[k]!=(p+c))
					{
						f=0;
						break;
					}
					c++;
				}
				p+=c;
				j=n-i-1;
				if(f==0)
				break;
			}
			
		}
		if(f)
		cout<<"Yes\n";
		else
		cout<<"No\n";
	}
	return 0;
}