#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,m,s[maxn],ans[maxn],a[maxn];

inline bool cmp(int a,int b){return a>b;}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=m;i>=1;i--) s[i]=s[i+1]+a[i];
	if(s[1]<n) {puts("-1"); return 0;}
	ans[1]=1;
	for(int i=2;i<=m;i++) ans[i]=max(ans[i-1]+1,n-s[i]+1);
	int f=0;
	for(int i=1;i<=m;i++) if(ans[i]+a[i]-1>n) f=1;
	if(f==1) puts("-1");
	else for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}