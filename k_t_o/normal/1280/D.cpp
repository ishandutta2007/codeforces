#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005;
struct atom{
	int c;ll s;
	inline atom operator+(const atom&rhs)const{return (atom){c+rhs.c,s+rhs.s};}
	inline bool operator<(const atom&rhs)const{return c==rhs.c?s<rhs.s:c<rhs.c;}
}f[N][N];
const atom E=(atom){0,-(1ll<<60)};
int T,n,m,i,j,b[N],w[N],x,y,sz[N];
vector<int>e[N];
void dfs(int x,int fa){
	sz[x]=1;f[x][0]=(atom){0,w[x]-b[x]};
	for(int y:e[x])if(y!=fa){
		dfs(y,x);
		static atom g[N];
		for(i=0;i<sz[x]+sz[y];++i)g[i]=E;
		for(i=0;i<sz[x];++i)for(j=0;j<=sz[y];++j)g[i+j]=max(g[i+j],f[x][i]+f[y][j]);
		for(i=0;i<sz[x]+sz[y];++i)f[x][i]=g[i];sz[x]+=sz[y];
	}
	f[x][sz[x]]=E;
	for(i=sz[x]-1;i>=0;--i)f[x][i+1]=max(f[x][i+1],(atom){f[x][i].c+(f[x][i].s>0),0});
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)e[i].clear();
		for(i=1;i<=n;++i)scanf("%d",b+i);
		for(i=1;i<=n;++i)scanf("%d",w+i);
		for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
		dfs(1,0);
		printf("%d\n",f[1][m-1].c+(f[1][m-1].s>0));
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005;
struct atom{
	int c;ll s;
	inline atom operator+(const atom&rhs)const{return (atom){c+rhs.c,s+rhs.s};}
	inline bool operator<(const atom&rhs)const{return c==rhs.c?s<rhs.s:c<rhs.c;}
}f[N][N];
const atom E=(atom){0,-(1ll<<60)};
int T,n,m,i,j,b[N],w[N],x,y,sz[N];
vector<int>e[N];
void dfs(int x,int fa){
	sz[x]=1;f[x][0]=(atom){0,w[x]-b[x]};
	for(int y:e[x])if(y!=fa){
		dfs(y,x);
		static atom g[N];
		for(i=0;i<sz[x]+sz[y];++i)g[i]=E;
		for(i=0;i<sz[x];++i)for(j=0;j<=sz[y];++j)g[i+j]=max(g[i+j],f[x][i]+f[y][j]);
		for(i=0;i<sz[x]+sz[y];++i)f[x][i]=g[i];sz[x]+=sz[y];
	}
	f[x][sz[x]]=E;
	if(fa)for(i=sz[x]-1;i>=0;--i)f[x][i+1]=max(f[x][i+1],(atom){f[x][i].c+(f[x][i].s>0),0});
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)e[i].clear();
		for(i=1;i<=n;++i)scanf("%d",b+i);
		for(i=1;i<=n;++i)scanf("%d",w+i);
		for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
		dfs(1,0);
		printf("%d\n",f[1][m-1].c+(f[1][m-1].s>0));
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005;
struct atom{
	int c;ll s;
	inline atom operator+(const atom&rhs)const{return (atom){c+rhs.c,s+rhs.s};}
	inline bool operator<(const atom&rhs)const{return c==rhs.c?s<rhs.s:c<rhs.c;}
}f[N][N];
const atom E=(atom){0,-(1ll<<60)};
int T,n,m,i,j,b[N],w[N],x,y,sz[N];
vector<int>e[N];
void dfs(int x,int fa){
	sz[x]=1;f[x][0]=(atom){0,w[x]-b[x]};
	for(int y:e[x])if(y!=fa){
		dfs(y,x);
		static atom g[N];
		for(i=0;i<sz[x]+sz[y];++i)g[i]=E;
		for(i=0;i<sz[x];++i)for(j=0;j<=sz[y];++j)g[i+j]=max(g[i+j],f[x][i]+f[y][j]);
		for(i=0;i<sz[x]+sz[y];++i)f[x][i]=g[i];sz[x]+=sz[y];
	}
	f[x][sz[x]]=E;
	if(fa)for(i=sz[x]-1;i>=0;--i)f[x][i+1]=max(f[x][i+1],(atom){f[x][i].c+(f[x][i].s>0),0});
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)e[i].clear();
		for(i=1;i<=n;++i)scanf("%d",b+i);
		for(i=1;i<=n;++i)scanf("%d",w+i);
		for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
		dfs(1,0);
		printf("%d\n",f[1][m-1].c+(f[1][m-1].s>0));
	}
	return 0;
}
*/