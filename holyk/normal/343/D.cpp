#include<bits/stdc++.h>
#define lson o<<1
#define rson o<<1|1
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=5e5+7;
int n,m,tot,head[N],nxt[N<<1],v[N<<1],cnt;
int fa[N],siz[N],dep[N],hson[N],top[N],sid[N],rid[N];
void dfs1(int x){
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int &y=v[i];
		if(y!=fa[x]){
			dep[y]=dep[x]+1;fa[y]=x;dfs1(y);siz[x]+=siz[y];
			if(hson[x]==0||siz[y]>siz[hson[x]])hson[x]=y;
		}
	}
}
void dfs2(int x,int anc){
	top[x]=anc;sid[x]=++cnt;rid[cnt]=x;
	if(hson[x]==0)return;
	dfs2(hson[x],anc);
	for(int i=head[x];i;i=nxt[i]){
		int &y=v[i];
		if(y!=fa[x]&&y!=hson[x])dfs2(y,y);
	}
}
inline void adde(int x,int y){v[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
int tag[N<<2],val[N<<2];
void pushdown(int o){
	if(~tag[o]){
		val[lson]=val[rson]=tag[lson]=tag[rson]=tag[o];
		tag[o]=-1;
	}
}
void update(int o,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){
		tag[o]=val[o]=k;return;
	}
	pushdown(o);
	int mid=l+r>>1;
	if(x<=mid)update(lson,l,mid,x,y,k);
	if(y>mid)update(rson,mid+1,r,x,y,k);
}
int query(int o,int l,int r,int x){
	if(l==r)return val[o];
	pushdown(o);
	int mid=l+r>>1;
	if(x<=mid)return query(lson,l,mid,x);
	return query(rson,mid+1,r,x);
}
inline void chain_update(int x,int y){
	int tx=top[x],ty=top[y];
	while(tx!=ty){
		if(dep[tx]<dep[ty])swap(tx,ty),swap(x,y);
		update(1,1,n,sid[tx],sid[x],0);
		x=fa[tx];tx=top[x];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,1,n,sid[x],sid[y],0);
}
int main(){
//	freopen("tmp.in","r",stdin);
	n=read();
	REP(i,2,n){
		int x=read(),y=read();
		adde(x,y);adde(y,x);
	}
	dfs1(1);dfs2(1,1);
	memset(tag,-1,sizeof tag);
	m=read();
	while(m--){
		int q=read(),x=read();
		switch(q){
			case 1:update(1,1,n,sid[x],sid[x]+siz[x]-1,1);break;
			case 2:chain_update(1,x);break;
			case 3:printf("%d\n",query(1,1,n,sid[x]));
		}	
	}
	return 0;
}