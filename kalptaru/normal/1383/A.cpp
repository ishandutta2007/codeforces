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
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
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
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		int m=21;
		int ans=0;
		bool f=1;
		FOR(j,0,20)
		{
			m=21;
			FOR(i,0,n)
			{
				if((a[i]-'a')==j)
				{
					if((b[i]-'a')<j)
					{
						f=0;
						break;
					}
					if((b[i]-'a')>j)
					{
						m=min(m,(b[i]-'a'));
					}
				}
			}
			if(f==0)
			break;
			char h='a';
			h+=m;
			if(m==21)
			{
				continue;
			}
			ans++;
			FOR(i,0,n)
			{
				if((a[i]-'a')==j)
				{
					if((b[i]-'a')>j)
					{
						a[i]=h;
					}
				}
			}
//			cout<<h<<"----------";
//			cout<<a<<'\n';
		}
		if(f)
		cout<<ans<<'\n';
		else
		cout<<"-1\n";
	}
	return 0;
}