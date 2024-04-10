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
		int n;
		cin>>n;
		int a[2*n];
		if(n%2==1)
		{
			int k=n/2;
			FOR(i,0,k+1)
			{
				a[i]=2*i+1;
			}
			FOR(i,1,k+1)
			{
				a[i+k]=n-2*i;
			}
			FOR(i,0,k)
			{
				a[i+n]=2*i+2;
				a[2*n-2-i]=2*i+2;
			}
			a[2*n-1]=n;
		}
		else
		{
			int k=n/2;
			FOR(i,0,k)
			{
				a[i]=2*i+1;
				a[n-i-1]=2*i+1;
				a[i+n]=2*i+2;
				a[2*n-i-2]=2*i+2;
			}
			a[2*n-1]=n;
			
		}
		FOR(i,0,2*n)
		{
			cout<<a[i]<<' ';
		}
	}
	return 0;
}