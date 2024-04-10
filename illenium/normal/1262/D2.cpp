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

struct node{int x,id;}p[maxn];
struct node2{int k,pos,id;}q[maxn];
int t[maxn],n,a[maxn],ans[maxn];

inline bool cmp(node a,node b)
{
	if(a.x!=b.x) return a.x>b.x;
	return a.id<b.id;
}

inline bool cmp2(node2 a,node2 b)
{
	if(a.k!=b.k) return a.k<b.k;
	return a.pos<b.pos;
}

inline void add(int x)
{
	for(int i=x;i<=n;i+=i&-i) t[i]++;
}

inline int query(int x)
{
	int tmp=0;
	for(int i=x;i;i-=i&-i) tmp+=t[i];
	return tmp;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) p[i].x=read(),p[i].id=i,a[i]=p[i].x;
	sort(p+1,p+n+1,cmp);
	int Q=read();
	for(int i=1;i<=Q;i++) q[i].k=read(),q[i].pos=read(),q[i].id=i;
	sort(q+1,q+Q+1,cmp2);
	int nw=0;
	for(int i=1;i<=Q;i++)
	{
		while(nw<q[i].k) nw++,add(p[nw].id);
		int l=0,r=n,tmp=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(query(mid)>=q[i].pos) tmp=mid,r=mid-1;
			else l=mid+1;
		}
		ans[q[i].id]=a[tmp];
//		for(int j=1;j<=n;j++)
//		{
//			if(query(j)==q[i].pos)
//			{
//				ans[q[i].id]=a[j];
//				break;
//			}
//		}
	}
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}