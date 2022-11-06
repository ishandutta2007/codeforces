#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll INF=1e18;
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
		ll a[n],b[n];
		bool p=0,m=0;
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		bool f=1;
		FOR(i,0,n)
		{
			cin>>b[i];
			if(b[i]<a[i] && m==0)
			f=0;
			else if(b[i]>a[i] && p==0)
			f=0;
			if(a[i]==1)
			p=1;
			else if(a[i]==-1)
			m=1;
		}
		if(f)
		{
			cout<<"YES"<<'\n';
		}
		else
		cout<<"NO"<<'\n';
	}
	return 0;
}