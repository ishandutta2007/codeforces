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

int n,k;
ll ans[maxn];
struct node{int p,c,id;}a[maxn];

inline bool cmp(node a,node b)
{
	if(a.p==b.p) return a.c<b.c;
	return a.p<b.p;
}

int main()
{
	n=read(); k=read();
	for(int i=1;i<=n;i++) a[i].p=read();
	for(int i=1;i<=n;i++) a[i].c=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	multiset <int> s;
	multiset <int>::iterator it;
	for(int i=1;i<=n;i++)
	{
		ans[a[i].id]=a[i].c;
		for(it=s.begin();it!=s.end();it++) ans[a[i].id]+=*it;
		s.insert(a[i].c);
		while(s.size()>k) s.erase(s.begin());
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	return 0;
}