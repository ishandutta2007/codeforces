#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define MAXN 200005
#define P 1000000007
#define ll long long
bool v[MAXN];
int s[MAXN],a[MAXN],f[MAXN],h[MAXN],ne[MAXN<<1],p[MAXN<<1],d[MAXN],R,sum,n,m,i,j,k,b[MAXN][2],A[MAXN],ans;
void dfs(int x,int fa)
{
    s[x]=1;
    f[x]=0;
    for(int i=h[x];i;i=ne[i])if(!v[p[i]]&&p[i]!=fa)
    {
        dfs(p[i],x);
        s[x]+=s[p[i]];
        f[x]=max(f[x],s[p[i]]);
    }
    f[x]=max(f[x],sum-s[x]);
    if(f[x]<f[R])R=x;
}
void dfs1(int x,int fa)
{
	b[x][0]=1;
	b[x][1]=0;
	for(int i=h[x];i;i=ne[i])if(!v[p[i]]&&p[i]!=fa)
	{
		d[p[i]]=!d[x];
		dfs1(p[i],x);
		b[x][0]+=b[p[i]][1];
		b[x][1]+=b[p[i]][0];
	}
}
void dfs2(int x,int fa,int root)
{
	A[x]=(A[x]+((ll)b[root][d[x]]-b[root][!d[x]]+P)*(b[x][0]+b[x][1])+((ll)b[x][0]-b[x][1]+P)*(b[root][0]+b[root][1]))%P;
	for(int i=h[x];i;i=ne[i])if(!v[p[i]]&&p[i]!=fa)dfs2(p[i],x,root);
}
void work(int x)
{
    v[x]=1;
    int i;
	d[x]=0;
	dfs1(x,0);
	A[x]=(A[x]+(ll)b[x][0]-b[x][1]+P)%P;
	for(i=h[x];i;i=ne[i])if(!v[p[i]])
	{
		b[x][0]-=b[p[i]][1];
		b[x][1]-=b[p[i]][0];
		A[x]=(A[x]+((ll)b[x][0]-b[x][1]+P)*(b[p[i]][0]+b[p[i]][1]))%P;
		dfs2(p[i],x,x);
		b[x][0]+=b[p[i]][1];
		b[x][1]+=b[p[i]][0];
	}
    for(i=h[x];i;i=ne[i])if(!v[p[i]])
    {
    	R=0;
    	sum=s[p[i]];
    	dfs(p[i],0);
    	work(R);
    }
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		p[++m]=k;
		ne[m]=h[j];
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		h[k]=m;
	}
	sum=n;
	f[0]=MAXN;
	dfs(n,0);
	work(R);
	for(i=1;i<=n;i++)
	{
		if(a[i]<0)a[i]+=P;
		ans=(ans+(ll)a[i]*A[i])%P;
	}
	cout<<ans<<endl;
	return 0;
}