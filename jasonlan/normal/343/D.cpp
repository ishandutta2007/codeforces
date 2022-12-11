#include<iostream>
#include<cstdio>
#include<algorithm>
#define mid ((l+r)>>1)
using namespace std;
int n,q;
int head[501000],nxt[1001000],rdc[1001000],tnt;
int size[501000],fa[501000],son[501000],id[501000],top[501000];
int sont[2][1001000],rt;
short tag[1001000];
bool fillin[1001000];
void add(int u,int v){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
}
void dfs(int u){
	size[u]=1;
	for(register int i=head[u];i;i=nxt[i])
		if(!fa[rdc[i]]){
			fa[rdc[i]]=u;
			dfs(rdc[i]);
			if(size[rdc[i]]>size[son[u]])
				son[u]=rdc[i];
			size[u]+=size[rdc[i]];
		}
}
void dfs2(int u,int t){
	id[u]=++tnt;
	top[u]=t;
	if(!son[u])return;
	dfs2(son[u],t);
	for(register int i=head[u];i;i=nxt[i])
		if(rdc[i]!=fa[u]&&rdc[i]!=son[u])
			dfs2(rdc[i],rdc[i]);
}
void pushdown(int u){
	if(tag[u]==-1)return;
	tag[sont[0][u]]=tag[sont[1][u]]=tag[u];
	tag[u]=-1;
}
void build(int &u,int l,int r){
	u=++tnt;
	if(l==r){
		tag[u]=0;return;
	}
	tag[u]=-1;
	build(sont[0][u],l,mid);build(sont[1][u],mid+1,r);
}
void pushtag(int u,int lr,int rr,int t,int l,int r){
	if(lr<=l&&r<=rr){tag[u]=t;return;}
	if(lr>r||rr<l)return;
	pushdown(u);
	pushtag(sont[0][u],lr,rr,t,l,mid);
	pushtag(sont[1][u],lr,rr,t,mid+1,r);
}
int query(int u,int x,int l,int r){
	if(tag[u]!=-1)return tag[u];
	return mid>=x?query(sont[0][u],x,l,mid):query(sont[1][u],x,mid+1,r);
}
void upmodify(int u){
	while(top[u]!=1){
		pushtag(rt,id[top[u]],id[u],0,1,n);
		u=fa[top[u]];
	}
	pushtag(rt,id[1],id[u],0,1,n);
}
int main()
{
	scanf("%d",&n);
	for(register int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	fa[1]=1;dfs(1);
	tnt=0;dfs2(1,1);
	tnt=0;build(rt,1,n);
	scanf("%d",&q);
	for(register int i=0,x,v;i<q;++i){
		scanf("%d%d",&x,&v);
		switch(x){
			case 1:{
				pushtag(rt,id[v],id[v]+size[v]-1,1,1,n);break;
			}
			case 2:{
				upmodify(v);break;
			}
			case 3:{
				printf("%d\n",query(rt,id[v],1,n));break;
			}
			default:{
				break;
			}
		}
	}
	return 0;
}