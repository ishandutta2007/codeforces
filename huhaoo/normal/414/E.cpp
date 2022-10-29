/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-12-10 14:29:43
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
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
#include<vector>
#define arr std::vector
const int N=200010;
struct info
{
	int s,min,max;
	info(int S=0,int Min=0,int Max=0){ s=S; min=Min; max=Max; }
};
info operator+(info a,info b)
{
	return info(a.s+b.s,std::min(a.min,a.s+b.min),std::max(a.max,a.s+b.max));
}
int n,s[N][2],f[N],R[N],w[N],q,rt,p[N],F[N];
info m[N];
void update(int u)
{
	m[u]=m[s[u][0]]+info(p[u],p[u],p[u])+m[s[u][1]]; w[u]=w[s[u][0]]+1+w[s[u][1]];
	f[s[u][0]]=f[s[u][1]]=u;
}
void cut(int u){ f[s[u][0]]=f[s[u][1]]=0; }
int merge(int u,int v)
{
	if(!u||!v) return u+v;
	if(R[u]<R[v])
	{
		cut(u); s[u][1]=merge(s[u][1],v); update(u);
		return u;
	}
	else
	{
		cut(v); s[v][0]=merge(u,s[v][0]); update(v);
		return v;
	}
}
void split(int u,int k,int &l,int &r)
{
	if(!u){ l=r=0; return ; }
	cut(u);
	if(w[s[u][0]]+1<=k)
	{
		l=u; split(s[l][1],k-w[s[u][0]]-1,s[l][1],r); update(l);
	}
	else
	{
		r=u; split(s[r][0],k,l,s[r][0]); update(r);
	}
}
int getrk(int u,int las)
{
	if(!u) return 0;
	if(s[u][0]!=las) return 1+w[s[u][0]]+getrk(f[u],u);
	return getrk(f[u],u);
}
void print(int u)
{
	if(!u) return;
	putchar('(');
	print(s[u][0]);
	printf(")%d %d,%d,%d(",u,w[u],m[u].min,m[u].max);
	print(s[u][1]);
	putchar(')');
}
int geth(int u,int h)
{
//	print(u);
//	printf("  %d %d %d\n",m[u].min,m[u].max,h);
	if(s[u][1]&&m[s[u][1]].min<=h-m[s[u][0]].s-p[u]&&h-m[s[u][0]].s-p[u]<=m[s[u][1]].max) return geth(s[u][1],h-m[s[u][0]].s-p[u]);
	if(p[u]==h-m[s[u][0]].s) return u;
	return geth(s[u][0],h);
}
arr<int> e[N];
void dfs(int u,int f)
{
	F[u]=f; rt=merge(rt,u);
	for(auto v:e[u]) if(v!=f) dfs(v,u);
	rt=merge(rt,u+n);
}
int main()
{
	srand(19491001); n=read(); q=read(); m[0]=info(0,n+1,-n-1);
	fr(i,1,n+n) R[i]=rand();
	fr(i,1,n) p[i]=1;
	fr(i,n+1,n+n) p[i]=-1;
	fr(i,1,n+n){ m[i]=info(p[i],p[i],p[i]); w[i]=1; }
	fr(i,1,n) fr(j,1,read()) e[i].push_back(read());
	dfs(1,0);
//	print(rt); putchar(10);
	while(q--)
	{
		int opt=read();
		if(opt==1)
		{
			int u=getrk(read(),-1),v=getrk(read(),-1);
//			printf(" %d %d\n",u,v);
//			print(rt); putchar(10);
			if(u>v) std::swap(u,v);
			int a,b,c;
			split(rt,v,b,c); split(b,u-1,a,b);
//			print(b); putchar(10);
			printf("%d\n",1+m[b].s-m[b].min*2);
			rt=merge(merge(a,b),c);
		}
		else if(opt==2)
		{
//			print(rt); putchar(10);
			int u=read(),D=read(),rk=getrk(u,-1),a,b,c,d;//abcd->acbd
			split(rt,rk-1,a,b);
			int v=geth(a,m[a].s+1-D);
			if(v>n) v=F[v-n];
//			printf("%d %d %d ",u,v,getrk(u+n,-1));
			split(b,getrk(u+n,-1),b,c);
//			printf("%d\n",getrk(v+n,-1));
			split(c,getrk(v+n,-1)-1,c,d);
/*			printf("---------------------\n");
			print(a); putchar(10);
			print(b); putchar(10);
			print(c); putchar(10);
			print(d); putchar(10);
			printf("---------------------\n");*/
			rt=merge(merge(a,c),merge(b,d)); F[u]=v;
//			print(rt); putchar(10);
		}
		else
		{
			int k=read()+1,ans=geth(rt,k);
//			print(rt); putchar(10);
			if(ans>n) ans=F[ans-n];
			printf("%d\n",ans);
		}
	}
	return 0;
}