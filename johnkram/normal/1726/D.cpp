#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
bool b[MAXN];
int t,n,m,N,M,i,j,k,h[MAXN],ne[MAXM],p[MAXM],d[MAXN],f[MAXN],u[10],v[10];
char ans[MAXN];
void dfs(int x)
{
	b[x]=1;
	for(int i=h[x];i;i=ne[i])if(!b[p[i]])
	{
		f[p[i]]=x;
		d[p[i]]=d[x]+1;
		dfs(p[i]);
	}
	else if(p[i]!=f[x]&&d[p[i]]<d[x])
	{
		u[++N]=x;
		v[N]=p[i];
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&M);
		m=0;
		fill(h+1,h+n+1,0);
		for(k=0;k<M;k++)
		{
			scanf("%d%d",&i,&j);
			p[++m]=j;
			ne[m]=h[i];
			h[i]=m;
			p[++m]=i;
			ne[m]=h[j];
			h[j]=m;
		}
		N=0;
		fill(b+1,b+n+1,0);
		dfs(1);
		if(N==3&&u[2]==u[3])
		{
			swap(u[1],u[3]);
			swap(v[1],v[3]);
		}
		if(N!=3||!(u[1]==u[2]&&(v[1]==u[3]&&v[2]==v[3]||v[1]==v[3]&&v[2]==u[3])))
		{	
			for(i=2;i<=n;i++)for(j=h[i];j;j=ne[j])if(p[j]==f[i])
			{
				ans[j+1>>1]='0';
				break;
			}
			for(i=1;i<=N;i++)for(j=h[u[i]];j;j=ne[j])if(p[j]==v[i])
			{
				ans[j+1>>1]='1';
				break;
			}
		}
		else
		{
			for(i=2;i<=n;i++)for(j=h[i];j;j=ne[j])if(p[j]==f[i])
			{
				ans[j+1>>1]='1'^(i!=u[1]&&i!=u[3]);
				break;
			}
			for(i=1;i<=N;i++)for(j=h[u[i]];j;j=ne[j])if(p[j]==v[i])
			{
				ans[j+1>>1]='1'^(i!=3);
				break;
			}
		}
		ans[M+1]=0;
		puts(ans+1);
	}
	return 0;
}