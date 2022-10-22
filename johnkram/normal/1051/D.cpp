#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
int f[1005][2005][4],i,j,k,l,o[4][4],ans,n,m;
int main()
{
	cin>>n>>m;
	f[1][1][0]=f[1][1][3]=f[1][2][1]=f[1][2][2]=o[0][1]=o[0][2]=o[0][3]=o[3][0]=o[3][1]=o[3][2]=1;
	o[1][2]=o[2][1]=2;
	for(i=2;i<=n;i++)for(j=1;j<=2*i;j++)for(k=0;k<4;k++)for(l=0;l<4;l++)if(j>=o[l][k])
	{
		f[i][j][k]+=f[i-1][j-o[l][k]][l];
		if(f[i][j][k]>=P)f[i][j][k]-=P;
	}
	for(i=0;i<4;i++)
	{
		ans+=f[n][m][i];
		if(ans>=P)ans-=P;
	}
	cout<<ans<<endl;
	return 0;
}