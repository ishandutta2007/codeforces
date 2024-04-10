#include <cstdio>
#include <vector>
#include <algorithm>

const int P=1000000007;
std::vector<std::pair<int,int> >edg[500001];
int head[1500001],nxt[3000001],b[3000001],k,n,fa[1500001][22],dep[1500001],_mul[500001];
int f[1500001],g[1500001],Nxt[1500001];
int c1[1500001],c2[1500001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
} 
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=1;i<=21;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x);
}
int LCA(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=21;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=21;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void addedge(int u,int v){
	int lca=LCA(u,v);
	++c1[u],++c2[v];
	for(int i=21;~i;--i)if(dep[fa[u][i]]>dep[lca])u=fa[u][i];
	for(int i=21;~i;--i)if(dep[fa[v][i]]>dep[lca])v=fa[v][i];
	if(u!=lca&&v!=lca)edg[lca].push_back(std::make_pair(u,v));
	--c1[u],--c2[v];
}
void getsum(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getsum(b[i],x),c1[x]+=c1[b[i]],c2[x]+=c2[b[i]];
}
int find(int x){return f[x]?f[x]=find(f[x]):x;}
int main(){
	scanf("%d",&n);
	_mul[0]=_mul[1]=1;
	for(int i=2;i<=n;i++)_mul[i]=1ll*_mul[i-1]*i%P;
	for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),push(u,v),push(v,u);
	for(int i=1;i<=n;i++)push(i,i+n),push(i,i+(n<<1));
	dfs(1,0);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		if(a)addedge(a+n,i+(n<<1));
	}
	getsum(1,0);
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=nxt[j])
			if(b[j]!=fa[i][0]){
				if(c1[b[j]])edg[i].push_back(std::make_pair(b[j],fa[i][0]));
				if(c2[b[j]])edg[i].push_back(std::make_pair(fa[i][0],b[j]));
			}
		for(int j=0;j<edg[i].size();j++){
			int u=edg[i][j].first,v=edg[i][j].second;
//			printf("%d %d %d\n",i,u,v);
			if(Nxt[u]&&Nxt[u]!=v){
				puts("0");
				return 0;
			}
			Nxt[u]=v;
			u=find(u);
			v=find(v);
			if(u!=v)f[u]=v;
		}
		int cnt=0;
		for(int j=head[i];j;j=nxt[j]){
//			printf("%d %d %d\n",b[j],f[b[j]],nxt[b[j]]);
			if(!f[b[j]]&&Nxt[b[j]]){
				puts("0");
				return 0;
			}
			if(!f[b[j]])++cnt;
		}
		if(cnt>1&&find(i+n)==find(i+(n<<1))){
			puts("0");
			return 0;
		}
		ans=1ll*ans*_mul[std::max(0,cnt-2)]%P;
		for(int j=head[i];j;j=nxt[j])
			f[b[j]]=Nxt[b[j]]=0;
	}
	printf("%d\n",ans);
}