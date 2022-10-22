#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n,i,j,ans,a[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=j=1;i<=n;i++)
	{
		for(;j<=n&&a[j]<=a[i]+5;j++);
		ans=max(ans,j-i);
	}
	cout<<ans<<endl;
	return 0;
}