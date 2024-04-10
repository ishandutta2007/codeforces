#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define P 1000000007
int n,m,i,j,k,d[2005][2005],r[2005][2005],f[2005][2005][2];
char c[2005][2005];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%s",c[i]);
	for(i=n-1;~i;i--)for(j=m-1;~j;j--)
	{
		d[i][j]=d[i+1][j]+(c[i+1][j]=='R');
		r[i][j]=r[i][j+1]+(c[i][j+1]=='R');
	}
	if(c[n-1][m-1]=='R')
	{
		puts("0");
		return 0;
	}
	if(n==1&&m==1)
	{
		puts("1");
		return 0;
	}
	for(i=n-1;~i;i--)for(j=m-1;~j;j--)if(i==n-1&&j==m-1)f[i][j][0]=f[i][j][1]=1;
	else
	{
		f[i][j][0]=((ll)f[i+1][j][0]+f[i][j+1][1]+P-f[i][m-r[i][j]][1])%P;
		f[i][j][1]=((ll)f[i][j+1][1]+f[i+1][j][0]+P-f[n-d[i][j]][j][0])%P;
	}
	cout<<((ll)f[0][0][0]+f[0][0][1]+P-f[1][0][0]+P-f[0][1][1])%P<<endl;
	return 0;
}