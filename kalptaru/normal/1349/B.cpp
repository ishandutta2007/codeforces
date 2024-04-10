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
		ll k;
		cin>>k;
		ll a[n];
		bool g=1;
		FOR(i,0,n)
		{
			cin>>a[i];
			if(a[i]==k)
			g=0;
		}
		if(g)
		{
			cout<<"no\n";
			continue;
		}
		if(n==1)
		{
			if(a[0]==k)
			cout<<"yes\n";
			else
			cout<<"no\n";
			continue;
		}
		if(n==2)
		{
			if(min(a[0],a[1])==k)
			cout<<"yes\n";
			else
			cout<<"no\n";
			continue;
		}
		bool f=0;
		FOR(i,0,n-2)
		{
			int c=0;
			FOR(j,i,i+3)
			{
				if(a[j]>=k)
				c++;
			}
			if(c>=2)
			{
				f=1;
				break;
			}
		}
		if(f)
		cout<<"yes\n";
		else
		cout<<"no\n";
	}
	return 0;
}