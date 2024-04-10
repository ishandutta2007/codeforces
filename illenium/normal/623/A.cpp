#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

const int N=502;
int i,j,n,m,v[4],a[N],d[N],g[N][N];

inline int F(int i,int j){return abs(a[i]-a[j]);}

inline void No()
{
	printf("No\n");
	exit(0);
}

int main()
{
	n=read(); m=read();
	while(m--)
	{
		i=read(); j=read();
		g[i][j]=g[j][i]=1;
		d[i]++,d[j]++;
		if(d[i]+1==n) a[i]=2;
		if(d[j]+1==n) a[j]=2;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i])continue;
		for(a[i]=j=1;j<=n;j++)
		{
			if(a[j])continue;
			if(g[i][j])a[j]=1;
				else a[j]=3;
		}
	}
	for(i=2;i<=n;i++)
		for(j=1;j<i;j++)
			if(F(i,j)==2&&g[i][j]||F(i,j)<2&&!g[i][j])No();
	for(puts("Yes"),i=1;i<=n;i++) putchar(a[i]+96);
}