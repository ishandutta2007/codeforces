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
		int a[n],m=n+1;
		int mi[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			m=min(m,a[i]);
			mi[a[i]]=m;
		}
		bool f=1;
		FOR(i,a[n-1]+1,n+1)
		{
			
			if(mi[i]>=i)
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			cout<<"YES\n";
		}
		else
		cout<<"NO\n";
	}
	return 0;
}