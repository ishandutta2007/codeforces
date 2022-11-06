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
		int a[n],l[n],m[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			m[i]=0;
			l[i]=-1;
		}
		FOR(i,0,n)
		{
			m[a[i]-1]=max(i-l[a[i]-1],m[a[i]-1]);
			l[a[i]-1]=i;
			a[i]=n+1;
		}
		FOR(i,0,n)
		{
			m[i]=max(n-l[i],m[i]);
		}
		FOR(i,0,n)
		{
			// cout<<m[i]<<' ';
			if(m[i]!=0)
			{
				a[m[i]-1]=min(a[m[i]-1],i+1);
			}
		}
		// cout<<'\n';
		FOR(i,0,n)
		{
			if(i>0)
			{
				a[i]=min(a[i],a[i-1]);
			}
			if(a[i]>n)
			{
				cout<<-1<<' ';
			}
			else
			{
				cout<<a[i]<<' ';
			}
		}
		cout<<'\n';
	}
	return 0;
}