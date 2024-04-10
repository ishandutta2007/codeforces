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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		ll a[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		ll ma=0,x;
		if((m-1)<=k)
		{
			FOR(i,0,m)
			{
				ma=max(ma,a[i]);
				ma=max(ma,a[n-i-1]);
			}
		}
		else
		{
			FOR(i,0,k+1)
			{
//				cout<<i<<',';
				ll mi=mod;
				FOR(j,0,(m-k))
				{
					mi=min(mi,max(a[i+j],a[n-m+i+j]));
				}
//				cout<<mi<<"----";
				ma=max(mi,ma);
			}
		}
		cout<<ma<<'\n';
	}
	return 0;
}