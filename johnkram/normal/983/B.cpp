#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005][5005],c[5005][5005],n,q,l,i,j;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)b[i][i]=c[i][i]=a[i];
	for(l=1;l<n;l++)for(i=1;i+l<=n;i++)
	{
		j=i+l;
		c[i][j]=max(b[i][j]=b[i+1][j]^b[i][j-1],max(c[i+1][j],c[i][j-1]));
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&i,&j);
		printf("%d\n",c[i][j]);
	}
	return 0;
}