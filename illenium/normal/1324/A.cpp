#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int a[maxn];

int main()
{
	int T=read(),mx=0;
	while(T--)
	{
		int n=read(),mx=0,f=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			mx=max(mx,a[i]);
		}
		for(int i=1;i<=n;i++) if((mx-a[i])%2==1) f=1;
		if(f==0) puts("YES");
		else puts("NO");
	}
	return 0;
}