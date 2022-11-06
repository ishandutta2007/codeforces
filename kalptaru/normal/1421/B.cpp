#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e18;

ll po(ll a,ll b)
{
	ll re=1;
	a%=mod;
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
		int n;
		cin>>n;
		string s[n];
		FOR(i,0,n)
		cin>>s[i];
		if(s[1][0]==s[0][1])
		{
			if(s[n-1][n-2]==s[n-2][n-1])
			{
				if(s[n-1][n-2]==s[0][1])
				{
					cout<<2<<'\n'<<n-1<<' '<<n<<'\n'<<n<<' '<<n-1<<'\n';
				}
				else
				{
					cout<<0<<'\n';
				}
			}
			else
			{
				if(s[n-1][n-2]==s[0][1])
				{
					cout<<1<<'\n'<<n<<' '<<n-1<<'\n';
				}
				else
				{
					cout<<1<<'\n'<<n-1<<' '<<n<<'\n';
				}
			}
		}
		else
		{
			if(s[n-1][n-2]==s[n-2][n-1])
			{
				if(s[n-1][n-2]==s[0][1])
				{
					cout<<"1\n1 2\n";
				}
				else
				{
					cout<<"1\n2 1\n";
				}
			}
			else
			{
				if(s[n-1][n-2]==s[0][1])
				{
					cout<<"2\n1 2\n"<<n-1<<' '<<n<<'\n';
				}
				else
				{
					cout<<"2\n2 1\n"<<n-1<<' '<<n<<'\n';
				}
			}
		}
	}
	return 0;
}