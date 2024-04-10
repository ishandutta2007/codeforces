/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-06 16:08:41
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
i64 read()
{
	i64 r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
namespace run
{
#define i64 long long
	const int N=400010;
	i64 n,d[N],begin[N],next[N],to[N],w[N],e,f[N],rt,mw[N],q[N]; int s[N],vis[N];
#define fo(i,a) for(int i=begin[a];i;i=next[i])
	void add(int u,int v,i64 W){ e++; next[e]=begin[u]; begin[u]=e; to[e]=v; w[e]=W; }
	void dfs(int u)
	{
		fo(i,u) if(to[i]!=f[u])
		{
			d[to[i]]=d[u]+w[i]; f[to[i]]=u; dfs(to[i]);
		}
	}
	void dfs1(int u)
	{
		mw[u]=0;
		fo(i,u) if(to[i]!=f[u]){ dfs1(to[i]); mw[u]=std::max(mw[u],mw[to[i]]+w[i]); }
	}
	void dfs2(int u)
	{
		fo(i,u) if(to[i]!=f[u]){ mw[to[i]]=std::max(mw[to[i]],mw[u]+w[i]); dfs2(to[i]); }
	}
	int getf(int u){ return f[u]==u?u:f[u]=getf(f[u]); }
	int main()
	{
		n=read();
		fr(i,1,n-1){ int u=read(),v=read(); i64 w=read(); add(u,v,w); add(v,u,w); }
		f[1]=d[1]=0; dfs(1); int p=1;
		fr(i,2,n) if(d[i]>d[p]) p=i;
//		fr(i,1,n) printf("%I64d%c",d[i],i==n?'\n':' ');
		f[p]=d[p]=0; dfs(p); p=1;
		fr(i,2,n) if(d[i]>d[p]) p=i;
		rt=p;
		for(int i=p;i;i=f[i]) if(std::max(d[i],d[p]-d[i])<std::max(d[rt],d[p]-d[rt])) rt=i;
		f[rt]=d[rt]=0; dfs(rt);
		dfs1(rt);
		int r1=0,r2=0;
		fo(i,rt)
			if(!r1||mw[to[i]]+w[i]>=mw[to[r1]]+w[r1]){ r2=r1; r1=i; }
			else if(!r2||mw[to[i]]+w[i]>=mw[to[r2]]+w[r2]) r2=i;
		mw[to[r1]]=std::max(mw[to[r1]],mw[to[r2]]+w[r1]+w[r2]);
		fo(i,rt) if(i!=r1) mw[to[i]]=std::max(mw[to[i]],mw[rt]+w[i]);
		fo(i,rt) dfs2(to[i]);
		fr(i,1,n) q[i]=i;
		std::sort(q+1,q+n+1,[&](int a,int b){ return mw[a]>mw[b]; });
		fr(T,1,read())
		{
			i64 l=read();
			int ans=0;
			fr(i,1,n){ f[i]=i; s[i]=1; vis[i]=0; }
			for(int i=1,j=1;i<=n;i++)
			{
				while(mw[q[j]]-mw[q[i]]>l){ s[getf(q[j])]--; j++; }
				fo(k,q[i]) if(vis[to[k]])
				{
//					printf("%I64d %I64d\n",q[i],to[k]); fflush(stdout);
					s[q[i]]+=s[getf(to[k])]; f[getf(to[k])]=q[i];
				}
				ans=std::max(ans,s[q[i]]); vis[q[i]]=1;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
}
int main(){ return run::main(); }