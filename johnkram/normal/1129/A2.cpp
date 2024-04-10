#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[5005],b[5005],c[5005],ans[5005];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)b[i]=n;
	while(m--)
	{
		scanf("%d%d",&i,&j);
		a[i]++;
		b[i]=min(b[i],(j-i+n)%n);
	}
	for(i=1;i<=n;i++)if(a[i])c[i]=(a[i]-1)*n+b[i];
	else c[i]=-1<<30;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)ans[i]=max(ans[i],(j-i+n)%n+c[j]);
		printf("%d ",ans[i]);
	}
	return 0;
}