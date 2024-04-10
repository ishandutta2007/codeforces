#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)

typedef long long ll;

#define gc getchar()
inline int read(){char c,p=0;int w;
	while(!isdigit(c=gc))if(c=='-')p=1;w=c&15;
	while(isdigit(c=gc))w=w*10+(c&15);return p?-w:w;
}

template<typename T,typename U>inline bool smin(T&x,const U&y){return y<x?x=y,1:0;}
template<typename T,typename U>inline bool smax(T&x,const U&y){return x<y?x=y,1:0;}

const int N=1e6+5;
int n,nn,m,q,to[N*5],ne[N*5],tot,a[N];
struct Graph{
	int head[N];
	inline void add(int x,int y){to[++tot]=y,ne[tot]=head[x],head[x]=tot;}
}G,T;

int dfn[N],low[N],dfs_clock,st[N],stt;
void dfs(int x){
	dfn[x]=low[x]=++dfs_clock;st[++stt]=x;
	for(int i=G.head[x];i;i=ne[i]){
		const int&y=to[i];
		if(!dfn[y]){
			dfs(y),smin(low[x],low[y]);
			if(low[y]>=dfn[x]){
				T.add(x,++nn);int t;
				do T.add(nn,st[stt]);while(st[stt--]!=y);
			}
		}
		else smin(low[x],dfn[y]);	
	}	
}

std::multiset<int>s[N];
int fa[N],siz[N],dep[N],son[N];

void go1(int x){
	siz[x]=1;
	if(x<=n&&fa[x])s[fa[x]].insert(a[x]);
	for(int i=T.head[x];i;i=ne[i]){
		dep[to[i]]=dep[x]+1,fa[to[i]]=x;
		go1(to[i]);
		siz[x]+=siz[to[i]];
		if(siz[to[i]]>siz[son[x]])son[x]=to[i];
	}
}
int top[N],in[N],id[N],cnt;
void go2(int x,int anc){
	top[x]=anc,in[x]=++cnt;id[cnt]=x;
	if(!son[x])return;go2(son[x],anc);
	for(int i=T.head[x];i;i=ne[i])if(to[i]!=son[x])
	go2(to[i],to[i]);
}

#define ls o<<1
#define rs o<<1|1
int minv[N];
inline void build(int o,int l,int r){
	if(l==r){minv[o]=a[id[l]];return;}
	int mid=l+r>>1;
	build(ls,l,mid),build(rs,mid+1,r);
	minv[o]=std::min(minv[ls],minv[rs]);
}
inline void update(int o,int l,int r,int x,int v){
	if(l==r){minv[o]=v;return;}
	int mid=l+r>>1;
	x<=mid?update(ls,l,mid,x,v):update(rs,mid+1,r,x,v);
	minv[o]=std::min(minv[ls],minv[rs]);
}
inline int ask(int o,int l,int r,int x,int y){
	if(x<=l&&r<=y)return minv[o];
	int mid=l+r>>1;
	if(y<=mid)return ask(ls,l,mid,x,y);
	if(x>mid)return ask(rs,mid+1,r,x,y);
	return std::min(ask(ls,l,mid,x,y),ask(rs,mid+1,r,x,y));
}
#define all 1,1,cnt
int ask(int x,int y){
	int ans=1e9;
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])std::swap(x,y);
		smin(ans,ask(all,in[top[x]],in[x]));x=fa[top[x]];
	}
	if(dep[x]>dep[y])std::swap(x,y);
	smin(ans,ask(all,in[x],in[y]));
	return x<=n?ans:std::min(ans,a[fa[x]]);
}
int main(){
	nn=n=read(),m=read(),q=read();
	REP(i,1,n)a[i]=read();a[0]=1e9;
	while(m--){
		int x=read(),y=read();G.add(x,y),G.add(y,x);
	};
	dfs(1),go1(1),go2(1,1);
	REP(i,n+1,nn)a[i]=*s[i].begin();
	build(all);
	while(q--){
		char c;while(isspace(c=gc));
		int x=read(),y=read();
		if(c=='C'){
			if(fa[x]){
				s[fa[x]].erase(s[fa[x]].find(a[x]));
				s[fa[x]].insert(y);
				update(all,in[fa[x]],a[fa[x]]=*s[fa[x]].begin());
			}
			update(all,in[x],a[x]=y);
		}else printf("%d\n",ask(x,y));
	}
	return 0;
}