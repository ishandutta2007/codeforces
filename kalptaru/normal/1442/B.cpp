#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=998244353;
// ll mod=1000000007;
ll INF=1e18;
ll po(ll a,ll b){
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
		int a[n],b[k];
		int pos[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			a[i]--;
			pos[a[i]]=i;
		}
		bool ch[n]={0};
		FOR(i,0,k)
		{
			cin>>b[i];
			b[i]--;
			ch[b[i]]=1;
		}
		ll ans=1,c=2;
		FOR(i,0,k)
		{
			int j=pos[b[i]];
			c=0;
			if(j>0 && ch[a[j-1]]==0)
			{
				c++;
			}
			if(j<(n-1) && ch[a[j+1]]==0)
			{
				c++;
			}
			ans*=c;
			ans%=mod;
			ch[b[i]]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}