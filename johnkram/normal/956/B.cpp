#include<bits/stdc++.h>
using namespace std;
double ans;
int n,m,i,j,a[100005];
bool b;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=j=1;i<=n;i++)
	{
		for(;j<=n&&a[j]-a[i]<=m;j++);
		if(j>i+2)
		{
			b=1;
			ans=max(ans,(double)(a[j-1]-a[i+1])/(a[j-1]-a[i]));
		}
	}
	if(b)printf("%.9lf\n",ans);
	else puts("-1");
	return 0;
}