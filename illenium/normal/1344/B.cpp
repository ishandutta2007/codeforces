#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char s[maxn][maxn];
int vis[maxn][maxn],n,m,cnt,f,p,h[maxn],l[maxn],f1,f2;
const int kx[4]={0,0,1,-1};
const int ky[4]={1,-1,0,0};

inline void bfs(int x,int y)
{
	cnt++; queue <int> qx,qy; qx.push(x); qy.push(y);
	while(!qx.empty())
	{
		int u=qx.front(),v=qy.front(); qx.pop(); qy.pop();
		for(int i=0;i<=3;i++)
		{
			int tx=u+kx[i],ty=v+ky[i];
			if(s[tx][ty]=='.'||vis[tx][ty]||tx<=0||tx>n||ty<=0||ty>m) continue;
			qx.push(tx); qy.push(ty); vis[tx][ty]=1;
		}
	}
}

int main()
{
	n=read(); m=read(); f=0; p=0;
	rep(i,0,n) rep(j,0,m) s[i][j]='.';
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='#'&&vis[i][j]==0) bfs(i,j);
	for(int i=1;i<=n;i++)
	{
		p=0;
		for(int j=1;j<=m;j++) if(s[i][j]!=s[i][j-1]&&s[i][j]=='#') p++;
		if(p>=2) f=1;
	}
	for(int j=1;j<=m;j++)
	{
		p=0;
		for(int i=1;i<=n;i++) if(s[i][j]!=s[i-1][j]&&s[i][j]=='#') p++;
		if(p>=2) f=1;
	}
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='#') h[i]++,l[j]++;
	rep(i,1,n) if(h[i]==0) f1=1;
	rep(i,1,m) if(l[i]==0) f2=1;
	if(f==0&&f1+f2!=1) cout<<cnt<<endl; else puts("-1");
	return 0;
}