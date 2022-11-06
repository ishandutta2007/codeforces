#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) ;for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		ll p;
		ll no=0,ne=0,m,mo=0,me=0;
		FOR(i,0,n)
		{
			cin>>p;
			if(p&1)
			ne++;
			else
			no++;
		}
		cin>>m;
		FOR(i,0,m)
		{
			cin>>p;
			if(p&1)
			me++;
			else
			mo++;
		}
		cout<<mo*no+me*ne<<'\n';
	}
	return 0;
}