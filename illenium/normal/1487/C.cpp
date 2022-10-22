#pragma GCC optimize(3,"Ofast","inline")
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

int main()
{
	int T=read();
	while(T--)
	{
		int n=read()-1;
		if(n%2==1)
		{
			rep(i,1,n) rep(j,1,n-i+1)
			{
				if(2*j-1==n) printf("0 ");
				else if(2*j<n) printf("1 ");
				else printf("-1 ");
			}
		}
		else
		{
			rep(i,1,n) rep(j,1,n-i+1)
			{
				if(j<=n/2) printf("1 ");
				else printf("-1 ");
			}
		}
		puts("");
	}
	return 0;
}