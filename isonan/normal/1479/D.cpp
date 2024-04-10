#include <cstdio>
#include <vector>
#include <random>
#include <ctime>

int n,q,a[300001];
int head[300001],nxt[600001],b[600001],k;
int u[300001],v[300001],l[300001],r[300001],dfn[300001],mx[300001],now,lca[300001];
long long c[300001],Xor[300001];
int ans[300001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
std::vector<int>que[3000001],vec[300001];
void update(int ind,long long val){
	for(;ind<=n;ind+=ind&-ind)c[ind]^=val;
}
long long query(int ind){
	long long tot=0;
	for(;ind;ind-=ind&-ind)tot^=c[ind];
	return tot;
}
void add(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		que[root].push_back(x);
		return;
	}
	add(root<<1,l,(l+r)>>1,el,er,x);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
int fa[300001][21],dep[300001];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	dfn[x]=++now;
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
void solve(int root,int l,int r){
	for(int i=l;i<=r;++i)
		for(int j=0;j<vec[i].size();++j){
			int u=vec[i][j];
			update(dfn[u],Xor[i]),update(mx[u]+1,Xor[i]);
		}
	for(int i=0;i<que[root].size();++i){
		int v=que[root][i];
		if(ans[v])continue;
		long long Val=query(dfn[::v[v]])^query(dfn[u[v]]);
		if(a[lca[v]]>=l&&a[lca[v]]<=r)Val^=Xor[a[lca[v]]];
		if(Val){
			if(l==r)ans[v]=l;
			else que[root<<1].push_back(v),que[root<<1|1].push_back(v);
		}
	}
	for(int i=l;i<=r;++i)
		for(int j=0;j<vec[i].size();++j){
			int u=vec[i][j];
			update(dfn[u],Xor[i]),update(mx[u]+1,Xor[i]);
		}
	if(l==r)return;
	solve(root<<1,l,(l+r)>>1);
	solve(root<<1|1,((l+r)>>1)+1,r);
}
int main(){
	std::mt19937 rnd(time(0));
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i),vec[a[i]].push_back(i);
	for(int i=1;i<=n;i++)Xor[i]=1ll*rnd()*rnd();
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d%d",u+i,v+i,l+i,r+i);
		lca[i]=LCA(u[i],v[i]);
		add(1,1,n,l[i],r[i],i);
	}
	solve(1,1,n);
	for(int i=1;i<=q;i++)if(!ans[i])puts("-1");else printf("%d\n",ans[i]);
}