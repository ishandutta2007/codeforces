#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef double ld;

void solve();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int z=1;
	while (z--)
		solve();
	return 0;
}

//#define int li

int n, l, k;
ld p[300];
ld dp[251][251][451];
int a[300];

void solve()
{
	cin>>n>>l>>k;
	for (int i=0; i<n; i++)
		cin>>p[i], p[i]/=100.0;
	for (int i=0; i<n; i++)
		cin>>a[i];
	dp[0][0][k+200]=1.0;
	for (int i=0; i<n; i++)
		for (int win=0; win<=i+1; win++)
			for (int w=0; w<=402; w++)
			{
				int space=w-200;
				if (a[i]==-1)
				{
					dp[i+1][win+1][w-1]+=dp[i][win][w]*p[i];
					dp[i+1][win][w]+=dp[i][win][w]*(1-p[i]);
				}
				else
				{
					int nex=w+a[i];
					if (nex>=402)
						nex=402;
					dp[i+1][win+1][nex]+=dp[i][win][w]*p[i];
					dp[i+1][win][w]+=dp[i][win][w]*(1-p[i]);
				}
			}
	ld ans=0.0;
	for (int win=l; win<=n; win++)
		for (int space=0; space<=202; space++)
			ans+=dp[n][win][space+200];
	printf ("%.10lf", ans);
}