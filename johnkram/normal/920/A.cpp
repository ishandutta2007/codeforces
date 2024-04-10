#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[205],i,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)scanf("%d",a+i);
		ans=max(a[1],n-a[m]+1);
		for(i=1;i<m;i++)ans=max(ans,a[i+1]-a[i]+2>>1);
		cout<<ans<<endl;
	}
	return 0;
}