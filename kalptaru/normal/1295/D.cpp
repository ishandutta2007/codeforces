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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		ll a,m,v;
		cin>>a>>m;
		ll o=__gcd(a,m);
		m/=o;
		a=m;
		v=m;
		for(ll i=2;(i*i)<=v;i++)
		{
			if(m%i==0)
			{
				a/=i;
				a*=(i-1);
				while(m%i==0)
				{
					m/=i;
//					cout<<i<<' ';
				}
			}
		}
		if(m>1)
		{
			a/=m;
			a*=(m-1);
		}
		cout<<a<<'\n';
	}
	return 0;
}