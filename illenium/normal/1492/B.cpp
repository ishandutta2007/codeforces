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

int a[maxn],p[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),nw=n; rep(i,1,n) a[i]=read(),p[a[i]]=i;
		per(i,n,1)
		{
			if(p[i]<=nw)
			{
				rep(j,p[i],nw) printf("%d ",a[j]);
				nw=p[i]-1;
			}
		}
		puts("");
	}
	return 0;
}