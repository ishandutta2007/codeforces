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

struct node{int x,id;}a[maxn];
int f[maxn];

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].id=i;
	for(int i=1;i<=(1e7/n)&&i<1000*n;i++)
	{
		random_shuffle(a+1,a+n+1);
		int t1=a[1].x,t2=a[2].x;
		f[a[1].id]=1; f[a[2].id]=2;
		for(int i=3;i<=n;i++)
		{
			int x=__gcd(t1,a[i].x);
			if(x<t1) t1=x,f[a[i].id]=1;
			else t2=__gcd(t2,a[i].x),f[a[i].id]=2;
		}
		if(t1==1&&t2==1)
		{
			puts("YES");
			for(int i=1;i<=n;i++) printf("%d ",f[i]);
			return 0;
		}
	}
	puts("NO");
	return 0;
}