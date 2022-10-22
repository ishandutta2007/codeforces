#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,v[maxn];
struct node{int a,b,c,d,e,id;}p[maxn];

inline bool cmp1(node a,node b){return a.a<b.a;}
inline bool cmp2(node a,node b){return a.b<b.b;}
inline bool cmp3(node a,node b){return a.c<b.c;}
inline bool cmp4(node a,node b){return a.d<b.d;}
inline bool cmp5(node a,node b){return a.e<b.e;}

inline bool operator < (node a,node b)
{
	int cnt=0;
	if(a.a>b.a) cnt++;
	if(a.b>b.b) cnt++;
	if(a.c>b.c) cnt++;
	if(a.d>b.d) cnt++;
	if(a.e>b.e) cnt++;
	if(cnt>=3) return true; return false;
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); int F=1,ff=0;
		rep(i,1,n) p[i].a=read(),p[i].b=read(),p[i].c=read(),p[i].d=read(),p[i].e=read(),p[i].id=i;
		rep(i,2,n) if(p[F]<p[i]) F=i;
		rep(i,1,n)
		{
			if(F==i) continue;
			if(p[F]<p[i]) {ff=1; break;}
		}
		if(ff) puts("-1"); else printf("%d\n",F);
	}
	return 0;
}