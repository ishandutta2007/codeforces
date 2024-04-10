#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
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
//	cout<<('a'-'`');
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		bool l[26]={0};
		char ne[26],o='`';
		FOR(i,0,n)
		l[s[i]-'a']=1;
		FORD(i,26,0)
		{
			ne[i]=o;
			if(l[i])
			o=('a'+i);
		}
//		FOR(i,0,26)
//		cout<<ne[i]<<' ';
		if(k<=n)
		{
			int in;
			FORD(i,k,0)
			{
				if(ne[s[i]-'a']!='`')
				{
					in=i+1;
					s[i]=ne[s[i]-'a'];
					break;
				}
			}
			FOR(i,0,in)
			cout<<s[i];
			FOR(i,in,k)
			cout<<o;
		}
		else
		{
			cout<<s;
			FOR(i,n,k)
			cout<<o;
		}
	}
	return 0;
}