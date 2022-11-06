#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=1000000007;
ll mod=67280421310721;
//ll mod=998244353;
//ll mod=163577857;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a)%mod;
		}
		a=(a*a)%mod;
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
		int n,k,a;
		cin>>n>>k;
		int cnt[26]={0},c=0,fir=26;
		string s;
		cin>>s;
		FOR(i,0,n)
		{
			cnt[s[i]-'a']++;
			fir=min(fir,(s[i]-'a'));
		}
		char u;
		if(cnt[fir]>=k)
		{
			cnt[fir]-=(k);
			FOR(i,0,26)
			{
				if(cnt[i]>0)
				c++;
			}
//			cout<<c<<':';
			u='a'+fir;
			cout<<u;
			FOR(i,0,26)
			{
				FOR(j,0,cnt[i])
				{
					if((c!=1) || (j%k)==0)
					{
						u='a'+i;
						cout<<u;
					}
				}
			}
		}
		else
		{
			int p=0;
			while(k>0)
			{
				k-=cnt[p];
				p++;
			}
			u='a'+p-1;
			cout<<u;
		}
		cout<<'\n';
	}
	return 0;
}