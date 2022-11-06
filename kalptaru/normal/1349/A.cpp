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
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
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
vector<int> ch[200001];
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
		int a,o;
		FOR(i,0,n)
		{
			cin>>a;
			o=a;
			for(int j=2;(j*j)<=o;j++)
			{
				if(a%j==0)
				{
					int c=0;
					while(a%j==0)
					{
						a/=j;
						c++;
					}
					ch[j].pb(c);
				}
			}
			if(a>1)
			ch[a].pb(1);
		}
		ll ans=1,b;
		FOR(i,2,200001)
		{
			if(ch[i].size()>=(n-1))
			{
				b=i;
				sort(ch[i].begin(),ch[i].end());
				FOR(j,0,ch[i][ch[i].size()-n+1])
				ans*=b;
			}
		}
		cout<<ans;
	}
	return 0;
}