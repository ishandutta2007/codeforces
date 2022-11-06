#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef pair<int,int> pii;
const int N=505,inf=1e9;
int sx,sy,vx[N],vy[N],trans[N][N],n;
pii a[N];
struct edge{int v,c,next;};
namespace dinic{
	edge e[1000005];
	int first[N],cur[N],d[N],cnt,s,t;
	inline void init(){memset(first,-1,sizeof(first)),cnt=-1;}
	inline void add(int u,int v,int c){e[++cnt]=(edge){v,c,first[u]},first[u]=cnt;}
	inline void addedge(int u,int v,int c){add(u,v,c),add(v,u,0);}
	inline bool bfs(){
		static int q[N],hd,tl;
		for(ri i=s;i<=t;++i)cur[i]=d[i]=-1;
		d[q[hd=tl=1]=s]=0;
		while(hd<=tl){
			int x=q[hd++];
			cur[x]=first[x];
			for(ri v,i=first[x];~i;i=e[i].next){
				if(~d[v=e[i].v]||e[i].c<=0)continue;
				d[q[++tl]=v]=d[x]+1;
			}
		}
		return ~d[t];
	}
	inline int dfs(int x,int f){
		if(x==t||!f)return f;
		int flow=f,v,t;
		for(ri &i=cur[x];~i;i=e[i].next){
			if(!flow)return f;
			if(d[v=e[i].v]==d[x]+1&&e[i].c>0){
				t=dfs(v,min(flow,e[i].c));
				if(!t)d[v]=-1;
				flow-=t,e[i].c-=t,e[i^1].c+=t;
			}
		}
		return f-flow;
	}
	inline int solve(){
		int ret=0,tmp;
		while(bfs())while(tmp=dfs(s,inf))ret+=tmp;
		return ret;
	}
}
int main(){
	n=read(),n=read();
	dinic::init();
	for(ri i=1,up=n<<1;i<=up;++i)a[i].fi=vx[++sx]=read()-(i&1),a[i].se=vy[++sy]=read()-(i&1);
	sort(vx+1,vx+sx+1),sx=unique(vx+1,vx+sx+1)-vx-1;
	sort(vy+1,vy+sy+1),sy=unique(vy+1,vy+sy+1)-vy-1;
	for(ri i=1,up=n<<1;i<=up;++i){
		a[i].fi=lower_bound(vx+1,vx+sx+1,a[i].fi)-vx;
		a[i].se=lower_bound(vy+1,vy+sy+1,a[i].se)-vy;
	}
	dinic::t=sx+sy+1;
	for(ri i=1;i<sx;++i)dinic::addedge(dinic::s,i,vx[i+1]-vx[i]);
	for(ri i=1;i<sy;++i)dinic::addedge(i+sx,dinic::t,vy[i+1]-vy[i]);
	for(ri A=1,B=2,up=n<<1;A<=up;A+=2,B+=2)for(ri i=a[A].fi;i<a[B].fi;++i)for(ri j=a[A].se;j<a[B].se;++j)trans[i][j]=1;
	for(ri i=1;i<sx;++i)for(ri j=1;j<sy;++j)if(trans[i][j])dinic::addedge(i,j+sx,inf);
	cout<<dinic::solve();
	return 0;
}