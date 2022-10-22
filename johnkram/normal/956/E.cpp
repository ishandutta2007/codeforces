#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,l,r,ans,s[10005],f[10005];
struct node
{
	int a,b;
	bool operator<(const node& y)const
	{
		if(b==y.b)return a>y.a;
		return b<y.b;
	}
}a[10005];
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	for(i=1;i<=n;i++)scanf("%d",&a[i].a);
	for(i=1;i<=n;i++)scanf("%d",&a[i].b);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)if(!a[i].b)m++;
	for(i=n;i;i--)s[i]=s[i+1]+a[i].a;
	memset(f,127,sizeof(f));
	for(f[0]=0,i=1;i<=n;i++)
	{
		if(i>m)for(j=l;j+s[i]<=r;j++)if(f[j]+m<i)ans=max(ans,n-i+1+(f[j]+m+1<i));
		for(j=r;j>=a[i].a;j--)f[j]=min(f[j],f[j-a[i].a]+a[i].b);
	}
	for(j=l;j<=r;j++)if(f[j]<n-m)ans=max(ans,1);
	cout<<ans<<endl;
	return 0;
}