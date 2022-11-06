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
int fm(int cnt[],int n)
{
	FOR(i,0,n+1)
	{
		if(cnt[i]==0)
		return i;
	}
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
		int n;
		cin>>n;
		int a[n];
		int cnt[n+1]={0};
		FOR(i,0,n)
		{
			cin>>a[i];
			cnt[a[i]]++;
		}
		int mex;
		FOR(i,0,n+1)
		{
			if(cnt[i]==0)
			{
				mex=i;
				break;
			}
		}
		int co=0;
		vector<int> ans;
		while(co<n)
		{
//			cout<<mex<<' ';
			if(a[co]==co)
			{
				co++;
				continue;
			}
			if(mex==n)
			{
				int v=co;
				while(mex==n)
				{
					cnt[a[v]]--;
					cnt[n]++;
					a[v]=n;
					ans.pb(v);
					mex=fm(cnt,n);
					v++;
				}
			}
			else
			{
				cnt[a[mex]]--;
				cnt[mex]++;
				a[mex]=mex;
				ans.pb(mex);
				mex=fm(cnt,n);
			}
		}
		cout<<ans.size()<<'\n';
		FOR(i,0,ans.size())
		{
			cout<<ans[i]+1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}