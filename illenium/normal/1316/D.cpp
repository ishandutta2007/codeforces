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

int x[maxn][maxn],y[maxn][maxn],n,f,vis[maxn][maxn];
char ans[maxn][maxn];
vector <int> v1,v2;
int kx[4]={0,0,1,-1},ky[4]={-1,1,0,0};

inline void dfs(int fx,int fy,int u,int v)
{
	//cout<<fx<<" "<<fy<<endl;
	vis[fx][fy]=1;
	for(int i=0;i<=3;i++)
	{
		int tx=fx+kx[i],ty=fy+ky[i];
		//cout<<"Asdkljasljdlksd"<<fx<<" "<<fy<<" "<<tx<<" "<<ty<<endl;
		if(tx>n||tx<=0||ty>n||ty<=0) continue;
		if(vis[tx][ty]==0&&x[tx][ty]==u&&y[tx][ty]==v)
		{
			if(i==0) ans[tx][ty]='R';
			else if(i==1) ans[tx][ty]='L';
			else if(i==2) ans[tx][ty]='U';
			else ans[tx][ty]='D'; dfs(tx,ty,u,v);
		}
	}
	return;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) x[i][j]=read(),y[i][j]=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		if(x[i][j]!=-1) ans[x[i][j]][y[i][j]]='X',v1.push_back(x[i][j]),v2.push_back(y[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		if(x[i][j]==-1)
		{
			int ff=0; vis[i][j]=1;
			for(int k=0;k<=3;k++)
			{
				int tx=i+kx[k],ty=j+ky[k];
				if(tx<=0||tx>n||ty<=0||ty>n) continue;
				if(x[tx][ty]==-1)
				{
					if(k==0) ans[i][j]='L';
					else if(k==1) ans[i][j]='R';
					else if(k==2) ans[i][j]='D';
					else ans[i][j]='U'; ff=1; break;
				}
			}
			if(ff==0) {f=1; break;}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		if(ans[i][j]=='X'&&(x[i][j]!=i||y[i][j]!=j)) f=1;
	if(f==1) {puts("INVALID"); return 0;}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		if(x[i][j]==-1||vis[i][j]) continue;
		if(ans[i][j]=='X') dfs(i,j,i,j);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(!ans[i][j]) f=1;
	if(f==1) {puts("INVALID"); return 0;}
	puts("VALID");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%c",ans[i][j]);
		puts("");
	}
	return 0;
}