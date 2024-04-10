#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 505
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

int mp[4][maxn][maxn],f[255][maxn][maxn],n,m,q;
char s[maxn][maxn];

inline int gs(int opt,int x,int y,int X,int Y)
{
	return mp[opt][X][Y]-mp[opt][x-1][Y]-mp[opt][X][y-1]+mp[opt][x-1][y-1];
}

inline bool jud(int x,int a,int b)
{
	if(gs(0,a,b,a+x-1,b+x-1)!=x*x) return false;
	if(gs(1,a,b+x,a+x-1,b+2*x-1)!=x*x) return false;
	if(gs(2,a+x,b,a+2*x-1,b+x-1)!=x*x) return false;
	if(gs(3,a+x,b+x,a+2*x-1,b+2*x-1)!=x*x) return false;
	return true;
}

inline bool jud2(int x,int a,int b,int c,int d)
{
	if(c<a||d<b) return false;
	int tmp=f[x][c][d]-f[x][a-1][d]-f[x][c][b-1]+f[x][a-1][b-1];
	return (tmp!=0);
}

int main()
{
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		mp[0][i][j]=mp[0][i][j-1]+mp[0][i-1][j]-mp[0][i-1][j-1]+(s[i][j]=='R');
		mp[1][i][j]=mp[1][i][j-1]+mp[1][i-1][j]-mp[1][i-1][j-1]+(s[i][j]=='G');
		mp[2][i][j]=mp[2][i][j-1]+mp[2][i-1][j]-mp[2][i-1][j-1]+(s[i][j]=='Y');
		mp[3][i][j]=mp[3][i][j-1]+mp[3][i-1][j]-mp[3][i-1][j-1]+(s[i][j]=='B');
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		for(int k=1;k<=n;k++)
		{
			if(i+2*k-1>n||j+2*k-1>m) break;
			if(jud(k,i,j)) f[k][i][j]=f[k][i-1][j]+f[k][i][j-1]-f[k][i-1][j-1]+1;
			else f[k][i][j]=f[k][i-1][j]+f[k][i][j-1]-f[k][i-1][j-1];
		}
	}
	
	while(q--)
	{
		int x=read(),y=read(),X=read(),Y=read();
		int l=1,r=min(X-x+1,Y-y+1),ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(jud2(mid,x,y,X-2*mid+1,Y-2*mid+1)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",4*ans*ans);
	}
	return 0;
}