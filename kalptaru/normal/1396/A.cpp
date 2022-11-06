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
		ll n,o=-1;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		if(n==1)
		{
			cout<<"1 1\n0\n1 1\n0\n1 1\n"<<o*a[0];
			return 0;
		}
		cout<<1<<' '<<n<<'\n';
		FOR(i,0,n)
		{
			cout<<a[i]*o *n<<' ';
		}
		cout<<'\n'<<1<<' '<<n-1<<'\n';
		FOR(i,0,n-1)
		cout<<a[i]*(n-1)<<' ';
		cout<<'\n'<<n<<' '<<n<<'\n'<<a[n-1]*(n-1);
	}
	return 0;
}