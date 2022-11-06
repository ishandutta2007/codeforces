#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e9;
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
		int a[n],b[n],c[n];
		int ar[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		FOR(i,0,n)cin>>b[i];
		FOR(i,0,n)cin>>c[i];
		ar[0]=a[0];
		FOR(i,1,n-1)
		{
			if(ar[i-1]==a[i])
			{
				ar[i]=b[i];
			}
			else
			{
				ar[i]=a[i];
			}
		}
		if(ar[0]!=a[n-1] && ar[n-2]!=a[n-1])
		{
			ar[n-1]=a[n-1];
		}
		else if(ar[0]!=b[n-1] && ar[n-2]!=b[n-1])
		{
			ar[n-1]=b[n-1];
		}
		else
		{
			ar[n-1]=c[n-1];
		}
		FOR(i,0,n)
		{
			cout<<ar[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}