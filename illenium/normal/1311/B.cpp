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

int a[maxn],p[maxn],n,m,f;

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); f=0;
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=m;i++) p[i]=read();
		sort(p+1,p+m+1);
		for(int i=1;i<=m;i++)
		{
			int st=i;
			while(p[i+1]==p[i]+1&&i<=m) i++;
			sort(a+p[st],a+p[i]+2);
		}
		for(int i=1;i<=n;i++) if(a[i]<a[i-1]) f=1;
		if(f==0) puts("YES"); else puts("NO");
	}
	return 0;
}