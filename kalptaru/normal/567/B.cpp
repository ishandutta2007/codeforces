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
		int n,r;
		cin>>n;
		bool in[1000001]={0};
		int cnt=0,ans=0;
		char s;
		FOR(i,0,n)
		{
			cin>>s>>r;
			if(s=='-')
			{
				if(in[r])
				{
					in[r]=0;
					cnt--;
				}
				else
				{
					ans++;
				}
			}
			else
			{
				in[r]=1;
				cnt++;
				ans=max(ans,cnt);
			}
		}
		cout<<ans;
	}
	return 0;
}