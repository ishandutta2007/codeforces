#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e9;
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
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		FOR(i,0,n)cin>>a[i];
		if(k==1)
		{
			if(a[0]==a[n-1])
			{
				cout<<1<<'\n';
			}
			else
			{
				cout<<-1<<'\n';
			}
			continue;
		}
		int p=a[0],c=1,ans=1;
		FOR(i,0,n)
		{
			if(a[i]!=p)
			{
				if(c<k)
				{
					c++;
					p=a[i];
				}
				else
				{
					ans++;
					p=a[i];
					c=2;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}