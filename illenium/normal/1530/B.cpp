#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
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

int n,m,ans[25][25];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); rep(i,1,n) rep(j,1,m) ans[i][j]=0;
		for(int i=1;i<=n;i+=2) ans[i][1]=1;
		for(int i=1;i<=m;i+=2) ans[1][i]=1;
		for(int i=3;i<=n;i+=2) ans[i][m]=1;
		for(int i=m-2;i>=3;i-=2) ans[n][i]=1;
		rep(i,1,n)
		{
			rep(j,1,m) printf("%d",ans[i][j]);
			puts("");
		}
		puts("");
	}
	return 0;
}