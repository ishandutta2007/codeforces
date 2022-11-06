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
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		int c[k],m[n],cnt[k]={0};
		FOR(i,0,n)
		{
			cin>>m[i];
			cnt[m[i]-1]++;
		}
		FOR(i,0,k)
		cin>>c[i];
		vector<int> a[n+1];
		int as[n+1]={0};
		int p=0;
		FORD(i,k,0)
		{
			if(i==(k-1) || c[i]!=c[i+1])
			p=0;
			else
			p=max(0,p-1);
			while(cnt[i]>0)
			{
				while(as[p]<c[i] && cnt[i]>0)
				{
					cnt[i]--;
					a[p].pb(i+1);
					as[p]++;
				}
				p++;
			}
		}
		int ans=0;
		while(a[ans].size()>0)
		ans++;
		cout<<ans<<'\n';
		FOR(i,0,ans)
		{
			cout<<a[i].size();
			FOR(j,0,a[i].size())
			cout<<' '<<a[i][j];
			cout<<'\n';
		}
	}
	return 0;
}