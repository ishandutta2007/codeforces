#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		int g=0,h=0,c=0;
		ll u=0,y=0;
		FOR(i,0,n)
		{
			if(c%2==0)
			g++;
			else
			h++;
			if(a[i]<0)
			{
				c++;
			}
			if(c%2==0)
			{
				u+=g;
				y+=h;
			}
			else
			{
				u+=h;
				y+=g;
			}
		}
		cout<<y<<' '<<u;
	}
	return 0;
}