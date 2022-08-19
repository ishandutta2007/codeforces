#include <cstdio>
#include <cstring>
#include <algorithm>

int n,q,head[200001],nxt[400001],b[400001],k,fa[200001][21],dep[200001],dfn[200001],now;
void push(int s,int t){
//	printf("push %d %d\n",s,t);
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void init(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=20;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)init(b[i],x);
}
int LCA(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);}
int ans[200001],num[400001],top,v[200001],stk[200001],t[200001],ord[200001];
int que[200001];
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void upd(int u,int v){
	if(u){
//		printf("upd %d %d\n",u,v);
		int dist=(dis(u,v)+::v[u]-1)/::v[u];
		if(dist<t[v]||(dist==t[v]&&ord[u]<ord[ans[v]]))ans[v]=u,t[v]=dist;
	}
}
void dfs1(int x){
	for(int i=head[x];i;i=nxt[i])
		dfs1(b[i]),upd(ans[b[i]],x);
}
void dfs2(int x){
	for(int i=head[x];i;i=nxt[i])
		upd(ans[x],b[i]),dfs2(b[i]);
}
void del(int x){
	for(int i=head[x];i;i=nxt[i])
		del(b[i]);
	head[x]=0;
	ans[x]=0;
	t[x]=0x7f7f7f7f;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	init(1,0);
	memset(head,0,sizeof head);
	memset(t,0x7f7f7f7f,sizeof t);
	k=0;
	scanf("%d",&q);
	for(int i=1,l1,l2,t1,t2;i<=q;i++){
		scanf("%d%d",&l1,&l2);
		top=0;
		for(int j=1;j<=l1;j++){
			scanf("%d%d",&t1,&t2);
			ans[t1]=t1;
			ord[t1]=j;
			v[t1]=t2;
			t[t1]=0;
			num[++top]=t1;
		}
		for(int j=1;j<=l2;j++)scanf("%d",num+(j+l1)),que[j]=num[j+l1];
		l1+=l2;
		std::sort(num+1,num+l1+1,cmp);
		top=0;
		stk[++top]=1;
		for(int i=1;i<=l1;i++){
			int lca=LCA(stk[top],num[i]);
			while(top>1&&dep[stk[top-1]]>=dep[lca])push(stk[top-1],stk[top]),--top;
			if(stk[top]!=lca)push(lca,stk[top]);
			stk[top]=lca;
			if(lca!=num[i])stk[++top]=num[i];
		}
		for(int i=1;i<top;i++)push(stk[i],stk[i+1]);
		dfs1(1);
		dfs2(1);
//		putchar('*');
		for(int i=1;i<=l2;i++)printf("%d ",ord[ans[que[i]]]);putchar('\n');
		del(1);
		k=0;
	}
}