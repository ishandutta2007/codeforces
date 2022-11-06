#include <bits/stdc++.h>
#include <string>
#include <cmath>
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
	ll t=1;
//	cin>>t;
	while(t--)
	{
			int n;
			cin>>n;
			int a[n][n];
			FOR(i,0,n)
			{
				FOR(j,0,n)
				{
					if(i%2==0)
					{
						a[j][i]=n*i+j+1;
					}
					else
					{
						a[n-j-1][i]=n*i+j+1;
					}
				}
			}
			FOR(i,0,n)
			{
				FOR(j,0,n)
				cout<<a[i][j]<<' ';
				cout<<'\n';
			}
	}
	return 0;
}