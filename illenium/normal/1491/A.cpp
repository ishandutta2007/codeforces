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

int n,q,a[maxn];

int main()
{
	int T=1;
	while(T--)
	{
		n=read(),q=read(); int t1=0,t2=0;
		rep(i,1,n) a[i]=read();
		rep(i,1,n) if(a[i]) t1++; else t2++;
		while(q--)
		{
			int opt=read();
			if(opt==1)
			{
				int x=read();
				if(a[x]) t1--,t2++;
				else t1++,t2--; a[x]^=1;
			}
			else
			{
				int x=read();
				if(x<=t1) puts("1"); else puts("0");
			}
		}
	}
	return 0;
}