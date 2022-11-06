#include<bits/stdc++.h>
#define ri register int
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
const int N=1e5+5;
int n,m,dep[N],id[N<<1],in[N],out[N];
vector<int>e[N];
namespace Splay{
	#define lc (son[p][0])
	#define rc (son[p][1])
	int son[N<<1][2],fa[N<<1],mx[N<<1],mn[N<<1],vl[N<<1],tg[N<<1],cnt=0,rt;
	inline void init(){mx[0]=-1e9,mn[0]=1e9;}
	inline void pushup(int p){
		mx[p]=max(vl[p],max(mx[lc],mx[rc]));
		mn[p]=min(vl[p],min(mn[lc],mn[rc]));
	}
	inline void init_node(int id,int Vl){mx[id]=mn[id]=vl[id]=Vl;}
	inline void pushnow(int p,int v){tg[p]+=v,mx[p]+=v,mn[p]+=v,vl[p]+=v;}
	inline void pushdown(int p){
		if(tg[p]){
			if(lc)pushnow(lc,tg[p]);
			if(rc)pushnow(rc,tg[p]);
			tg[p]=0;
		}
	}
	inline int which(int x){return x==son[fa[x]][1];} 
	inline void rotate(int x){
		int y=fa[x],z=fa[y],t=which(x);
		if(z)son[z][which(y)]=x;
		fa[x]=z,fa[y]=x,son[y][t]=son[x][t^1],son[x][t^1]=y;
		if(son[y][t])fa[son[y][t]]=y;
		pushup(y),pushup(x);
	}
	inline void splay(int x,int t){
		while(fa[x]^t){
			pushdown(x);
			int ft=fa[x],ftt=fa[ft];
			if(ftt)pushdown(ftt);
			if(ft)pushdown(ft);
			pushdown(x);
			if(ftt^t)rotate(which(x)^which(ft)?x:ft);
			rotate(x);
		}
		if(!t)rt=x;
	}
	inline int build(int l,int r){
		if(l>r)return 0;
		if(l==r)return l;
		int mid=l+r>>1,p=mid;
		lc=build(l,mid-1);
		if(lc)fa[lc]=mid;
		rc=build(mid+1,r);
		if(rc)fa[rc]=mid;
		pushup(p);
		return p;
	}
	inline int pre(int p){
		splay(p,0),p=lc;
		while(rc)p=rc;
		return pushdown(p),splay(p,0),p; 
	}
	inline int suf(int p){
		splay(p,0),p=rc;
		while(lc)p=lc;
		return pushdown(p),splay(p,0),p;
	} 
	inline int find(int p,int k){
		pushdown(p);
		if(mn[rc]<=k&&k<=mx[rc])return find(rc,k);
		return vl[p]==k?p:find(lc,k);
	}
	inline void dist(int x,int y){
		if(x==y){
			puts("0");
			return;
		}
		x=in[x],y=in[y];
		splay(x,0),splay(y,x);
		int t=y==son[x][0]?mn[son[y][1]]:mn[son[y][0]];
		cout<<vl[x]+vl[y]-2*min(t-1,min(vl[x],vl[y]))<<'\n';
	}
	inline void update(int p,int k){
		splay(1,0),splay(in[p],1);
		int wt=id[find(son[in[p]][0],vl[in[p]]-k)],Pre=pre(in[p]),Suf=suf(out[p]),seg;
		splay(Pre,0),splay(Suf,Pre);
		seg=son[Suf][0],son[Suf][0]=0;
		pushup(Suf),pushup(Pre);
		Suf=out[wt],Pre=pre(Suf);
		splay(Pre,0),splay(Suf,Pre);
		son[Suf][0]=seg,fa[seg]=Suf;
		pushnow(seg,1-k);
		pushup(Suf),pushup(Pre);
		splay(seg,0);		
	}
	inline void query(int k){cout<<id[find(rt,k+1)]<<'\n';}
	#undef lc
	#undef rc
}
int tot=0;
void dfs(int p,int fa){
	id[in[p]=++tot]=p,Splay::init_node(tot,dep[p]);
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa)continue;
		dep[v]=dep[p]+1,dfs(v,p);
	}
	id[out[p]=++tot]=p,Splay::init_node(tot,dep[p]);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	Splay::init(); 
	n=read(),m=read();
	for(ri i=1;i<=n;++i)for(ri tt=read();tt;--tt)e[i].push_back(read());
	++tot,dep[1]=1,dfs(1,0),++tot;
	Splay::rt=Splay::build(1,tot);
	for(ri op,a,b;m;--m){
		op=read();
		if(op==1)a=read(),b=read(),Splay::dist(a,b);
		if(op==2)a=read(),b=read(),Splay::update(a,b);
		if(op==3)a=read(),Splay::query(a);
	}
	return 0;
}