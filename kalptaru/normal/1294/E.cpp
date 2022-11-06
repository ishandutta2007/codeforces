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
		int n,m;
		cin>>n>>m;
		int a[n][m];
		int c[m][n];
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				c[j][i]=0;
				cin>>a[i][j];
			}
		}
		int ans=0;
		int r,q;
		FOR(i,0,m)
		{
			FOR(j,0,n)
			{
				q=(a[j][i]-1)/m;
				r=(a[j][i]-1)%m;
				if(r==i && q<n)
				{
					c[i][(j-q+n)%n]++;
				}
			}
		}
		FOR(i,0,m)
		{
			int m=3*n;
			FOR(j,0,n)
			{
				m=min(m,(n-c[i][j]+j));
//				cout<<c[i][j]<<' ';
			}
			ans+=m;
//			cout<<m<<'\n';
		}
		cout<<ans;
	}
	return 0;
}