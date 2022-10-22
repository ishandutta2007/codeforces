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

int n,u,v,a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); u=read(); v=read(); rep(i,1,n) a[i]=read();
		
		int nw=0;
		rep(i,2,n) if(abs(a[i]-a[i-1])>=2) {nw=1; break;}
		if(nw==1) {puts("0"); continue;}
		
		int F=0;
		rep(i,2,n) if(a[i]!=a[1]) {F=1; break;}
		if(!F) printf("%d\n",min(2*v,u+v));
		else printf("%d\n",min(u,v));
	}
	return 0;
}