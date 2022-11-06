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
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b%2==1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
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
		string a[9];
		FOR(i,0,9)
		{	
				cin>>a[i];
		}
		FOR(i,0,3)
		{
			a[i][i*3]=a[i][i*3+1];
		}
		FOR(i,0,3)
		{
			a[i+3][i*3+1]=a[i+3][i*3+2];
		}
		FOR(i,0,3)
		{
			a[i+6][i*3+2]=a[i+6][i*3];
		}
		FOR(i,0,9)
		{
			FOR(j,0,9)
			cout<<a[i][j];
			cout<<'\n';
		}
	}
	return 0;
}