#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
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
		int a[n];
		int pos[n];
		int b[n];
		FOR(i,0,n)
		{
			cin>>a[i];
			pos[a[i]-1]=i;
		}
		FOR(i,0,n)
		{
			cin>>b[i];
			b[i]=pos[b[i]-1];
		}
		bool f[n]={0};
		int m=n+1,ans=0;
		FOR(i,0,n)
		{
			if(b[n-i-1]>m)
			{
				ans++;
			}
			else
			m=b[n-i-1];
		}
		cout<<ans;
	}
	return 0;
}