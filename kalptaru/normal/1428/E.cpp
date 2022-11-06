#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define spre cout<<fixed<<setprecision(10);
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
ll vl(ll a, ll b)
{
	ll c=a/b;
	return (a%b)*(c+1)*(c+1)+(b-a%b)*c*c;
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
	// cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		ll a[n],ans=0;
		set< pair<ll,int> > c;
		pair<ll,int> tem;
		int cn[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			cn[i]=1;
			ans+=a[i]*a[i];
			c.insert(mp(vl(a[i],1)-vl(a[i],2),i));
		}
		FOR(j,n,k)
		{
			tem= *(--c.end());
			c.erase(tem);
			ans-=tem.first;
			int i=tem.second;
			cn[i]++;
			c.insert(mp(vl(a[i],cn[i])-vl(a[i],cn[i]+1),i));
			// cout<<tem.first<<' ';
		}
		// FOR(i,1,6)
		// {
		// 	cout<<vl(19,i)<<'\n';
		// }
		cout<<ans;
	}
	return 0;
}