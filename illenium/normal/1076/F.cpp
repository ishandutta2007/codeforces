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
#define maxn 300005
#define re register
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

ll x[maxn],y[maxn],fx[maxn],fy[maxn];

int main()
{
	ll n=read(),k=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=n;i++) y[i]=read();
	for(int i=1;i<=n;i++)
	{
		fx[i]=max(0ll,x[i]-(k*y[i]-fx[i-1]));
		fy[i]=max(0ll,y[i]-(k*x[i]-fy[i-1]));
		if(fx[i]>k||fy[i]>k) {puts("NO"); return 0;}
	}
	puts("YES");
	return 0;
}