// Hydro submission #6215e4da021863789ed33c51@1645602011076
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define R register
using namespace std;
const int N=5e5+5;
int n,u,sum,cnt,ans[N],bigs[N],jl[N*10],size[N],dfn[N],dfns[N],dis[N],dep[N],map[N],maps[N],last[N],l[N];
void ad(int u,int v,int w)
{
	map[++sum]=v;maps[sum]=w;last[sum]=l[u];l[u]=sum;
}
void dg(int x)
{
	size[x]=1;dfn[x]=++cnt;dfns[cnt]=x;
	for (int i=l[x];i;i=last[i])
	{
		dis[map[i]]=dis[x]^maps[i];dep[map[i]]=dep[x]+1;
		dg(map[i]);size[x]+=size[map[i]];
		if (size[map[i]]>size[bigs[x]]) bigs[x]=map[i];
	}
}
void dg2(int x,int lx)
{
	for (int i=l[x];i;i=last[i])
		if (map[i]!=bigs[x])
		{
			dg2(map[i],0);
			ans[x]=max(ans[x],ans[map[i]]);
		}
	for (int i=l[x];i;i=last[i])
		if (map[i]==bigs[x])
		{
			dg2(map[i],1);
			ans[x]=max(ans[x],ans[map[i]]);
		}
	if (jl[dis[x]]) ans[x]=max(ans[x],jl[dis[x]]-dep[x]);
	for (int i=0;i<22;++i) 
		if (jl[dis[x]^(1<<i)]) ans[x]=max(ans[x],jl[dis[x]^(1<<i)]-dep[x]);
	jl[dis[x]]=max(jl[dis[x]],dep[x]);
	for (int i=l[x];i;i=last[i])
		if (map[i]!=bigs[x])
		{
			for (int j=dfn[map[i]];j<=dfn[map[i]]+size[map[i]]-1;++j)
			{
				int v=dfns[j];
				if (jl[dis[v]]) ans[x]=max(ans[x],jl[dis[v]]+dep[v]-2*dep[x]);
				for (int k=0;k<22;++k)
					if (jl[dis[v]^(1<<k)])
						ans[x]=max(ans[x],jl[dis[v]^(1<<k)]+dep[v]-2*dep[x]);
			}
			for (int j=dfn[map[i]];j<=dfn[map[i]]+size[map[i]]-1;++j)
			{
				int v=dfns[j];
				jl[dis[v]]=max(jl[dis[v]],dep[v]);
			}
		}
	if (lx==0)
	{
		for (int i=dfn[x];i<=dfn[x]+size[x]-1;++i)
			jl[dis[dfns[i]]]=0;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;++i)
	{
		scanf("%d",&u);
		char ch=getchar();while (ch<'a'||ch>'z') ch=getchar();
		ad(u,i+1,1<<(ch-'a'));
	}
	dg(1);
	dg2(1,0);
	for (int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}