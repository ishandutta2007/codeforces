#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e3+5;
int n,m,g[maxn][maxn];
bool vis[maxn][maxn];
int cnt=0,s[maxn*maxn];
const int dx[]={0,1,0,-1},dy[]={-1,0,1,0};
void dfs(int x,int y){
	vis[x][y]=1;
	s[cnt]++;
	for(int i=0;i<4;i++) if(!(g[x][y]>>i&1)){
		int vx=x+dx[i],vy=y+dy[i];
		if(!vis[vx][vy]) dfs(vx,vy);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) g[i][j]=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!vis[i][j]){
		cnt++;
		dfs(i,j);
	}
	sort(s+1,s+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++) printf("%d ",s[i]);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}