#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char ans[505][505];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		if((n*m)%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if((i+j)%2==0) ans[i][j]='B';
					else ans[i][j]='W';
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if((i+j)%2==0) ans[i][j]='B';
					else ans[i][j]='W';
				}
			}
			if(m%2==0) ans[1][m]='B';
			else if(n%2==0) ans[n][1]='B';
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				printf("%c",ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}