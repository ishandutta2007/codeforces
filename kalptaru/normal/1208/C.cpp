#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(a) push_back(a);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n][n];
		n=n>>2;
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				FOR(k,0,4)
				{
					FOR(l,0,4)
					{
						a[i*4+k][j*4+l]=(16*((n*i)+j))+(4*k)+l;
					}
				}
			}
		}
		FOR(i,0,4*n)
		{
			FOR(j,0,4*n)
			{
				cout<<a[i][j]<<' ';
			}
			cout<<'\n';
		}
	}
}