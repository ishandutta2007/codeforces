#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
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

int a[maxn],f[maxn],last,mx;
int opt[maxn],x[maxn],y[maxn],ans[maxn];

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int q=read();
	for(int i=1;i<=q;i++)
	{
		opt[i]=read();
		if(opt[i]==1) x[i]=read(),y[i]=read();
		else x[i]=read();
	}
	int now=0;
	for(int i=q;i>=1;i--)
	{
		if(opt[i]==1)
		{
			if(f[x[i]]) continue;
			if(y[i]<now) ans[x[i]]=now,f[x[i]]=1;
			else ans[x[i]]=y[i],f[x[i]]=1;
		}
		else now=max(now,x[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]) printf("%d ",ans[i]);
		else printf("%d ",max(a[i],now));
	}
	return 0;
}