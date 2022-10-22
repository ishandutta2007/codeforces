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

int a[maxn],b[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		rep(i,1,n) b[i]=read();
		int f1=n,f2=n,f=0;
		for(int i=1;i<=n;i++) if(a[i]==1) {f1=i; break;}
		for(int i=1;i<=n;i++) if(a[i]==-1) {f2=i; break;}
		for(int i=1;i<=f1;i++) if(a[i]<b[i]) f=1;
		for(int i=1;i<=f2;i++) if(a[i]>b[i]) f=1;
		if(f==1) puts("NO"); else puts("YES");
	}
	return 0;
}