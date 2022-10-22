#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
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

int n,m,K,mp[maxn][maxn],f[45][maxn][maxn];
bool vis[45][maxn][maxn],v[45];
struct node{int x,y;};
queue <node> q;
vector <node> vec[45];

const int kx[4]={0,0,1,-1};
const int ky[4]={-1,1,0,0};

int main()
{
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		mp[i][j]=read(),vec[mp[i][j]].push_back((node){i,j});
	for(int k=1;k<=K;k++)
	{
		for(int i=1;i<=40;i++) v[i]=0; v[k]=1;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
			if(mp[i][j]==k) q.push((node){i,j}),vis[k][i][j]=1;
		while(!q.empty())
		{
			node u=q.front(); q.pop();
			int col=mp[u.x][u.y];
			
			if(v[col]==0)
			{
				v[col]=1;
				for(int i=0;i<vec[col].size();i++)
				{
					node v=vec[col][i];
					if(vis[k][v.x][v.y]) continue;
					f[k][v.x][v.y]=f[k][u.x][u.y]+1;
					q.push((node){v.x,v.y}); vis[k][v.x][v.y]=1;
				}
			}
			
			for(int z=0;z<=3;z++)
			{
				int tx=u.x+kx[z],ty=u.y+ky[z];
				if(vis[k][tx][ty]||tx<=0||tx>n||ty<=0||ty>m) continue;
				f[k][tx][ty]=f[k][u.x][u.y]+1; vis[k][tx][ty]=1;
				q.push((node){tx,ty});
			}
		}
	}
	
	//cout<<f[3][3][8]<<endl;
	int Q=read();
	while(Q--)
	{
		int x=read(),y=read(),X=read(),Y=read();
		if(mp[x][y]==mp[X][Y])
		{
			if(x==X&&y==Y) puts("0");
			else puts("1");
		}
		else
		{
			int ans=abs(x-X)+abs(y-Y);
			for(int i=1;i<=K;i++) ans=min(ans,f[i][x][y]+f[i][X][Y]+1);
			printf("%d\n",ans);
		}
	}
	return 0;
}