#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int p=1e9+7;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,cnt;
struct edge{
	int pre,to;
}e[2*N];int last[N];
inline void add(int x,int y){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	last[x]=cnt;
}
inline int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
int fa[N][20];
int dep[N];
void dfs(int x,int F){
	dep[x]=dep[F]+1;
	fa[x][0]=F;
	for(int i=1;i<=10;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=last[x];i;i=e[i].pre){
		int to=e[i].to;if(to==F)continue;
		dfs(to,x);
	}
}
inline int LCA(int x,int y){
	if(dep[y]>dep[x])swap(x,y);
	for(int i=10;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=10;i>=0;i--){
		if(fa[x][i]==fa[y][i])continue;
		x=fa[x][i],y=fa[y][i];
	}return fa[x][0];
}
int dp[N][N];
int ans;
signed main(){
	n=read();dep[0]=-1;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++)dp[0][i]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		dp[i][j]=(dp[i-1][j]+dp[i][j-1])*inv(2)%p;
	}
	for(int i=1;i<=n;i++){
		dfs(i,0);
		for(int x=1;x<=n;x++)for(int y=1;y<x;y++){
			int lca=LCA(x,y);
			ans=(ans+dp[dep[x]-dep[lca]][dep[y]-dep[lca]])%p;
		}
	}
	cout<<ans*inv(n)%p<<endl;
	return 0;
}