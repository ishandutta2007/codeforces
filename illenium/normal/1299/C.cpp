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

int a[maxn],pre[maxn];
ll p[maxn];
double ans[maxn];

inline double wk(int x)
{
	ll tmp=p[x]-p[pre[x]-1];
	ll len=x-pre[x]+1;
	return (double)tmp/len;
}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read(),p[i]=p[i-1]+a[i];
	for(int i=1;i<=n;i++) pre[i]=i;
	for(int i=2;i<=n;i++)
	{
		while(wk(i)<=wk(pre[i]-1)) pre[i]=pre[pre[i]-1];
	}
	for(int i=n;i>=1;i)
	{
		double tmp=wk(i);
		for(int j=i;j>=pre[i];j--) ans[j]=tmp;
		i=pre[i]-1;
	}
	for(int i=1;i<=n;i++) printf("%.9lf\n",ans[i]);
	return 0;
}