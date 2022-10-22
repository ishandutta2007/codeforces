#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int t,n,m,i,j,ans,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(i=1;i<n;i++)b[i]=a[i+1]-a[i]-1;
		b[n]=m-a[n]+a[1]-1;
		sort(b+1,b+n+1,greater<int>());
		for(ans=0,i=1;i<=n;i++)
		{
			j=b[i]-(i-1<<2);
			if(j<=0)break;
			ans+=max(j-1,1);
		}
		printf("%d\n",m-ans);
	}
	return 0;
}