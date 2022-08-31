#include <cstdio>

int head[500001],nxt[1000001],b[1000001],k,lazy[2100001];
int son[1000001],dfn[1000001],size[1000001],mx[1000001],now,top[1000001],fa[1000001],n;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	size[x]=1;
	fa[x]=f;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			if(size[son[x]]<size[b[i]])son[x]=b[i];
			size[x]+=size[b[i]];
		}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x]&&b[i]!=son[x])dfs2(b[i],b[i]);
	mx[x]=now;
}
void spread(int root){
	if(lazy[root]){
		lazy[root<<1]=lazy[root<<1|1]=lazy[root];
		lazy[root]=0;
	}
}
void update(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		lazy[root]=x;
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
int query(int root,int l,int r,int e){
	if(l==r)return lazy[root];
	spread(root);
	if((l+r)>>1>=e)return query(root<<1,l,(l+r)>>1,e);
	else return query(root<<1|1,((l+r)>>1)+1,r,e);
}
int main(){
	scanf("%d",&n);
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s);
	}
	dfs1(1,0);
	dfs2(1,1);
	int Q;
	scanf("%d",&Q);
	for(int i=1,opt,x;i<=Q;i++){
		scanf("%d%d",&opt,&x);
		if(opt==1)update(1,1,n,dfn[x],mx[x],1);
		else if(opt==2){
			while(x){
				update(1,1,n,dfn[top[x]],dfn[x],-1);
				x=fa[top[x]];
			}
		}
		else{
			printf("%d\n",query(1,1,n,dfn[x])>0);
		}
	} 
}