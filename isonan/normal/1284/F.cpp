#include <cstdio>
#include <algorithm>

int ch[250001][2],mn[250001],mx[250001],fa[250001];
bool lazy[250001];
bool son(int x){return ch[fa[x]][1]==x;}
bool isroot(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
void pushup(int x){
	mn[x]=mn[ch[x][0]]?mn[ch[x][0]]:x;
	mx[x]=mx[ch[x][1]]?mx[ch[x][1]]:x;
}
void Rotate(int x){
	int faz=fa[x],fazz=fa[faz],g=son(x);
	fa[x]=fazz;
	if(!isroot(faz))ch[fazz][son(faz)]=x;
	fa[ch[x][!g]]=faz;
	ch[faz][g]=ch[x][!g];
	ch[x][!g]=faz;
	fa[faz]=x;
	pushup(faz);
	pushup(x);
}
void pushdown(int x){
	if(!x)return;
	lazy[x]^=1;
	std::swap(ch[x][0],ch[x][1]);
	std::swap(mn[x],mx[x]);
}
void spread(int x){if(lazy[x])pushdown(ch[x][0]),pushdown(ch[x][1]),lazy[x]=0;}
void clear(int x){
	if(!isroot(x))clear(fa[x]);
	spread(x);
}
void splay(int x){
	clear(x);
	while(!isroot(x)){
		if(!isroot(fa[x]))
			if(son(x)^son(fa[x]))Rotate(x);
			else Rotate(fa[x]);
		Rotate(x);
	}
}
void access(int x){
	for(int y=0;x;y=x,x=fa[x])
		splay(x),ch[x][1]=y,pushup(x);
}
void mroot(int x){
	access(x);
	splay(x);
	pushdown(x);
}
void split(int x,int y){
	mroot(x);
	access(y);
	splay(y);
}
void link(int x,int y){
	mroot(x);
	fa[x]=y;
}
void cut(int x,int y){
	split(x,y);
	ch[y][0]=fa[x]=0;
	pushup(y);
}
int head[250001],nxt[500001],b[500001],k,dfn[250001],end[250001],now,n;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x);
	end[x]=now;
}
bool in(int x,int y){return dfn[x]>=dfn[y]&&dfn[x]<=end[y];}
void getedge(int x,int c1,int c2){
	spread(x);
	if(ch[x][0]&&in(mx[ch[x][0]],c1)^in(x,c1)){
		printf("%d %d %d %d\n",c1,c2,x,mx[ch[x][0]]);
		cut(x,mx[ch[x][0]]);
		link(c1,c2);
		return;
	}
	if(ch[x][1]&&in(mn[ch[x][1]],c1)^in(x,c1)){
		printf("%d %d %d %d\n",c1,c2,x,mn[ch[x][1]]);
		cut(x,mn[ch[x][1]]);
		link(c1,c2);
		return;
	}
	if(ch[x][0]&&in(mn[ch[x][0]],c1)^in(x,c1))getedge(ch[x][0],c1,c2);
	else getedge(ch[x][1],c1,c2);
}
void dfs(int x){
	if(!x)return;
	spread(x);
	dfs(ch[x][0]);
	printf("%d ",x);
	dfs(ch[x][1]);
}
void getans(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getans(b[i],x);
	if(f){
		split(x,f);
//	for(int i=1;i<=n;i++)printf("%d %d %d %d %d %d\n",i,fa[i],ch[i][0],ch[i][1],mn[i],mx[i]);
//		putchar('*');
//		dfs(f);putchar('\n');
		getedge(f,x,f);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	dfs(1,0);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		link(u,v);
	}
//	for(int i=1;i<=n;i++)printf("%d %d %d %d %d %d\n",i,fa[i],ch[i][0],ch[i][1],mn[i],mx[i]);
	printf("%d\n",n-1);
	getans(1,0);
}