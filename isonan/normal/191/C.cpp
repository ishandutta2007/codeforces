#include <cstdio>

int head[100001],nxt[200001],b[200001],fa[100001][21],k,dep[100001],cnt[100001],n;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	fa[x][0]=f;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	dep[x]=dep[f]+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x);
}
int LCA(int x,int y){
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void getans(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getans(b[i],x),cnt[x]+=cnt[b[i]];
}
int main(){
	scanf("%d",&n);
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s);
	}
	dfs(1,0);
	int Q;
	scanf("%d",&Q);
	for(int i=1,x,y;i<=Q;i++){
		scanf("%d%d",&x,&y);
		++cnt[x];
		++cnt[y];
		cnt[LCA(x,y)]-=2;
	}
	getans(1,0);
	for(int i=1;i<n;i++){
		int x=b[(i<<1)-1],y=b[i<<1];
		if(fa[x][0]==y)printf("%d ",cnt[x]);
		else printf("%d ",cnt[y]);
	}
}