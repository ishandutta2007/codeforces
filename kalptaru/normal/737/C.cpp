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
		int n,s;
		cin>>n>>s;
		int a;
		int cnt[n]={0};
		int ans=0;
		FOR(i,0,n)
		{
			cin>>a;
			if(i==(s-1) && a!=0)
			{
				ans++;
				a=0;
			}
			cnt[a]++;
		}
		int t=cnt[0];
		ans--;
		ans+=cnt[0];
		FOR(i,1,n)
		{
//			cout<<ans<<' ';
			if(t>=n)
			break;
			if(cnt[i]==0)
			{
				if(cnt[0]>1)
				{
					cnt[0]--;
					continue;
				}
				ans++;
				t++;
			}
			else
			{
				t+=cnt[i];
			}
		}
		cout<<ans;		
	}
	return 0;
}