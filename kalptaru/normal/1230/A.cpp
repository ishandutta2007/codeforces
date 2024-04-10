#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
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
		int a[4];
		FOR(i,0,4)
		cin>>a[i];
		sort(a,a+4);
		if(a[0]+a[3]==a[1]+a[2] || a[0]+a[1]+a[2]==a[3])
		{
			cout<<"YES";
		}
		else
		cout<<"NO";
	}
	return 0;
}