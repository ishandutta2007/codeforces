#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll ncr[251][251];
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,m;
		cin>>n>>m;
		int a[m]={0},c;
		ll ans=0;
		FOR(i,0,n)
		{
			cin>>c;
			a[c-1]++;
		}
		FOR(i,0,m)
		{
			FOR(j,i+1,m)
			{
				ans+=(a[i]*a[j]);
			}
		}
		cout<<ans;
	}
	return 0;
}