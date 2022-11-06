#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define pb(a) push_back(a);
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,m,cnt=0;
		vector<int> v;
		cin>>n>>m;
		bool a[n][m],b[n][m],f=0;
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				cin>>a[i][j];
				b[i][j]=0;
			}
		}
		FOR(i,0,n-1)
		{
			FOR(j,0,m-1)
			{
				if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1])
				{
					cnt++;
					b[i][j]=1;
					b[i+1][j]=1;
					b[i][j+1]=1;
					b[i+1][j+1]=1;
					v.pb(i+1);
					v.pb(j+1);
				}
			}
		}
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(a[i][j]!=b[i][j])
				{
					cout<<-1;
					return 0;
				}
			}
		}
		cout<<cnt<<'\n';
		FOR(i,0,cnt)
		{
			cout<<v[2*i]<<' '<<v[2*i+1]<<'\n';
		}
	}
	return 0;
}