#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 505
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

int n,m;
char s[maxn][maxn],ans[maxn][maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); rep(i,1,n) scanf("%s",s[i]+1);
		rep(i,1,n) rep(j,1,m) ans[i][j]=s[i][j];
		if(n==1)
		{
			rep(i,1,m) printf("X"); puts("");
		}
		else
		{
			for(int i=1;i<=m;i+=3) rep(j,1,n) ans[j][i]='X';
			if(m%3==0) rep(i,1,n) if(ans[i][m]=='X'&&ans[i][m-1]=='.') ans[i][m-1]='X';
			
			for(int i=1;i<=m;i+=3)
				if(ans[n-1][i+1]=='X'||ans[n-1][i+2]=='X') ans[n-1][i+1]='X',ans[n-1][i+2]='X';
				else ans[n][i+1]='X',ans[n][i+2]='X';
			
			rep(i,1,n)
			{
				rep(j,1,m) printf("%c",ans[i][j]);
				puts("");
			}
		}
		
		rep(i,1,n+2) rep(j,1,m+2) ans[i][j]=' ',s[i][j]=' ';
	}
	return 0;
}