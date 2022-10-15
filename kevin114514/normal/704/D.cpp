#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define MAXL 5000100
#define MAX 300300
const ll inf=1e9;
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
namespace Flow
{
	int n;
	void Fail(){puts("-1");exit(0);}
	struct Line{int v,next;ll w;}e[MAXL];
	int h[MAX],cnt=2;
	inline void Add(int u,int v,ll w)
	{
		e[cnt]=(Line){v,h[u],w};h[u]=cnt++;
		e[cnt]=(Line){u,h[v],0};h[v]=cnt++;
	}
	int S,T,cur[MAX],level[MAX];
	queue<int> Q;
	bool bfs(int S,int T)
	{
		memset(level,0,sizeof(level));Q.push(S);level[S]=1;
		while(!Q.empty())
		{
			int u=Q.front();Q.pop();
			for(int i=h[u];i;i=e[i].next)
				if(e[i].w&&!level[e[i].v])
					level[e[i].v]=level[u]+1,Q.push(e[i].v);
		}
		return level[T];
	}
	ll dfs(int u,int T,ll flow)
	{
		if(u==T||!flow)return flow;
		ll ret=0;
		for(int &i=cur[u];i;i=e[i].next)
		{
			int v=e[i].v;ll d;
			if(e[i].w&&level[v]==level[u]+1)
			{
				d=dfs(v,T,min(flow,e[i].w));
				ret+=d;flow-=d;
				e[i].w-=d;e[i^1].w+=d;
				if(!flow)break;
			}
		}
		if(!ret)level[u]=0;
		return ret;
	}
	ll Dinic(int S,int T)
	{
		ll ret=0;
		while(bfs(S,T))
		{
			memcpy(cur,h,sizeof(h));
			ret+=dfs(S,T,inf);
		}
		return ret;
	}
	ll M[MAX];int SS,TT;
	void AddEdge(int u,int v,ll B,ll C){if(B>C)Fail();Add(u,v,C-B);M[u]-=B;M[v]+=B;}
	ll Work()
	{
		for(int i=1;i<=n;++i)
			if(M[i]>0)Add(SS,i,M[i]);
			else if(M[i]<0)Add(i,TT,-M[i]);
		Add(T,S,inf);int lastedge=cnt-1;
		Dinic(SS,TT);
		for(int i=h[SS];i;i=e[i].next)if(e[i].w)Fail();
		h[T]=e[h[T]].next;h[S]=e[h[S]].next;
		ll ret=Dinic(S,T);ret+=e[lastedge].w;
		return ret;		
	}
	void Output(bool f,int L,int R)
	{
		for(int u=1;u<L;++u)
		{
			bool fl=false;
			for(int i=h[u];i;i=e[i].next)
				if(e[i].w)
					if(L<=e[i].v&&e[i].v<=R)
						fl=true,putchar(f?'b':'r');
			if(!fl)putchar(f?'r':'b');
		}
	}
}
int n,m,R,B,ox[MAX],oy[MAX],X[MAX],Y[MAX],mxx[MAX],mxy[MAX],cntx[MAX],cnty[MAX],f;
int main()
{
	n=read();m=read();R=read();B=read();if(R>B)swap(R,B),f=1;
	for(int i=1;i<=n;++i)ox[i]=X[i]=read(),oy[i]=Y[i]=read();
	sort(&ox[1],&ox[n+1]);sort(&oy[1],&oy[n+1]);
	int lx=unique(&ox[1],&ox[n+1])-ox-1;
	int ly=unique(&oy[1],&oy[n+1])-oy-1;
	for(int i=1;i<=n;++i)X[i]=lower_bound(&ox[1],&ox[lx+1],X[i])-ox;
	for(int i=1;i<=n;++i)Y[i]=lower_bound(&oy[1],&oy[ly+1],Y[i])-oy;
	Flow::S=n+lx+ly+1;Flow::T=Flow::S+1;Flow::SS=Flow::T+1;Flow::TT=Flow::T+2;
	for(int i=1;i<=n;++i)Flow::AddEdge(n+X[i],i,0,1),++cntx[X[i]];
	for(int i=1;i<=n;++i)Flow::AddEdge(i,lx+n+Y[i],0,1),++cnty[Y[i]];
	Flow::n=n+lx+ly+2;
	for(int i=1;i<=n;++i)mxx[i]=mxy[i]=n;
	for(int i=1;i<=m;++i)
	{
		int t=read(),u=read(),p,d=read();
		if(t&1)p=lower_bound(&ox[1],&ox[lx+1],u)-ox;
		else p=lower_bound(&oy[1],&oy[ly+1],u)-oy;
		if(t&1){if(ox[p]!=u)continue;}
		else if(oy[p]!=u)continue;
		if(t&1)mxx[p]=min(mxx[p],d);
		else mxy[p]=min(mxy[p],d);
	}
	for(int i=1;i<=lx;++i)
		if(mxx[i]>=cntx[i])Flow::AddEdge(Flow::S,n+i,0,inf);
		else Flow::AddEdge(Flow::S,n+i,(cntx[i]-mxx[i]+1)/2,(cntx[i]+mxx[i])/2);
	for(int i=1;i<=ly;++i)
		if(mxy[i]>=cnty[i])Flow::AddEdge(lx+n+i,Flow::T,0,inf);
		else Flow::AddEdge(lx+n+i,Flow::T,(cnty[i]-mxy[i]+1)/2,(cnty[i]+mxy[i])/2);
	int d=Flow::Work();
	printf("%lld\n",1ll*d*R+1ll*(n-d)*B);
	Flow::Output(f,n+1,n+lx);puts("");
	return 0;
}