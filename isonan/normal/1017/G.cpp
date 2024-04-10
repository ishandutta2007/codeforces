#include <cstdio>
#include <algorithm>

int n,q,fa[100001],siz[1000001];
struct info{
	int sum,mx;
}se[1000001];
bool lazy[1000001];
void pushdown(int x){
	se[x]=(info){-siz[x],-1};
	lazy[x]=1;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1);
		pushdown(x<<1|1);
		lazy[x]=0;
	}
}
info merge(info a,info b){
	return (info){a.sum+b.sum,std::max(b.mx,a.mx+b.sum)};
}
void pushup(int x){
	se[x]=merge(se[x<<1],se[x<<1|1]);
}
void build(int root,int l,int r){
	siz[root]=r-l+1;
	if(l==r){
		se[root]=(info){-1,-1};
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void update(int root,int l,int r,int e,int x){
	if(l==r){
		se[root].mx=se[root].sum+=x;
		return;
	}
	spread(root);
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	pushup(root);
}
void clear(int root,int l,int r,int el,int er){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root);
		return;
	}
	spread(root);
	clear(root<<1,l,(l+r)>>1,el,er);
	clear(root<<1|1,((l+r)>>1)+1,r,el,er);
	pushup(root);
}
info query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return (info){0,-0x7f7f7f7f};
	if(el<=l&&er>=r)return se[root];
	spread(root);
	return merge(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
int head[100001],nxt[200001],b[200001],k;
int size[100001],dfn[100001],top[100001],son[100001],now,mx[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		dfs1(b[i]);
		size[x]+=size[b[i]];
		if(size[son[x]]<size[b[i]])son[x]=b[i];
	}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=son[x])
			dfs2(b[i],b[i]);
	mx[x]=now;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d",fa+i);
		push(fa[i],i);
	}
	dfs1(1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1,t,v;i<=q;i++){
		scanf("%d%d",&t,&v);
		if(t==1){
			update(1,1,n,dfn[v],1);
		}
		else if(t==2){
			clear(1,1,n,dfn[v],mx[v]);
			int tem=v;
			info ans=(info){0,-0x7f7f7f7f};
			while(v){
				info now=query(1,1,n,dfn[top[v]],dfn[v]);
				ans=merge(now,ans);
				v=fa[top[v]];
			}
			update(1,1,n,dfn[tem],-ans.mx-1);
		}
		else{
			info ans=(info){0,-0x7f7f7f7f};
			while(v){
				info now=query(1,1,n,dfn[top[v]],dfn[v]);
				ans=merge(now,ans);
				v=fa[top[v]];
			}
			if(ans.mx>=0)puts("black");
			else puts("white");
		}
	}
}