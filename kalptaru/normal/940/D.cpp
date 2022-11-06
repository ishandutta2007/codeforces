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
//	cout<<('a'-'`');
	while(test--)
	{
		int n;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		string b;
		cin>>b;
		ll lu=mod-7,ld=-1*mod+7,ru=mod-7,rd=-1*mod+7;
		FOR(i,4,n)
		{
			ll ma=a[i],mi=a[i];
			FOR(j,1,5)
			{
				ma=max(a[i-j],ma);
				mi=min(a[i-j],mi);
			}
			if(b[i]!=b[i-1])
			{
				if(b[i]=='0')
				{
					ru=min(ru,mi-1);
				}
				else
				{
					ld=max(ld,ma+1);
				}
				i+=3;
			}
			
		}
		cout<<ld<<' '<<ru;
	}
	return 0;
}