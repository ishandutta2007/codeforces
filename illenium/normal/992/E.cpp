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

ll n,q,a[maxn],c[maxn];

inline void add(int x,ll v)
{
	for(int i=x;i<=n;i+=i&-i) c[i]+=v; 
}

inline ll sum(int x)
{
	ll res=0;
	for(int i=x;i;i-=i&-i) res+=c[i];
	return res;
}

inline void solve()
{
	int x=1;
	if(sum(1)==0)
	{
		puts("1");
		return;
	}
	while(x<n)
	{
		ll l=x+1,r=n,k=x,now=2*sum(x);
		if(sum(x+1)==now)
		{
			printf("%d\n",x+1);
			return;
		}
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(sum(mid)<now) k=mid,l=mid+1;
			else r=mid-1;
		}
		if(k+1>n) break;
		x=(k==x)?k+1:k;
	}
	puts("-1");
}

int main()
{
	n=read(); q=read();
	for(int i=1;i<=n;i++) a[i]=read(),add(i,a[i]);
	while(q--)
	{
		int x=read(),y=read();
		add(x,y-a[x]); a[x]=y; solve();
	}
	return 0;
}