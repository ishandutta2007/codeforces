#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,i,ans,a[2005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		ans=a[n]-a[1];
		for(i=1;i<n;i++)ans=max(ans,a[i]-a[i+1]);
		for(i=1;i<n;i++)ans=max(ans,a[n]-a[i]);
		for(i=2;i<=n;i++)ans=max(ans,a[i]-a[1]);
		printf("%d\n",ans);
	}
	return 0;
}