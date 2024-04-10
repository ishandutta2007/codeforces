#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,a[200005],i,j;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		for(i=j=1;i+m<=n;i++)if(a[i+m]-a[i]<a[j+m]-a[j])j=i;
		printf("%d\n",a[j]+a[j+m]>>1);
	}
	return 0;
}