#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
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

int a[305][305],n,m,F;

inline int jud(int x,int y)
{
	int tmp=4;
	if(x==1) tmp--; if(y==1) tmp--;
	if(x==n) tmp--; if(y==m) tmp--;
	return tmp;
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(),m=read(),F=0;
		rep(i,1,n) rep(j,1,m) a[i][j]=read();
		rep(i,1,n) rep(j,1,m)
		{
			if(a[i][j]>jud(i,j)) {F=1; break;}
			else a[i][j]=jud(i,j);
		}
		if(F) puts("NO");
		else
		{
			puts("YES");
			rep(i,1,n)
			{
				rep(j,1,m) printf("%d ",a[i][j]);
				puts("");
			}
		}
	}
	return 0;
}