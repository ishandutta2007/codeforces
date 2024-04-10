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

int n,m;
struct node{int id,w,op;}p[maxn];
ll ans;

inline bool cmp(node x,node y)
{
	if(x.id==y.id) return x.w>y.w;
	return x.id<y.id;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) p[i].id=read(),p[i].w=read(),p[i].op=1;
	m=read();
	for(int i=1;i<=m;i++) p[i+n].id=read(),p[i+n].w=read(),p[i+n].op=2;
	sort(p+1,p+n+m+1,cmp);
	ans+=p[1].w;
	for(int i=2;i<=n+m;i++)
	{
		if(p[i].id!=p[i-1].id) ans+=p[i].w;
	}
	cout<<ans<<endl;
	return 0;
}