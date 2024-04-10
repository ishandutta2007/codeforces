#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
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
	cin>>test;
	while(test--)
	{
		int n,k,z;
		cin>>n>>k>>z;
		int a[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		int ma[k]={0};
		ma[0]=a[0]+a[1];
		FOR(i,1,k)
		{
			ma[i]=max(ma[i-1],a[i]+a[i+1]);
		}
		int ans=0;
		int s=0;
		FOR(i,0,k+1)
		{
			s+=a[i];
			int r=k-i;
			if((r%2)==0 && (r/2)<=z)
			{
				ans=max(ans,s+ma[i+1]*(r/2));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}