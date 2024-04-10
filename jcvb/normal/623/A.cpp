#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#define cl(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
void gn(int &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
void gn(ll &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
int mo=1000000007;
int inf=1061109567;
db eps=1e-6;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#define x1 x192837465
#define x2 x123456789
#define y1 y192837465
#define y2 y123456789
int g[555][555];
int n,m;

int vis[555]={0};
int col[555];
int deg[555];
void dfs(int u){
	vis[u]=1;
	for (int i=1;i<=n;i++)if(g[u][i] && !vis[i]){
		col[i]=col[u]^1;
		dfs(i);
	}
}
int main()
{
	gn(n);gn(m);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)g[i][j]=g[j][i]=1;
	while(m--){
		int x,y;
		gn(x);gn(y);
		g[x][y]=0;
		g[y][x]=0;
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)if(g[i][j])deg[i]++,deg[j]++;
	for (int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)if(g[i][j] && col[i]==col[j]){
			printf("No\n");
			return 0;
		}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)if(!g[i][j] && deg[i] && deg[j] && col[i]!=col[j]){
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	for (int i=1;i<=n;i++){
		if(deg[i]==0)putchar('b');
		else if(col[i]==0)putchar('a');
		else putchar('c');
	}
	putchar('\n');
	return 0;
}