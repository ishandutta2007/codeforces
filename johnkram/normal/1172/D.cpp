#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[1005],b[1005],a1[1005],a2[1005],a3[1005],a4[1005];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	for(i=n;i;i--)
	{
		if(a[i]==i&&b[i]==i)continue;
		for(j=1;j<=i;j++)if(a[j]==i)a[j]=a[i];
		for(j=1;j<=i;j++)if(b[j]==i)b[j]=b[i];
		a1[++m]=a[i];
		a2[m]=i;
		a3[m]=i;
		a4[m]=b[i];
	}
	printf("%d\n",m);
	for(i=1;i<=m;i++)printf("%d %d %d %d\n",a1[i],a2[i],a3[i],a4[i]);
	return 0;
}