#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=524288;
const int M=998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n,i,m,t,j,qx[N*2],qy[N*2],r,x,y;
long long z;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char c[1005][1005];
int vis[1005][1005];
void dfs(int x,int y)
{
	if(vis[x][y]==0)
		return;
	vis[x][y]=0;
	if(c[x][y]==c[x-1][y])
		dfs(x-1,y);
	if(c[x][y]==c[x][y+1])
		dfs(x,y+1);
	if(c[x][y]==c[x+1][y])
		dfs(x+1,y);
	if(c[x][y]==c[x][y-1])
		dfs(x,y-1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&t);
	for(i=1;i<=n;++i)
	{
		scanf("%s",c[i]+1);
		for(j=1;j<=m;++j)
			vis[i][j]=-1;
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(c[i][j]==c[i-1][j]||c[i][j]==c[i][j-1]||c[i][j]==c[i+1][j]||c[i][j]==c[i][j+1])
				dfs(i,j);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(vis[i][j]==0)
			{
				qx[++r]=i;
				qy[r]=j;
			}
	for(i=1;i<=r;++i)
		for(j=0;j<4;++j)
		{
			int x=dx[j]+qx[i],y=dy[j]+qy[i];
			if(vis[x][y]==-1)
			{
				vis[x][y]=vis[qx[i]][qy[i]]+1;
				qx[++r]=x;
				qy[r]=y;
			}
		}
	while(t--)
	{
		scanf("%d %d %lld",&x,&y,&z);
		if(vis[x][y]==-1)
		{
			printf("%c\n",c[x][y]);
			continue;
		}
		if(z<=vis[x][y])
		{
			printf("%c\n",c[x][y]);
			continue;
		}
		else
			printf("%lld\n",(c[x][y]-'0')^(z&1)^(vis[x][y]&1));
	}
}