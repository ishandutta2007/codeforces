#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
const int N=10005,M=6e6+5,inf=0x3f3f3f3f;
int n,m;
struct edge{int v,next,c;};
namespace dinic{
	int s,t,first[M],cnt,d[M],cur[M];
	edge e[M];
	inline void addedge(int u,int v,int c){e[++cnt]=(edge){v,first[u],c},first[u]=cnt;}
	inline void add(int u,int v,int c){if(!c)return;addedge(u,v,c),addedge(v,u,0);}
	inline bool bfs(){
		static int que[M],hd,tl;
		for(ri i=s;i<=t;++i)d[i]=-1;
		d[s]=0,que[hd=tl=1]=s;
		while(hd<=tl){
			int x=que[hd++];
			for(ri i=first[x],v;~i;i=e[i].next){
				v=e[i].v;
				if(~d[v]||e[i].c<=0)continue;
				d[v]=d[x]+1;
				if(v==t)return 1;
				que[++tl]=v;
			}
		}
		return 0;
	}
	inline int dfs(int p,int f){
		if(!f||p==t)return f;
		int flow=f;
		for(ri i=first[p],v,tp;~i;i=e[i].next){
			if(!flow)return f;
			v=e[i].v;
			if(d[v]>d[p]&&e[i].c>0){
				tp=dfs(v,min(flow,e[i].c));
				(!tp)&&(d[v]=-1);
				e[i].c-=tp,e[i^1].c+=tp,flow-=tp;
			}
		}
		return f-flow;
	}
	inline int solve(){
		int res=0,tp=0;
		while(bfs())while((tp=dfs(s,inf)))res+=tp;
		return res;
	}
}
namespace subtask1{
	int det[105][105];
	inline void Main(){
		dinic::cnt=-1;
		dinic::s=0,dinic::t=2*n+1;
		for(ri i=0;i<=n*2+1;++i)dinic::first[i]=-1;
		for(ri i=1;i<=n;++i)dinic::add(0,i,1),dinic::add(i+n,n*2+1,1);
		for(ri x1,x2,y1,y2,i=1;i<=m;++i){
			x1=read(),y1=read(),x2=read(),y2=read();
			++det[x1][y1],--det[x1][y2+1],--det[x2+1][y1],++det[x2+1][y2+1];
		}
		for(ri i=1;i<=n;++i)for(ri j=1;j<=n;++j){
			det[i][j]+=det[i-1][j]+det[i][j-1]-det[i-1][j-1];
			if(!det[i][j])dinic::add(i,j+n,1);
		}
		cout<<dinic::solve();
		exit(0);
	}
}
int all=0,idx[M],rt[N],tot=0,son[M][2],siz[M];
#define lc (son[p][0])
#define rc (son[p][1])
#define mid (l+r>>1)
inline void build(int&p,int l,int r){
	p=++tot,siz[p]=r-l+1;
	idx[p]=++all,dinic::first[all]=-1;
	if(l==r){
		dinic::add(idx[p],l+n,1);
		return;
	}
	build(lc,l,mid),build(rc,mid+1,r);
	dinic::add(idx[p],idx[lc],siz[lc]);
	dinic::add(idx[p],idx[rc],siz[rc]);
}
inline void update(int&p,int o,int O,int l,int r,int ql,int qr,int v){
	p=++tot;
	siz[p]=siz[o]+v*(min(qr,r)-max(ql,l)+1),lc=son[o][0],rc=son[o][1];
	idx[p]=++all,dinic::first[all]=-1;
	if(ql<=l&&r<=qr){
		if(l==r)dinic::add(idx[p],l+n,1);
		else{
			dinic::add(idx[p],idx[son[O][0]],siz[son[O][0]]);
			dinic::add(idx[p],idx[son[O][1]],siz[son[O][1]]);
		}
		return;
	}
	if(qr<=mid)update(lc,lc,son[O][0],l,mid,ql,qr,v);
	else if(ql>mid)update(rc,rc,son[O][1],mid+1,r,ql,qr,v);
	else update(lc,lc,son[O][0],l,mid,ql,qr,v),update(rc,rc,son[O][1],mid+1,r,ql,qr,v);
	dinic::add(idx[p],idx[lc],siz[lc]);
	dinic::add(idx[p],idx[rc],siz[rc]);
}
#undef lc
#undef rc
#undef mid
struct F{int l,r,typ;friend inline bool operator<(F a,F b){return a.typ<b.typ;};};
vector<F>upd[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	freopen("own.out","w",stdout);
	#endif
	n=read(),m=read();
	for(ri x1,y1,x2,y2,i=1;i<=m;++i){
		x1=read(),y1=read(),x2=read(),y2=read();
		upd[x1].pb((F){y1,y2,-1}),upd[x2+1].pb((F){y1,y2,1});
	}
	all=n*2;
	dinic::s=0;
	dinic::cnt=-1;
	for(ri i=0;i<=all;++i)dinic::first[i]=-1;
	for(ri i=1;i<=n;++i)dinic::add(0,i,1);
	build(rt[0],1,n);
	for(ri i=1;i<=n;++i){
		rt[i]=rt[i-1];
		sort(upd[i].begin(),upd[i].end());
		for(ri j=upd[i].size()-1;~j;--j)
		update(rt[i],rt[i],rt[0],1,n,upd[i][j].l,upd[i][j].r,upd[i][j].typ);
		dinic::add(i,idx[rt[i]],siz[rt[i]]);
	}
	dinic::t=++all,dinic::first[all]=-1;
	for(ri i=1;i<=n;++i)dinic::add(i+n,all,1);
	cout<<dinic::solve();
	return 0;
}