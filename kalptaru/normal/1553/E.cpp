#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
const ll mod=1e9+7;
ll INF=1e18;
const int N=100005;
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
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
   
    
	ll test=1;
	// int gt=0;
	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		int a[n],cnt[n]={0};
		FOR(i,0,n)
		{
			cin>>a[i];
			cnt[(n-a[i]+i+1)%n]++;
		}
		vector<int> ans;
		FOR(i,0,n)
		{
			if((n-2*m)>cnt[i])
			{
				continue;
			}
			bool vis[n]={0};
			int o,c=n;
			FOR(j,0,n)
			{
				o=j;
				if(vis[j]==0)
				{
					c--;
					while(vis[o]==0)
					{
						vis[o]=1;
						o=(n+a[o]+i-1)%n;
					}
				}
			}
			if(c<=m)
			{
				ans.pb(i);
			}
		}
		cout<<ans.size();
		FOR(i,0,ans.size())
		{
			cout<<' '<<ans[i];
		}
		cout<<'\n';
	}
	return 0;
}