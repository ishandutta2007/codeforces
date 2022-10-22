#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500005
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

struct node
{
	int l,r,w;
}tree[maxn<<2];

int n,m,l,r,x,y,w,q,op;
int a[maxn];

int gcd(int a,int b)
{
	if(a<b) swap(a,b);
	if(a%b==0) return b;
	return gcd(b,a%b);
}

void update(int now)
{
	tree[now].w=gcd(tree[now<<1].w,tree[now<<1|1].w);
}

void buildtree(int now,int l,int r)
{
	tree[now].l=l; tree[now].r=r;
	if(l==r)
	{
		tree[now].w=a[l];
		return;
	}
	int mid=(l+r)>>1;
	buildtree(now<<1,l,mid);
	buildtree(now<<1|1,mid+1,r);
	update(now);
}

void change(int now,int l,int w)
{
	if(tree[now].l==l&&tree[now].r==l)
	{
		tree[now].w=w;
		return;
	}
	if(l>=tree[now<<1|1].l) change(now<<1|1,l,w);
	else if(l<=tree[now<<1].r) change(now<<1,l,w);
	update(now);
}

int query(int now,int l,int r,int w)
{
	if(tree[now].l==tree[now].r)
	{
		if(tree[now].w%w==0) return 0;
		return 1;
	}
	if(tree[now].l<=l&&tree[now].r>=r&&tree[now].w%w==0) return 0;
	else if(l>=tree[now<<1|1].l) return query(now<<1|1,l,r,w);
	else if(r<=tree[now<<1].r) return query(now<<1,l,r,w);
	else
	{
		int b1=query(now<<1,l,tree[now<<1].r,w);
		if(b1>=2) return 2;
		int b2=query(now<<1|1,tree[now<<1|1].l,r,w);
		return b1+b2;
	}
}

int cha(int now,int l)
{
	if(tree[now].l==tree[now].r) return tree[now].w;
	else if(l>=tree[now<<1|1].l) return cha(now<<1|1,l);
	else if(l<=tree[now<<1].r) return cha(now<<1,l); 
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	buildtree(1,1,n);
	q=read();
	while(q--)
	{
		op=read();
		if(op==1)
		{
			l=read(); r=read(); w=read();
			//cout<<query(1,l,r,w)<<endl;
			if(query(1,l,r,w)<=1) puts("YES");
			else puts("NO");
		}
		else
		{
			l=read(); w=read();
			change(1,l,w);
		}
		//for(int i=1;i<=n;i++) cout<<cha(1,i); cout<<endl;
	}
	return 0;
}