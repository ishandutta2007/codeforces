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
//	cin>>t;
	while ( t-- ) 
	{
		ll a,b;
		cin>>a>>b;
		ll p[10]={0};
		FOR(i,a,b+1)
		{
			int u=i;
			while(u>0)
			{
				p[u%10]++;
				u=u/10;
			}
		}
		cout<<6*(p[0]+p[6]+p[9])+2*p[1]+5*(p[2]+p[3]+p[5])+4*p[4]+3*p[7]+7*p[8];
		
	}
	return 0;
}