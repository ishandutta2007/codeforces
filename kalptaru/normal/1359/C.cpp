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
		long double c,h,t,m,e,i1,i2;
		ll o1,o2;
		
		cin>>h>>c>>t;
		h-=c;
		t-=c;
		m=h/2;
		if(t<=m)
		cout<<2<<'\n';
		else
		{
			t-=m;
			e=m/t;
//			cout<<e<<' ';
			o1=e;
			if(o1%2==0)
			{
				o2=o1+1;
				o1--;
			}
			else
			{
				o2=o1+2;
			}
			i1=o1;
			i2=o2;
			if((m/i1-t)>(t-m/i2))
			{
				cout<<o2<<'\n';
			}
			else
			{
				cout<<o1<<'\n';
			}
		}
	}
	return 0;
}