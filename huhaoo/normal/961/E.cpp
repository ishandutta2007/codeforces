#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int t=1,r=0,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define N 500010
int n,a;
long long ans;
struct tree
{
	int s;
	tree *l,*r;
	tree()
	{
		s=0;
		l=r=NULL;
	}
}*root[N];
tree *build(int l,int r)
{
	tree *k=new tree;
	if(l==r)return k;
	int mid=(l+r)>>1;
	k->l=build(l,mid);
	k->r=build(mid+1,r);
	return k;
}
tree *ins(tree *las,int l,int r,int pos)
{
	tree *k=new tree;
	k->s=las->s+1;
	if(l==r)return k;
	int mid=(l+r)>>1;
	if(pos<=mid)
	{
		k->l=ins(las->l,l,mid,pos);
		k->r=las->r;
	}
	else
	{
		k->l=las->l;
		k->r=ins(las->r,mid+1,r,pos);
	}
	return k;
}
int up(tree *k,int l,int r,int pos)
{
	if(l>=pos)return k->s;
	int mid=(l+r)>>1;
	if(mid>=pos)return up(k->l,l,mid,pos)+up(k->r,mid+1,r,pos);
	else return up(k->r,mid+1,r,pos);
}
int main()
{
	n=read();
	root[0]=build(1,n);
	fr(i,1,n)
	{
		a=read();
		ans+=up(root[min(a,i-1)],1,n,i);
		root[i]=ins(root[i-1],1,n,min(a,n));
	}
	printf("%I64d\n",ans);
	return 0;
}