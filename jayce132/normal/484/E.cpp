#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;

int n,m,a[maxn],p[maxn];

inline bool cmp(const int x,const int y){ return a[x]<a[y];}

struct node {
	int s,ls,rs,id,lc,rc;
	inline void Merge(node lc,node rc){
		s=max(max(lc.s,rc.s),lc.rs+rc.ls);
		ls=lc.id?lc.ls+rc.ls:lc.ls;
		rs=rc.id?rc.rs+lc.rs:rc.rs;
		id=lc.id&rc.id;
	}
};
node c[maxn<<6];
int tot,root[maxn];

int make_tree(int l,int r)
{
	int no=++tot;
	c[no]=(node){r-l+1,r-l+1,r-l+1,1};
	if(l==r)return no;
	int mid=(l+r)>>1;
	c[no].lc=make_tree(l,mid);
	c[no].rc=make_tree(mid+1,r);
	return no;
}


int update(int x,int o,int l,int r)
{
	int no=++tot;
	c[no]=c[o];
	if(l==r){c[no].s=c[no].ls=c[no].rs=c[no].id=0;return no;}
	int mid=(l+r)>>1;
	if(x<=mid)c[no].lc=update(x,c[o].lc,l,mid);
	else c[no].rc=update(x,c[o].rc,mid+1,r);
	c[no].Merge(c[c[no].lc],c[c[no].rc]);
	return no;
}

node query(int ql,int qr,int o,int l,int r)
{
	if(!o || ql>qr)return (node){0,0,0,0};
	if(ql<=l && r<=qr)return c[o];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(ql,qr,c[o].lc,l,mid);
	else if(ql>mid)return query(ql,qr,c[o].rc,mid+1,r);
	else{
		node x;
		x.Merge(query(ql,qr,c[o].lc,l,mid),query(ql,qr,c[o].rc,mid+1,r));
		return x;
	}
}

inline void init()
{
	n=read();
	REP(i,1,n)a[i]=read(),p[i]=i;
	sort(p+1,p+n+1,cmp);
	root[1]=make_tree(1,n);
	REP(i,2,n)root[i]=update(p[i-1],root[i-1],1,n);
}

inline void doing()
{
	int m=read();
	while(m--)
	{
		int ql=read(),qr=read(),k=read();
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(query(ql,qr,root[mid],1,n).s>=k)l=mid;
			else r=mid-1;
		}
		printf("%d\n",a[p[l]]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}