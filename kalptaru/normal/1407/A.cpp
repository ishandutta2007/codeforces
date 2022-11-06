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
// ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
//			re%=mod;
		}
		a=(a*a);
//		a%=mod;
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
		int n;
		cin>>n;
		int a[n];
		int o=0,e=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			if(i%2)
			{
				o+=a[i];
			}
			else
			{
				e+=a[i];
			}
		}
		if(o==e)
		{
			cout<<n<<'\n';
			FOR(i,0,n)
			cout<<a[i]<<' ';
			cout<<"\n";
			continue;
		}
		int p=0,q=0,j=0;
		FOR(i,0,n)
		{
			if(i%2)
			{
				o-=a[i];
				if((p+o)==(q+e))
				{
					j=i;
					break;
				}
				q+=a[i];
			}
			else
			{
				e-=a[i];
				if((p+o)==(q+e))
				{
					j=i;
					break;
				}
				p+=a[i];
			}
		}
		cout<<n-1<<'\n';
		FOR(i,0,n)
		{
			if(i!=j)
				cout<<a[i]<<' ';
		}
		cout<<'\n';

	}
	return 0;
}