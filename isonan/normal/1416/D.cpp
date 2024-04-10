#include <cstdio>
#include <algorithm>

int n,m,q,p[400001],qu[2][500001],cnt,T[400001],fa[19][400001];
int f[400001],dfn[400001],mx[400001],now,ord[400001];
int cmp(int a,int b){
	if(!a||!b)return a|b;
	return p[a]<p[b]?b:a;
}
int se[5000001];
int head[400001],nxt[800001],b[800001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int find(int x){return f[x]?f[x]=find(f[x]):x;}
struct point{
	int a,b,t;
}edg[300001];
void dfs(int x,int f){
	dfn[x]=++now;
	ord[now]=x;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
		}
	mx[x]=now;
}
void build(int root,int l,int r){
	if(l==r){
		if(ord[l]<=n)se[root]=ord[l];
		else se[root]=0;
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=cmp(se[root<<1],se[root<<1|1]);
}
int query(int root,int l,int r,int el,int er){
	if(!se[root])return 0;
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[root];
	return cmp(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
void update(int root,int l,int r,int e){
	if(l==r){
		se[root]=0;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e);
	else update(root<<1|1,((l+r)>>1)+1,r,e);
	se[root]=cmp(se[root<<1],se[root<<1|1]);
}
bool Cmp(point a,point b){
	return a.t>b.t;
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
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)p[i]=read(),T[i]=0x7f7f7f7f;
	cnt=n;
	for(int i=1;i<=m;i++)edg[i].a=read(),edg[i].b=read(),edg[i].t=q+1;
	for(int i=1;i<=q;i++){
		qu[0][i]=read();
		qu[1][i]=read();
		if(qu[0][i]==2){
			edg[qu[1][i]].t=i;
		}
	}
	std::sort(edg+1,edg+m+1,Cmp);
	for(int i=1;i<=m;i++){
		int u=find(edg[i].a),v=find(edg[i].b);
		if(u!=v){
			++cnt;
			T[cnt]=edg[i].t;
			f[u]=f[v]=cnt;
			fa[0][u]=fa[0][v]=cnt;
			push(cnt,u),push(cnt,v);
		}
	}
	for(int j=1;j<=18;j++)
		for(int i=1;i<=cnt;i++)
			fa[j][i]=fa[j-1][fa[j-1][i]];
	for(int i=1;i<=cnt;i++)
		if(!f[i])dfs(i,0);
	build(1,1,now);
	for(int i=1;i<=q;i++){
		if(qu[0][i]==1){
			int tem=qu[1][i];
			for(int j=18;~j;--j)
				if(T[fa[j][tem]]>=i)tem=fa[j][tem];
			int u=query(1,1,now,dfn[tem],mx[tem]);
			write(p[u]);
			putchar('\n');
			if(u)update(1,1,now,dfn[u]);
		}
	}
}