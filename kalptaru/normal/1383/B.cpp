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
		int n;
		cin>>n;
		ll a[n],x=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			x^=a[i];
		}
		if(x==0)
		{
			cout<<"DRAW\n";
			continue;
		}
		int l=log2(x);
		x=po(2,l);
		int cn=0;
		FOR(i,0,n)
		{
			if(a[i]&x)
			cn++;
		}
		if((cn%4)==3 && (n%2)==1)
		{
			cout<<"LOSE\n";
		}
		else
		{
			cout<<"WIN\n";
		}
	}
	return 0;
}