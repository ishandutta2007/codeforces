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
		int n,p;
		cin>>n>>p;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		sort(a,a+n);
		vector<int> ans;
		FOR(i,1,2001)
		{
			bool f=1;
			int j=0,k=0;
			while(k<n && f)
			{
				while(j<n && a[j]<=(i+k))
				{
					j++;
				}
				if(((j-k)%p)==0)
				{
					f=0;
				}
				k++;
			}
			if(f)
			ans.pb(i);
		}
		cout<<ans.size()<<'\n';
		FOR(i,0,ans.size())
		cout<<ans[i]<<' ';
	}
	return 0;
}