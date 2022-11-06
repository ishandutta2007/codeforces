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
		int a[n];
		FOR(i,0,n)
		cin>>a[i];
		sort(a,a+n);
		int i=n-1;
		while(m>0 && i>=0)
		{
			m-=a[i];
			i--;
		}
		cout<<n-i-1;
	}
	return 0;
}