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
		}
		a=(a*a);
		b>>=1;
	}
	return re;
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		int u=n-k-1;
		int q=u/k,r=u%k;
		int o=2;
		int ans=2+q+q;
		if(r==1)
		ans++;
		if(r>1)
		ans+=2;
		cout<<ans<<'\n';
		FOR(i,0,k)
		{
			cout<<"1 "<<o<<'\n';
			FOR(i,0,q)
			{
				cout<<o<<' '<<o+1<<'\n';
				o++;
			}
			if(i<r)
			{
				cout<<o<<' '<<o+1<<'\n';
				o++;
			}
			o++;
		}
	}
	return 0;
}