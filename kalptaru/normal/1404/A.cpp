#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include<vector>
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
//			re%=mod;
		}
		a=(a*a);
//		a%=mod;
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
		ll n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		bool f=1;
		int u=k/2;
		int o=0,z=0;
		int y=-1;
		FOR(i,0,k)
		{
			y=-1;
			for(int j=i;j<n;j+=k)
			{
				if(s[j]=='1')
				{
					if(y==0)
					{
						f=0;
						break;
					}
					y=1;
				}
				else if(s[j]=='0')
				{
					if(y==1)
					{
						f=0;
						break;
					}
					y=0;
				}
			}
			if(f==0)
			break;
			if(y==1)
			z++;
			else if(y==0)
			o++;
		}
		if(o>u || z>u)
		f=0;
		if(f)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}