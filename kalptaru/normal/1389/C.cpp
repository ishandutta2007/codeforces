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
		string s;
		cin>>s;
		int n=s.size();
		int cnt[10]={0};
		vector<int> ind[10];
		FOR(i,0,n)
		{
			cnt[s[i]-'0']++;
			ind[s[i]-'0'].pb(i);
		}
		int ans=0;
		FOR(i,0,10)
		{
			ans=max(ans,cnt[i]);
			FOR(j,0,10)
			{
				if(i==j)
				continue;
				int l=0,r=0;
				bool f=0;
				int cn=0;
				while(l<cnt[i] && r<cnt[j])
				{
					if(ind[i][l]<ind[j][r])
					{
						f=1;
						l++;
					}
					else
					{
						if(f==1)
						cn+=2;
						f=0;
						r++;
					}
				}
				if(f && r<cnt[j])
				cn+=2;
				ans=max(ans,cn);
//				cout<<ans<<' '<<i<<' '<<j<<'\n';
			}
		}
		cout<<n-ans<<'\n';
	}
	return 0;
}