#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
int n,i,ans,a[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)
	{
		if(a[i]!=a[1])ans=max(ans,i-1);
		if(a[i]!=a[n])ans=max(ans,n-i);
	}
	cout<<ans<<endl;
	return 0;
}