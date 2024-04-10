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

int n,m,a[maxn],cnt[maxn*5],block;
struct node{int l,r,id;}q[maxn];
ll w,ans[maxn];

inline bool cmp(node x,node y)
{
	if(x.l/block==y.l/block) return x.r<y.r;
	return x.l/block<y.l/block;
}

inline void del(ll x)
{
	w-=(ll)((2*cnt[a[x]]-1)*a[x]);
	cnt[a[x]]--;
}

inline void add(ll x)
{
	cnt[a[x]]++;
	w+=(ll)((2*cnt[a[x]]-1)*a[x]);
}

int main()
{
	//freopen("CF86D.in","r",stdin);
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) q[i].l=read(),q[i].r=read(),q[i].id=i;
	block=sqrt(n);
	sort(q+1,q+m+1,cmp);
	int l=0,r=0;
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l) del(l),l++;
		while(l>q[i].l) l--,add(l);
		while(r<q[i].r) r++,add(r);
		while(r>q[i].r) del(r),r--;
		ans[q[i].id]=w;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}