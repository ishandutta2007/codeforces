#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[55][55];
int dp[55][55][55][55],f[55][55][55][55];

inline int dfs(int lx,int ly,int rx,int ry)
{
	if(f[lx][ly][rx][ry]) return dp[lx][ly][rx][ry];
	if(lx==rx&&ly==ry) return s[lx][ly]=='#';
	for(int i=lx;i<rx;i++) dp[lx][ly][rx][ry]=min(dp[lx][ly][rx][ry],dfs(lx,ly,i,ry)+dfs(i+1,ly,rx,ry));
	for(int i=ly;i<ry;i++) dp[lx][ly][rx][ry]=min(dp[lx][ly][rx][ry],dfs(lx,ly,rx,i)+dfs(lx,i+1,rx,ry));
	f[lx][ly][rx][ry]=1;
	return dp[lx][ly][rx][ry];
}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=i;k<=n;k++) for(int l=j;l<=n;l++)
		dp[i][j][k][l]=max(k-i+1,l-j+1);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	dfs(1,1,n,n);
	cout<<dp[1][1][n][n];
	return 0;
}