#include<bits/stdc++.h>
using namespace std;
#define ll long long
int f[1000005],g[1000005],n,i,j,l,r,x,s[1000005][10];
int main()
{
	n=1000000;
	for(f[0]=i=1;i<=n;i++)
	{
		if(i%10)f[i]=i%10*f[i/10];
		else f[i]=f[i/10];
		if(i<10)g[i]=i;
		else g[i]=g[f[i]];
		for(j=1;j<10;j++)s[i][j]=s[i-1][j];
		s[i][g[i]]++;
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&l,&r,&x);
		printf("%d\n",s[r][x]-s[l-1][x]);
	}
	return 0;
}