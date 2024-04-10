#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int a[MAXN],b[MAXN],n,m,i;
long double ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)scanf("%d",b+i);
	b[n+1]=b[1];
	for(i=1;i<=n;i++)if(a[i]==1||b[i]==1)break;
	if(i<=n)
	{
		puts("-1");
		return 0;
	}
	for(ans=m,i=n;i;i--)
	{
		ans+=ans/(b[i+1]-1);
		ans+=ans/(a[i]-1);
	}
	printf("%.10lf\n",(double)(ans-m));
	return 0;
}