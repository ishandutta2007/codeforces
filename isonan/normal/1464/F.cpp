#include <cstdio>
#include <set>
#include <algorithm>

int n,q,head[200001],nxt[400001],b[400001],k;
int fa[200001][21],dep[200001],dfn[200001],now,mx[200001];
std::multiset<int>dfns;
std::multiset<std::pair<int,int> >set;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	dfn[x]=++now;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
		}
	mx[x]=now;
}
int LCA(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dist(int x,int y){
	return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);
}
struct info{
	int u,v,d;
	void add(int x){
		if(!x)return;
		if(!u)return (void)(u=x);
		if(!v)return (void)(v=x,d=dist(u,v));
		int d1=dist(u,x),d2=dist(v,x);
		if(d1>d||d2>d){
			if(d1>=d2)v=x,d=d1;
			else u=x,d=d2;
		}
	}
}se[2000001];
info merge(info a,info b){
	a.add(b.u);
	a.add(b.v);
	return a;
}
int Cnt[2000001];
void update(int root,int l,int r,int e,info x){
	if(l==r){
		se[root]=x;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	se[root]=se[root<<1];
	se[root].add(se[root<<1|1].u);
	se[root].add(se[root<<1|1].v);
}
info Query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return (info){0,0,0};
	if(el<=l&&er>=r)return se[root];
	return merge(Query(root<<1,l,(l+r)>>1,el,er),Query(root<<1|1,((l+r)>>1)+1,r,el,er));
}
void ADD(int x){
	if(!Cnt[x])update(1,1,n,dfn[x],(info){x,x,0});
	++Cnt[x];
}
void DEL(int x){
	--Cnt[x];
	if(!Cnt[x])update(1,1,n,dfn[x],(info){0,0,0});
}
int se2[2000001];
void add(int root,int l,int r,int e,int y){
	if(l==r){
		se2[root]+=y;
		return;
	}
	if((l+r)>>1>=e)add(root<<1,l,(l+r)>>1,e,y);
	else add(root<<1|1,((l+r)>>1)+1,r,e,y);
	se2[root]=se2[root<<1]+se2[root<<1|1];
}
int query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se2[root];
	return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
int P;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	for(int i=1,opt,t1,t2;i<=q;i++){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&t1,&t2);
			if(t1>t2)std::swap(t1,t2);
			int u=LCA(t1,t2);
			add(1,1,n,dfn[t1],1);
			add(1,1,n,dfn[t2],1);
			add(1,1,n,dfn[u],-1);
			dfns.insert(dfn[u]);
			set.insert(std::make_pair(dep[u],u));
			++P;
			ADD(u);
		}
		else if(opt==2){
			scanf("%d%d",&t1,&t2);
			if(t1>t2)std::swap(t1,t2);
			int u=LCA(t1,t2);
			add(1,1,n,dfn[t1],-1);
			add(1,1,n,dfn[t2],-1);
			add(1,1,n,dfn[u],1);
			dfns.erase(dfns.find(dfn[u]));
			set.erase(set.find(std::make_pair(dep[u],u)));
			--P;
			DEL(u);
		}
		else{
			scanf("%d",&t1);
			int p=set.rbegin()->second,l=std::min(t1,dep[p]-1);
			for(int i=20;~i;--i)
				if(l>=1<<i)l-=1<<i,p=fa[p][i];
			int x=p;
			l=std::min(t1,dep[p]-1);
			for(int i=20;~i;--i)
				if(l>=1<<i)l-=1<<i,x=fa[x][i];
			if(query(1,1,n,dfn[x],mx[x])<P){
				puts("No");
				continue;
			}
			info now=Query(1,1,n,dfn[x],mx[x]);
			bool bb=1;
			bb&=(now.u&&dist(now.u,p)<=t1);
			bb&=(now.v&&dist(now.v,p)<=t1); 
			if(bb)puts("Yes");
			else puts("No");
		}
	}
}