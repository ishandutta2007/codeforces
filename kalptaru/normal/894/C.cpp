#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
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
		int m;
		cin>>m;
		int a[m];
		cin>>a[0];
		if(m==1)
		{cout<<1<<'\n'<<a[0];return 0;}
		bool f=1;
		FOR(i,1,m)
		{
			cin>>a[i];
			if((a[i]%a[0])!=0)
			f=0;
		}
		if(f==0)
		cout<<-1;
		else
		{
			cout<<2*(m-1)<<'\n';
			FOR(i,1,m)
			{
				cout<<a[0]<<' '<<a[i]<<' ';
			}
		}
	}
	return 0;
}