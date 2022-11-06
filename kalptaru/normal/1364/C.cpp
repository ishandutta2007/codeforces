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
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n];
		set<int> f,g;
		FOR(i,0,n)
		{
			cin>>a[i];
			f.insert(i);
			g.insert(i);
		}
		int b[n];
		memset(b,-1,sizeof(b));
		int p=0;
		FOR(i,0,n)
		{
//			cout<<a[i]<<' ';
			if(a[i]!=p)
			{
				b[i]=p;
				f.erase(p);
				g.erase(i);
//				cout<<p<<' ';
			}
			int u=*f.begin(),v;
			while(!f.empty() && a[i]>u)
			{
				v=*g.begin();
//				cout<<v<<' '<<i<<'\n';
				b[v]=u;
				f.erase(u);
				g.erase(v);
				u=*f.begin();
			}
			p=a[i];
		}
		FOR(i,0,n)
		{
			if(b[i]==-1)
			cout<<999999<<' ';
			else
			cout<<b[i]<<' ';
		}

	}
	return 0;
}