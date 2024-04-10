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
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				if((i+j)%2==0)
				cout<<'W';
				else
				cout<<'B';
			}
			cout<<'\n';
		}
	}
	return 0;
}