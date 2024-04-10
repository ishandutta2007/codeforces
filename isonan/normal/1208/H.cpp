#include <cstdio>
#include <random>

std::mt19937 Rand(19260817);
int n,K;
int head[100001],nxt[200001],b[200001],k,s[100001];
int fa[100001],son[100001],top[100001],dfn[100001],down[100001],now,d[100001];
int root[2000001],lson[2000001],rson[2000001],size[2000001],key[2000001],pri[2000001];
int stk[2000001],Top,cnt;
void pushup(int x){size[x]=size[lson[x]]+size[rson[x]]+1;}
void split(int now,int &x,int &y,int v){
	if(!now)x=y=0;
	else{
		if(key[now]>=v)x=now,split(rson[now],rson[now],y,v);
		else y=now,split(lson[now],x,lson[now],v);
		pushup(now);
	}
}
void splits(int now,int &x,int &y,int s){
	if(!now)x=y=0;
	else{
//		printf("splits %d %d %d %d\n",now,lson[now],rson[now],s);
		if(size[lson[now]]+1<=s)x=now,splits(rson[now],rson[now],y,s-size[lson[now]]-1);
		else y=now,splits(lson[now],x,lson[now],s);
		pushup(now);
	}
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	if(pri[a]<pri[b]){
		rson[a]=merge(rson[a],b);
		pushup(a);
		return a;
	}
	else{
		lson[b]=merge(a,lson[b]);
		pushup(b);
		return b;
	}
}
int getf(int x,int offset,int d,int siz){
	if(!x)return (offset<<1)-d;
	int ord=siz+size[lson[x]]+1;
	if(key[x]>=((ord+offset)<<1)-d-1&&((ord+offset)<<1)-d-1>=offset-d)
		return std::max(getf(rson[x],offset,d,ord),std::min(d,std::min(key[x],((ord+offset)<<1)-d)));
	else return getf(lson[x],offset,d,siz);
}
int Newnode(int x){
	int u=(Top)?stk[Top--]:++cnt;
	key[u]=x;
	pri[u]=Rand();
	size[u]=1;
	lson[u]=rson[u]=0;
	return u;
}
void Delnode(int x){
	stk[++Top]=x;
}
void debug(int x){
	if(!x)return;
	debug(lson[x]);
	printf("%d ",key[x]);
	debug(rson[x]);
}
void add(int &rt,int x){
	int u=Newnode(x),t1,t2;
	split(rt,t1,t2,x);
	rt=merge(t1,merge(u,t2));
//	printf("Add %d %d\n",rt,size[rt]);
}
void del(int &rt,int x){
	int t1,t2,t3;
	split(rt,t1,t2,x);
//	printf("%d %d\n",t1,t2);
	splits(t1,t1,t3,size[t1]-1);
	rt=merge(t1,t2);
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f){
	fa[x]=f;
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs1(b[i],x);
			size[x]+=size[b[i]];
			if(size[son[x]]<size[b[i]])son[x]=b[i];
		}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++now;
	if(son[x])dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=son[x]&&b[i]!=fa[x])
			dfs2(b[i],b[i]);
	down[x]=son[x]?down[son[x]]:x;
}
struct info{
	int L,R;
	int eval(const int &x)const{return (L>R)?L:std::max(L,std::min(R,x));}
}se[1000001];
info merge(const info &a,const info &b){
	if(a.L>a.R)return (info){b.eval(a.L),b.eval(a.L)};
	else if(b.L>b.R)return b;
	else{
		info now=(info){std::max(a.L,b.L),std::min(a.R,b.R)};
		if(now.L>now.R)now=(info){b.eval(a.L),-0x7f7f7f7f};
		return now;
	}
}
void update(int root,int l,int r,int e,const info &x){
	if(l==r){
		se[root]=x;
//		printf("%d %d %d\n",e,x.L,x.R);
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	se[root]=merge(se[root<<1|1],se[root<<1]);
}
info query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return (info){-0x7f7f7f7f,0x7f7f7f7f};
	if(el<=l&&er>=r)return se[root];
	return merge(query(root<<1|1,((l+r)>>1)+1,r,el,er),query(root<<1,l,(l+r)>>1,el,er));
}
void UpDaTe(int x){
	if(d[x]&&x==12170){
//		puts("debug");
//		debug(root[x]);putchar('\n');
//		printf("%d %d %d\n",x,getf(root[x],0,d[x],0),getf(root[x],1,d[x],0));
	}
	update(1,1,n,dfn[x],
		(d[x])?(info){getf(root[x],0,d[x],0),getf(root[x],1,d[x],0)}:
		((s[x]==1)?(info){0x7f7f7f7f,0x7f7f7f7f}:(info){-0x7f7f7f7f,-0x7f7f7f7f}));
}
void build(int x){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x]){
			build(b[i]);
			if(b[i]!=son[x]){
				int f=query(1,1,n,dfn[b[i]],dfn[down[b[i]]]).eval(0);
				add(root[x],f);
			}
		}
	UpDaTe(x);
}
void change(int x){
	while(x){
		int f=query(1,1,n,dfn[top[x]],dfn[down[x]]).eval(0);
		if(fa[top[x]])del(root[fa[top[x]]],f);
		UpDaTe(x);
		f=query(1,1,n,dfn[top[x]],dfn[down[x]]).eval(0);
		if(fa[top[x]])add(root[fa[top[x]]],f);
		x=fa[top[x]];
	}
}
void DFS(int x){
	printf("%d %d %d\n",x,fa[x],s[x]);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=fa[x]){
			DFS(b[i]);
		}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u),++d[u],++d[v];
	for(int i=2;i<=n;i++)--d[i];
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	dfs1(1,0);
	dfs2(1,1);
	build(1);
//	for(int i=1;i<=n;i++)printf("%d ",d[i]);putchar('\n');
//	for(int i=1;i<=n;i++)printf("%d ",query(1,1,n,dfn[i],dfn[down[i]]).eval(0));putchar('\n');
//	freopen("CON","r",stdin);
//	for(int v;;){
//		scanf("%d",&v);
//		printf("%d\n",query(1,1,n,dfn[v],dfn[down[v]]).eval(0));
//	}
	int q;
	scanf("%d",&q);
	for(int i=1,opt,t1,t2;i<=q;i++){
		scanf("%d",&opt);
//		printf("*%d\n",lson[2]);
		if(opt==1){
			scanf("%d",&t1);
//			DFS(t1);
			printf("%d\n",query(1,1,n,dfn[t1],dfn[down[t1]]).eval(0)>=K);
		}
		else if(opt==2){
			scanf("%d%d",&t1,&t2);
			s[t1]=t2;
			change(t1);
		}
		else{
			scanf("%d",&K);
		}
	}
}