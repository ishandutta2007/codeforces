#include <cstdio>
#include <vector>
#include <algorithm>

int n,m;
int head[100001],nxt[200001],b[200001],k;
int sum[100001];
int f[100001];
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
std::vector<std::pair<int,int> >vec;
int dep[100001],fa[100001][21];
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=20;++i)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
		}
}
int LCA(int x,int y){
	if(x==y)return x;
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=20;~i;--i)
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;~i;--i)
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
		return fa[x][0];
}
void dfs2(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			sum[b[i]]+=sum[x];
			dfs2(b[i],x);
		}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		int du=find(u),dv=find(v);
		if(du!=dv){
			push(u,v),push(v,u);
			f[du]=dv;
			// printf("**%d %d\n",u,v);
		}
		else{
			vec.push_back(std::make_pair(u,v));
		}
	}
	dfs(1,0);
	for(auto v:vec){
		int x=v.first,y=v.second,l=LCA(x,y);
		if(x==l||y==l){
			int tem=(x^y^l);
			for(int i=20;~i;--i)
				if(dep[fa[tem][i]]>dep[l])tem=fa[tem][i];
			++sum[tem];
			--sum[x^y^l];
		}
		else{
			++sum[1];
			--sum[x],--sum[y];
		}
		// sum[fa[LCA(v.first,v.second)][0]]-=2;
		// printf("%d %d %d\n",v.first,v.second,LCA(v.first,v.second));
	}
	dfs2(1,0);
	// for(int i=1;i<=n;++i)printf("%d ",sum[i]);putchar('\n');
	for(int i=1;i<=n;++i)printf("%d",sum[i]==0);
}