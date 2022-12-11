#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=201000;
int n,m,q,no;
int w[maxn],dfn[maxn],low[maxn],tsp;
int s[maxn],st;
int sz[maxn],dep[maxn],fa[maxn],son[maxn],top[maxn],id[maxn],idt;
vector <int> v[maxn],e[maxn];
multiset <int> mt[maxn];
struct Segment_Tree{
	int rt,ver;
	int tson[2][maxn<<1],val[maxn<<1];
	void update(int p){
		val[p]=min(val[tson[0][p]],val[tson[1][p]]);
	}
	void build(int &p,int l,int r){
		p=++ver;
		val[p]=1e9;
		if(l==r)return;
		build(tson[0][p],l,mid);
		build(tson[1][p],mid+1,r);
	}
	void modify(int p,int x,int nw,int l,int r){
		if(l==r){
			val[p]=nw;return;
		}
		if(x<=mid)modify(tson[0][p],x,nw,l,mid);
		else modify(tson[1][p],x,nw,mid+1,r);
		update(p);
	}
	int query(int p,int lr,int rr,int l,int r){
		if(lr<=l&&r<=rr)return val[p];
		if(lr>r||l>rr)return 1e9;
		return min(query(tson[0][p],lr,rr,l,mid),query(tson[1][p],lr,rr,mid+1,r));
	}
}T;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void tarjan(int p){
	dfn[p]=low[p]=++tsp;
	s[++st]=p;
	for(register int i=0;i<v[p].size();++i)
		if(!dfn[v[p][i]]){
			tarjan(v[p][i]);
			low[p]=min(low[p],low[v[p][i]]);
			if(dfn[p]==low[v[p][i]]){
				++no;
				while(s[st+1]!=v[p][i]){
					e[s[st]].push_back(no);
					e[no].push_back(s[st]);
					--st;
				}
				e[p].push_back(no);
				e[no].push_back(p);
			}
		}
		else
			low[p]=min(low[p],dfn[v[p][i]]);
}
void dfs(int p){
	sz[p]=1;
	for(register int i=0;i<e[p].size();++i)
		if(fa[p]!=e[p][i]){
			fa[e[p][i]]=p;
			dep[e[p][i]]=dep[p]+1;
			dfs(e[p][i]);
			if(sz[son[p]]<sz[e[p][i]])
				son[p]=e[p][i];
			sz[p]+=sz[e[p][i]];
			if(p>n)mt[p].insert(w[e[p][i]]);
		}
	if(p>n)w[p]=*mt[p].begin();
}
void dfs2(int p,int t){
	id[p]=++idt;
	top[p]=t;
	T.modify(T.rt,id[p],w[p],1,no);
	if(!son[p])return;
	dfs2(son[p],t);
	for(register int i=0;i<e[p].size();++i)
		if(e[p][i]!=fa[p]&&e[p][i]!=son[p])
			dfs2(e[p][i],e[p][i]);
}

int getans(int u,int v){
	int res=1e9;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])
			swap(u,v);
		res=min(res,T.query(T.rt,id[top[u]],id[u],1,no));
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])swap(u,v);
	res=min(res,T.query(T.rt,id[v],id[u],1,no));
	if(v>n)res=min(res,w[fa[v]]);
	return res;
}
int main(){
	n=read();m=read();q=read();
	for(register int i=1;i<=n;++i)
		w[i]=read();
	for(register int i=1,x,y;i<=m;++i){
		x=read();y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	no=n;
	tarjan(1);
	T.build(T.rt,1,no);
	dfs(1);dfs2(1,1);
	for(register int i=1,x,y;i<=q;++i){
		string op;
		cin>>op;x=read();y=read();
		if(op=="C"){
			if(fa[x]){
				mt[fa[x]].erase(w[x]);
				mt[fa[x]].insert(y);
				w[fa[x]]=*mt[fa[x]].begin();
				T.modify(T.rt,id[fa[x]],w[fa[x]],1,no);
			}
			w[x]=y;
			T.modify(T.rt,id[x],w[x],1,no);
		}
		else printf("%d\n",getans(x,y));
	}
	return 0;
}