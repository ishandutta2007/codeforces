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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],k[maxn],sum[maxn],dmg,n,q;

int main()
{
	//freopen("CF975C.in","r",stdin);
	n=read(); q=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=q;i++) k[i]=read();
	for(int turn=1;turn<=q;turn++)
	{
		dmg+=k[turn];
		if(dmg>=sum[n]) dmg=0,printf("%d\n",n);
		else printf("%d\n",n-((upper_bound(sum+1,sum+n+1,dmg))-sum)+1);
	}
	return 0;
}