#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int x[55][55];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read(),a=read(),b=read(),cnt=0,F=0;
		if(a*n!=b*m) {puts("NO"); continue;}
		for(int w=1;w<=max(n,m);w++)
		{
			int f=0,nw=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=nw,k=1;k<=a;j++,k++) {if(j>m) j-=m; x[i][j]=1;}
				nw+=w; if(nw>m) nw-=m;
			}
			rep(i,1,n)
			{
				int tmp=0;
				rep(j,1,m) tmp+=(x[i][j]==1);
				if(tmp!=a) f=1;
			}
			rep(i,1,m)
			{
				int tmp=0;
				rep(j,1,n) tmp+=(x[j][i]==1);
				if(tmp!=b) f=1;
			}
			if(f==0)
			{
				F=1;
				puts("YES");
				rep(i,1,n)
				{
					rep(j,1,m) printf("%d",x[i][j]); puts("");
				}
				break;
			}
			rep(i,1,n) rep(j,1,m) x[i][j]=0;
		}
		if(F==0) puts("NO");
		rep(i,1,n) rep(j,1,m) x[i][j]=0;
	}
	return 0;
}