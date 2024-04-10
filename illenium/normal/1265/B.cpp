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

inline bool cmp(node a,node b){return a.x<b.x;}

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++) a[i].x=read(),a[i].id=i;
		sort(a+1,a+n+1,cmp);
		int mx=-1,mn=inf;
		for(int i=1;i<=n;i++)
		{
			mx=max(a[i].id,mx);
			mn=min(a[i].id,mn);
			if(mx-mn+1==i) printf("1");
			else printf("0");
		}
		puts("");
	}
	return 0;
}