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
		ll n;
		cin>>n;
		int u=0;
		while((n%2)==0)
		{
			u++;
			n>>=1;
		}
		if(n==1)
		{
			if(u==1)
			{
				cout<<"Ashishgup\n"; 
			}
			else
			{
				cout<<"FastestFinger\n";
			}
		}
		else
		{
			if(u==1)
			{
				bool f=0;
				for(ll j=2;(j*j)<=n;j++)
				{
					if((n%j)==0)
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					cout<<"FastestFinger\n";
					continue;
				}
				cout<<"Ashishgup\n";
			}
			else
			{
				
				cout<<"Ashishgup\n";
			}
		}
	}
	return 0;
}