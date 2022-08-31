#include <cstdio>
#include <vector>

int st[1000001][21],start[500001],now,dep[500001];
int Log[1000001],dfn[500001],dn,mx[500001];
int n,m,con[2][500001],v[1000001];
int head[500001],nxt[1000001],b[1000001],k,a[500001],ord[500001],fa[500001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void dfs(int x,int f){
	start[x]=++now;
	dfn[x]=++dn;
	ord[dn]=x;
	fa[x]=f;
	dep[x]=dep[f]+1;
	st[now][0]=dep[x];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			a[b[i]]=a[x]^v[i];
			dfs(b[i],x);
			st[++now][0]=dep[x];
		}
	mx[x]=dn;
}
int dist(int x,int y){
	int ans=dep[x]+dep[y];
	x=start[x],y=start[y];
	if(x>y)std::swap(x,y);
	int k=Log[y-x+1];
	return ans-2*std::min(st[x][k],st[y-(1<<k)+1][k]);
}
struct diam{
	int u,v,dis;
	void add(int x){
		if(!x)return;
		if(!u)u=x;
		else if(!v){
			v=x;
			dis=dist(u,v);
		}
		else{
			int mx=std::max(dist(u,x),dist(v,x));
			if(mx>=dis){
				if(dist(u,x)==mx){
					dis=dist(u,x);
					v=x;
				}
				if(dist(v,x)==mx){
					dis=dist(v,x);
					u=x;
				}
			}
		}
	}
}se[2][4000001];
bool lazy[4000001];
void pushup(int root){
	for(int i=0;i<2;i++){
		se[i][root]=se[i][root<<1];
		se[i][root].add(se[i][root<<1|1].u);
		se[i][root].add(se[i][root<<1|1].v);
	}
}
void pushdown(int x){
	diam a=se[0][x];
	se[0][x]=se[1][x];
	se[1][x]=a;
	lazy[x]^=1;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1);
		pushdown(x<<1|1);
		lazy[x]=0;
	}
}
void build(int root,int l,int r){
	if(l==r){
		se[a[ord[l]]][root].add(ord[l]);
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
void change(int root,int l,int r,int el,int er){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root);
//	printf("changed %d %d %d %d %d %d\n",l,r,se[0][root].u,se[1][root].u,el,er);
		return;
	}
	spread(root);
	change(root<<1,l,(l+r)>>1,el,er);
	change(root<<1|1,((l+r)>>1)+1,r,el,er);
	pushup(root);
//	printf("update %d %d %d %d\n",l,r,se[0][root].u,se[0][root].v);
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
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		push(u,v,w);
		push(v,u,w);
		con[0][i]=u;
		con[1][i]=v;
	}
	dfs(1,0);
	m=read();
	for(int i=2;i<=now;i++)Log[i]=Log[i>>1]+1;
	for(int j=1;(1<<j)<=now;j++)
		for(int i=1;i+(1<<j)-1<=now;i++)
			st[i][j]=std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	build(1,1,n);
	for(int i=1;i<n;i++)if(fa[con[1][i]]==con[0][i])con[0][i]=con[1][i];
	for(int i=1,id;i<=m;i++){
		id=read();
		change(1,1,n,dfn[con[0][id]],mx[con[0][id]]);
		write(std::max(se[0][1].dis,se[1][1].dis));
		putchar('\n');
	}
}