#include <cstdio>
#include <vector>
#include <algorithm>

int n,m,K,head[150001],nxt[300001],b[300001],k;
int lson[8000001],rson[8000001],se[8000001],cnt,fa[150001][21],dep[150001],root[150001];
int u[150001],v[150001],lca[150001],Lift[150001],ind[150001],dfn[150001],mx[150001],now;
bool vis[150001];
std::vector<int>num[150001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int f){
	dfn[x]=++now;
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x);
	mx[x]=now;
}
int LCA(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=20;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int lift(int x,int k){
	if(k<0)return 0;
	for(int i=20;~i;--i)
		if((1<<i)<=k)k^=1<<i,x=fa[x][i];
	return x;
}
void add(int &pos,int l,int r,int e){
	if(!pos)pos=++cnt;
	++se[pos];
	if(l==r)return;
	if((l+r)>>1>=e)add(lson[pos],l,(l+r)>>1,e);
	else add(rson[pos],((l+r)>>1)+1,r,e);
}
int query(int pos,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[pos];
	return query(lson[pos],l,(l+r)>>1,el,er)+query(rson[pos],((l+r)>>1)+1,r,el,er);
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	se[a]+=se[b];
	lson[a]=merge(lson[a],lson[b]);
	rson[a]=merge(rson[a],rson[b]);
	return a;
}
long long ans;
void eval(int x,int i,int root){
	if(dep[x]<=dep[lca[i]])return;
	if(dep[x]-dep[lca[i]]>=K){
		int y=lift(x,K-1);
		ans+=se[root]-query(root,1,n,dfn[y],mx[y]);
		if(dfn[x]>dfn[u[i]]&&Lift[i])ans-=query(root,1,n,dfn[Lift[i]],mx[Lift[i]]);
	}
	else{
		if(dfn[x]>dfn[u[i]])return;
		int y=lift(v[i],(dep[x]+dep[v[i]]-(dep[lca[i]]<<1))-K);
		ans+=query(root,1,n,dfn[y],mx[y]);
	}
}
void getans(int x,int f){
	ind[x]=x;
	for(int i=0;i<(int)num[x].size();i++){
		eval(x,num[x][i],root[x]);
		add(root[x],1,n,dfn[u[num[x][i]]^v[num[x][i]]^x]);
	}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			getans(b[i],x);
			if(num[ind[x]].size()<num[ind[b[i]]].size())std::swap(ind[x],ind[b[i]]),std::swap(root[x],root[b[i]]);
			for(int j=0;j<num[ind[b[i]]].size();j++)eval(x,num[ind[b[i]]][j],root[x]);
			for(int j=0;j<num[ind[b[i]]].size();j++)num[ind[x]].push_back(num[ind[b[i]]][j]);
			root[x]=merge(root[x],root[b[i]]);
		}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	for(int i=1;i<=m;i++){
		scanf("%d%d",u+i,v+i);
		if(dfn[u[i]]>dfn[v[i]])std::swap(u[i],v[i]);
		lca[i]=LCA(u[i],v[i]);
		Lift[i]=lift(u[i],dep[u[i]]-dep[lca[i]]-1);
		num[u[i]].push_back(i);
		num[v[i]].push_back(i);
//		printf("%d %d %d %d\n",u[i],v[i],lca[i],Lift[i]);
	}
	getans(1,0);
	printf("%lld\n",ans);
}