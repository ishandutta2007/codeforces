#include<cstdio>
#include<algorithm>

int a[20],n;
long long f[20];

long long d[555555],dn;

long long s,r;

void dfs(int x,int y,long long z)
{
	if(y<0)return;
	if(x==n/2)
	{
		if(y==0)d[dn++]=z;
		return;
	}
    dfs(x+1,y,z);
    dfs(x+1,y,z+a[x]);
    if(a[x]<20)dfs(x+1,y-1,z+f[a[x]]);
}

void dfs2(int x,int y,long long z)
{
	if(y<0)return;
	if(x==n)
	{
		r+=std::upper_bound(d,d+dn,s-z)-std::lower_bound(d,d+dn,s-z);
		return;
	}
    dfs2(x+1,y,z);
    dfs2(x+1,y,z+a[x]);
    if(a[x]<20)dfs2(x+1,y-1,z+f[a[x]]);
}

int main()
{
	int i,j,m;
	scanf("%d%d%I64d",&n,&m,&s);
	f[0]=1LL;
	for(i=1;i<20;i++)f[i]=f[i-1]*i;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<=m;i++)if(i<=n/2)
	{
		dn=0;
		dfs(0,i,0LL);
        std::sort(d,d+dn);
        dfs2(n/2,m-i,0LL);
	}
	printf("%I64d",r);
}