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

int n,T;
struct node{int a,t; double s;}a[maxn];
double tp,ans;

inline bool cmp(node a,node b){return a.t<b.t;}

int main()
{
	n=read(); T=read();
	for(int i=1;i<=n;i++) a[i].a=read();
	for(int i=1;i<=n;i++) a[i].t=read(),a[i].t-=T;
	sort(a+1,a+n+1,cmp);
	if(a[1].t>0||a[n].t<0)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++) a[i].s=(double)a[i].a*a[i].t,tp+=a[i].s;
	if(tp<0)
	{
		for(int i=1;i<=n;i++) a[i].t=-a[i].t,a[i].s=-a[i].s;
		reverse(a+1,a+n+1);
	}
	tp=0;
	for(int i=1;i<=n;i++)
	{
		if(tp+a[i].s>0)
		{
			ans+=(-tp)/a[i].t;
			break;
		}
		tp+=a[i].s,ans+=a[i].a;
	}
	printf("%.6lf",ans);
	return 0;
}