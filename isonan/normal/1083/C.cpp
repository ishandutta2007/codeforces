#include <cstdio>
#include <algorithm>


int fa[200001][21],dep[200001],n,head[200001],nxt[400001],b[200001],k,p[4],a[200001],pos[200001],q,longest,F[200001],dfn[200001],mx[200001],now;
struct point{int u,v;operator int(){return u;}}se[800001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	fa[x][0]=f;
	for(int i=1;i<=18;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	dep[x]=dep[f]+1;
	F[x]=1;
	dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i]){
		dfs(b[i],x);
		longest=std::max(longest,F[b[i]]+F[x]);
		F[x]=std::max(F[x],F[b[i]]+1);
	}
	mx[x]=now;
}
bool insubtree(int x,int y){return dfn[x]>=dfn[y]&&dfn[x]<=mx[y];}
int LCA(int x,int y){
    if(dep[x]<dep[y])x^=y^=x^=y;
    for(int i=18;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
    if(x==y)return x;
    for(int i=18;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
bool InPath(int u,int v,int x){
	return (insubtree(u,x)||insubtree(v,x))&&insubtree(x,LCA(u,v));
}
point merge(point a,point b){
	if((!~a)||(!~b))return (point){-1,-1};
	if(!a)return b;
	if(!b)return a;
	p[0]=a.u;
	p[1]=a.v;
	p[2]=b.u;
	p[3]=b.v;
//	printf("%d %d %d %d\n",p[0],p[1],p[2],p[3]);
	if(InPath(p[0],p[1],p[2])&&InPath(p[0],p[1],p[3]))return (point){p[0],p[1]};
	if(InPath(p[0],p[2],p[1])&&InPath(p[0],p[2],p[3]))return (point){p[0],p[2]};
	if(InPath(p[0],p[3],p[2])&&InPath(p[0],p[3],p[1]))return (point){p[0],p[3]};
	if(InPath(p[1],p[2],p[0])&&InPath(p[1],p[2],p[3]))return (point){p[1],p[2]};
	if(InPath(p[1],p[3],p[0])&&InPath(p[1],p[3],p[2]))return (point){p[1],p[3]};
	if(InPath(p[2],p[3],p[0])&&InPath(p[2],p[3],p[1]))return (point){p[2],p[3]};
	return (point){-1,-1};
}
void build(int root,int l,int r){
	if(l==r){
		se[root]=(point){pos[l],pos[l]};
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=merge(se[root<<1],se[root<<1|1]);
}
void change(int root,int l,int r,int e){
	if(l==r){
		se[root]=(point){pos[l],pos[l]};
		return;
	}
	if(((l+r)>>1)>=e)change(root<<1,l,(l+r)>>1,e);
	else change(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=merge(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,const point &pre){
//	printf("query %d %d %d %d\n",root,l,r,merge(se[root<<1],pre));
	if(l==r)return (~merge(se[root],pre))?l:l-1;
	if(~merge(se[root<<1],pre))return query(root<<1|1,((l+r)>>1)+1,r,merge(pre,se[root<<1]));
	else return query(root<<1,l,(l+r)>>1,pre);
}
void dfs(int root,int l,int r){
	printf("%d %d %d %d %d\n",root,l,r,se[root].u,se[root].v);
	if(l==r)return;
	dfs(root<<1,l,(l+r)>>1);
	dfs(root<<1|1,((l+r)>>1)+1,r);
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)pos[a[i]=read()]=i;
	for(int i=2,tem;i<=n;i++)push(read(),i);
//	putchar('*');
	dfs(1,0);
//	printf("*%d\n",longest);
	q=read();
	build(1,0,longest-1);
	for(int i=1,opt,x,y;i<=q;i++){
		opt=read();
		if(opt==1){
			x=read(),y=read();
			std::swap(a[x],a[y]);
			std::swap(pos[a[x]],pos[a[y]]);
			if(a[x]<longest)change(1,0,longest-1,a[x]);
			if(a[y]<longest)change(1,0,longest-1,a[y]);
		}
		else{
			write(query(1,0,longest-1,(point){0,0})+1);
			putchar('\n');
		}
//		dfs(1,0,n-1);
	}
}