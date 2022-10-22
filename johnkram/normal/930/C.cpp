#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int m,n,i,j,d[MAXN],a[MAXN],f[MAXN],g[MAXN],ans;
int main()
{
	scanf("%d%d",&m,&n);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		a[i]++;
		a[j+1]--;
	}
	for(i=1;i<=n;i++)a[i]+=a[i-1];
	for(i=1,m=0;i<=n;i++)
	{
		j=upper_bound(d+1,d+m+1,a[i])-d;
		f[i]=j;
		d[j]=a[i];
		if(j>m)m=j;
	}
	for(i=n,m=0;i;i--)
	{
		j=upper_bound(d+1,d+m+1,a[i])-d;
		g[i]=j;
		d[j]=a[i];
		if(j>m)m=j;
	}
	for(i=1;i<=n;i++)ans=max(ans,f[i]+g[i]-1);
	cout<<ans<<endl;
	return 0;
}