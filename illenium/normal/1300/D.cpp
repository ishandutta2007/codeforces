#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

struct node{int x,y;}p[maxn];

inline bool cmp(node a,node b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) p[i].x=read(),p[i].y=read();
	sort(p+1,p+n+1,cmp);
	if(n%2==1) {puts("NO"); return 0;}
	int tx=p[1].x+p[n].x,ty=p[1].y+p[n].y;
	for(int i=2;i<=n/2;i++)
	{
		if(p[i].x+p[n-i+1].x!=tx||p[i].y+p[n-i+1].y!=ty) {puts("NO"); return 0;}
	}
	puts("YES");
	return 0;
}