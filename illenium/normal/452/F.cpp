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
#define ull unsigned long long
#define maxn 300005
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

int n,a[maxn];
ull p[maxn];

struct bit
{
	ull c[maxn];
	
	inline void clr(){memset(c,0,sizeof(c));}
	
	inline void add(int x)
	{
		for(int i=x;i<=n;i+=i&-i) c[i]=c[i]+p[i-x];
	}
	
	inline ull getsum(int x)
	{
		ull t=0;
		for(int i=x;i;i-=i&-i) t=(t+c[i]*p[x-i]);
		return t;
	}
	
	inline ull query(int x,int y)
	{
		ull pp=getsum(x-1),q=getsum(y);
		return q-pp*p[y-x+1];
	}
}bit1,bit2;

int main()
{
	int T=1; p[0]=1;
	for(int i=1;i<=maxn-5;i++) p[i]=p[i-1]*233;
	while(T--)
	{
		bit1.clr(); bit2.clr(); n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int i;
		for(i=1;i<=n;i++)
		{
			int x=min(a[i]-1,n-a[i]);
			if(x&&bit1.query(a[i]-x,a[i]-1)!=bit2.query(n-a[i]-x+1,n-a[i])) break;
			bit1.add(a[i]); bit2.add(n-a[i]+1);
		}
		if(i>n) puts("NO");
		else puts("YES");
	}
	return 0;
}