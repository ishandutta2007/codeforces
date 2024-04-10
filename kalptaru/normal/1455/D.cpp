#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e18;
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
		int n,x;
		cin>>n>>x;
		int a[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		int p;
		bool f=1;
		FOR(i,1,n)
		{
			if(a[i]<a[i-1])
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			cout<<0<<'\n';
			continue;
		}
		FOR(i,0,n)
		{
			if(a[i]>x)
			{
				p=i;
				break;
			}
			if(i<(n-1) && a[i+1]<a[i])
			{
				f=1;
				break;
			}
		}
		FOR(i,p,n)
		{
			if(a[i]<x)
			{
				f=1;
				break;
			}
		}
		if(f)
		{
			cout<<-1<<'\n';
			continue;
		}
		int ans=0;
		FOR(i,p,n)
		{
			if(a[i]>x)
			{
				swap(a[i],x);
				ans++;
			}
			else if(i>0 && a[i]<a[i-1])
			{
				cout<<-1<<'\n';
				break;
			}
			FOR(j,i+1,n)
			{
				if(a[j]<a[j-1])
				{
					f=1;
					break;
				}
			}
			if(f==0)
			{
				cout<<ans<<'\n';
				break;
			}
			f=0;
		}

	
	}
	return 0;
}