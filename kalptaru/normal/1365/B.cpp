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
		int n;
		cin>>n;
		bool z=0,o=0,p;
		int a[n],b[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		FOR(i,0,n)
		{
			cin>>p;
			if(p)
			o=1;
			else
			z=1;
		}
		if(o==1 && z==1)
		{
			cout<<"Yes\n";
		}
		else
		{
			sort(b,b+n);
			p=1;
			FOR(i,0,n)
			{
				if(a[i]!=b[i])
				p=0;
			}
			if(p)
			cout<<"Yes\n";
			else
			cout<<"No\n";
		}
	}
	return 0;
}