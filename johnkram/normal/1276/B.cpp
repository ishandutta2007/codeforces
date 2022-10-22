#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 200005
#define MAXM 1000005
#define ll long long
ll A;
int n,m,M,M1,a,b,t,N,su[MAXN],sv[MAXN],top,dfn[MAXN],low[MAXN],f[MAXN],h[MAXN],ne[MAXM],p[MAXM],ANS,ans,h1[MAXN<<1],ne1[MAXN<<2],p1[MAXN<<2],s[MAXN<<1],f1[MAXN<<1];
void add(int x,int y)
{
	if(f[x]==y)return;
	f[x]=y;
	p1[++M1]=y;
	ne1[M1]=h1[x];
	h1[x]=M1;
	p1[++M1]=x;
	ne1[M1]=h1[y];
	h1[y]=M1;
}
void Tarjan(int i,int fa=0)
{
	int j,k;
	dfn[i]=low[i]=++N;
	for(k=h[i];k;k=ne[k])
	{
		j=p[k];
		if(!dfn[j])
		{
			su[++top]=i;
			sv[top]=j;
			Tarjan(j,i);
			low[i]=min(low[i],low[j]);
			if(dfn[i]<=low[j])
			{
				ans++;
				for(;;)
				{
					add(su[top],ans);
					add(sv[top],ans);
					if(su[top]==i&&sv[top]==j)break;
					top--;
				}
				top--;
			}
		}
		else if(j!=fa)low[i]=min(low[i],dfn[j]);
	}
}
void dfs(int x)
{
	s[x]=x<=n;
	for(int i=h1[x];i;i=ne1[i])if(p1[i]!=f1[x])
	{
		f1[p1[i]]=x;
		dfs(p1[i]);
		s[x]+=s[p1[i]];
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b);
		fill(h+1,h+n+1,0);
		fill(h1+1,h1+(n<<1)+1,0);
		fill(f+1,f+n+1,0);
		fill(dfn+1,dfn+n+1,0);
		M=N=0;
		int i,j,k,l;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&j,&k);
			p[++M]=k;
			ne[M]=h[j];
			h[j]=M;
			p[++M]=j;
			ne[M]=h[k];
			h[k]=M;
		}
		ans=n;
		for(i=1;i<=n;i++)if(!dfn[i])
		{
			ANS=ans;
			Tarjan(i);
			if(ANS==ans)
			{
				ans++;
				for(;top;top--)
				{
					add(su[top],ans);
					add(sv[top],ans);
				}
				add(i,ans);
			}
		}
		if(!h1[a]||!h1[b])
		{
			puts("0");
			continue;
		}
		f1[a]=0;
		dfs(a);
		A=s[b]-1;
		f1[b]=0;
		dfs(b);
		A*=s[a]-1;
		cout<<A<<endl;
		
	}
	return 0;
}