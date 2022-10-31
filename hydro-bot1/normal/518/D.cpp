// Hydro submission #6193a36401410992b6879c69@1637065572384
#include <bits/stdc++.h>
using namespace std;
const int MAXN{2005};
double f[MAXN][MAXN];
int main()
{
	int n,t;double p;
	cin>>n>>p>>t;
	f[0][0]=1;
	double ans{0};
	for (int i{0};i<t;f[i+1][n]+=f[i][n],++i)
		for (int j{0};j<n;++j)
		{
			f[i+1][j+1]+=f[i][j]*p;
			f[i+1][j]+=f[i][j]*(1-p);
			ans+=f[i][j]*p;
		}
	cout<<fixed<<setprecision(6)<<ans<<endl;
	return 0;
}