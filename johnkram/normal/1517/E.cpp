#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
#define MAXN 200005
#define MAXM 1000005
ll s0[MAXN],s1[MAXN],a2[MAXM];
int t,n,m,i,j,a[MAXN],ans,t1[2][MAXM],b[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			s0[i]=a[i]+s0[i-1];
			s1[i]=a[i]-s1[i-1];
		}
		for(i=ans=0;i<=n;i++)if(s0[i]<<1>s0[n])ans++;
		m=0;
		for(i=1;i<n;i++)
		{
			a2[++m]=s0[i]+s1[i];
			a2[++m]=s1[i]-s0[i]+s0[n]-1;
			a2[++m]=s1[i]-s0[i]+s0[n]-1-(a[n]<<1);
			a2[++m]=s1[i]-s0[i]+s0[n]-1+(a[1]<<1);
			a2[++m]=s1[i]-s0[i]+s0[n]-1+(a[1]-a[n]<<1);
		}
		sort(a2+1,a2+m+1);
		m=unique(a2+1,a2+m+1)-a2-1;
		fill(t1[0],t1[0]+m+1,0);
		fill(t1[1],t1[1]+m+1,0);
		for(i=n-1;i;i--)
		{
			b[i]=lower_bound(a2+1,a2+m+1,s0[i]+s1[i])-a2;
			for(j=b[i];j<=m;j+=j&-j)t1[i&1][j]++;
			for(j=lower_bound(a2+1,a2+m+1,s1[i]-s0[i]+s0[n]-1)-a2;j;j^=j&-j)
			{
				ans+=t1[i&1][j];
				if(ans>=P)ans-=P;
			}
			if(i>1)for(j=lower_bound(a2+1,a2+m+1,s1[i]-s0[i]+s0[n]-1+(a[1]<<1))-a2;j;j^=j&-j)
			{
				ans+=t1[i&1][j];
				if(ans>=P)ans-=P;
			}
		}
		fill(t1[0],t1[0]+m+1,0);
		fill(t1[1],t1[1]+m+1,0);
		if(n>2)for(i=n-2;i;i--)
		{
			for(j=b[i];j<=m;j+=j&-j)t1[i&1][j]++;
			for(j=lower_bound(a2+1,a2+m+1,s1[i]-s0[i]+s0[n]-1-(a[n]<<1))-a2;j;j^=j&-j)
			{
				ans+=t1[i&1][j];
				if(ans>=P)ans-=P;
			}
			if(i>1)for(j=lower_bound(a2+1,a2+m+1,s1[i]-s0[i]+s0[n]-1+(a[1]-a[n]<<1))-a2;j;j^=j&-j)
			{
				ans+=t1[i&1][j];
				if(ans>=P)ans-=P;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}