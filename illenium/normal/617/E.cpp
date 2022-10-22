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
#define maxn 1<<20
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,m,k;
struct node{ll l,r,id;}q[maxn];
ll a[maxn],blo,cnt[maxn],as[maxn],ans;

inline bool cmp(node a,node b)
{
	if(a.l/blo==b.l/blo) return a.r<b.r;
	return a.l<b.l; 
}

inline void add(int w)
{
	ans+=cnt[a[w]^k];
	cnt[a[w]]++;
}

inline void del(int w)
{
	cnt[a[w]]--;
	ans-=cnt[a[w]^k];
}

int main()
{
	n=read(); m=read(); k=read(); blo=sqrt(n);
	for(int i=1;i<=n;i++) a[i]=read(),a[i]^=a[i-1];
	for(int i=1;i<=m;i++)
	{
		q[i].l=read(); q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=1,r=0; cnt[0]=1;
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l) del(l-1),l++;
		while(l>q[i].l) l--,add(l-1);
		while(r<q[i].r) r++,add(r);
		while(r>q[i].r) del(r),r--;
		as[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++) printf("%lld\n",as[i]);
	return 0;
}