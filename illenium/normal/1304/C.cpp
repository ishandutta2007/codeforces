#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
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

struct node{int t,l,r;}p[maxn];

inline bool cmp(node a,node b){return a.t<b.t;}

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;i++) p[i].t=read(),p[i].l=read(),p[i].r=read();
		sort(p+1,p+n+1,cmp);
		p[0].t=0; p[0].l=m; p[0].r=m;
		int f=0,mr=m,ml=m;
		for(int i=1;i<=n;i++)
		{
			mr=mr+(p[i].t-p[i-1].t);
			ml=ml-(p[i].t-p[i-1].t);
			if(mr<p[i].l||ml>p[i].r) f=1;
			mr=min(mr,p[i].r); ml=max(ml,p[i].l);
		}
		if(f==1) puts("NO");
		else puts("YES");
	}
	return 0;
}