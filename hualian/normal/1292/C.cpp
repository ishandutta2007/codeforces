#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=3e3+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;vector<int>e[N];
int rt;
int dp[N][N];
int dis[N][N];
int sz[N][N];
void dfs(int x,int fa){
	dis[rt][x]=dis[rt][fa]+1;
	sz[rt][x]=1;
	for(int to:e[x])if(to!=fa)
		dfs(to,x),sz[rt][x]+=sz[rt][to];
}
struct node{int x,y;};
vector<node>had[N];
int ans;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n-1){
		int x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	rep(i,n){
		rt=i;dis[rt][0]=-1;
		dfs(rt,0);
	}
	rep(i,n)For(j,i,n)
		had[dis[i][j]].push_back(node{i,j});
	rep(len,n)for(node now:had[len]){
		int x=now.x,y=now.y,nx,ny;
		for(int to:e[x])if(dis[x][y]==dis[to][y]+1){
			nx=to;break;}
		for(int to:e[y])if(dis[x][y]==dis[x][to]+1){
			ny=to;break;}
		chmx(dp[x][y],dp[nx][y]+sz[nx][x]*(n-sz[y][ny]));
		chmx(dp[x][y],dp[x][ny]+sz[ny][y]*(n-sz[x][nx]));
		dp[y][x]=dp[x][y];
		chmx(ans,dp[x][y]);
	}cout<<ans<<endl;
	return 0;
}