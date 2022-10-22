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

int r[40][40],v[40][40],n,m,ans=-1e9,bin[40];

inline int F(int x,int y)
{
	return r[x][y]?-v[x][y]:v[x][y];
}

inline int query(int x,int y,int d)
{
	r[x][y]=d; r[x+m][y]=r[m][y]^d;
	r[x][y+m]=r[x][m]^d;
	r[x+m][y+m]=r[m][y+m]^r[x][y+m];
	return F(x,y)+F(x+m,y)+F(x,y+m)+F(x+m,y+m);
}

inline int query(int y,int d)
{
	int res=0; r[m][y]=d; r[m][y+m]=r[m][m]^d;
	res+=F(m,y)+F(m,y+m);
	for(int x=1;x<m;x++) res+=max(query(x,y,0),query(x,y,1));
	return res;
}

inline int calc()
{
	int res=0;
	for(int x=1;x<=n;x++) res+=F(x,m);
	for(int y=1;y<m;y++) res+=max(query(y,0),query(y,1));
	return res;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) v[i][j]=read();
	m=(n+1)>>1; ans=-inf; bin[0]=1;
	for(int i=1;i<=m+1;i++) bin[i]=bin[i-1]<<1;
	for(int zt=0;zt<bin[m];zt++)
	{
		for(int x=1;x<=m;x++) r[x][m]=zt>>(x-1)&1;
		for(int x=1;x<m;x++) r[x+m][m]=r[m][m]^r[x][m];
		ans=max(ans,calc());
	}
	printf("%d\n",ans);
	return 0;
}