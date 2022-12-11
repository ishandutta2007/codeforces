#include<iostream>
#include<cstring>
using namespace std;

int n,a[201000];

typedef struct line_tree{
	int ls,rs,val;
}lt;
lt tree[30001000];

int tnt=150;
void add(int &x,int pos,int l,int r)
{
	if(!x)
		x=++tnt;
	if(l==r){
		++tree[x].val;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)add(tree[x].ls,pos,l,mid);
	else add(tree[x].rs,pos,mid+1,r);
	++tree[x].val;
}
void merge(int &i,int &j)
{
	if(!i)return;
	if(!j){
		j=i;i=0;return;
	}
	tree[j].val+=tree[i].val;
	merge(tree[i].ls,tree[j].ls);
	merge(tree[i].rs,tree[j].rs);
	i=0;
}
void change(int &i,int &j,int l,int r,int rl,int rr)	//j<-i
{
	if(!i)return;
	if(!j)j=++tnt;
	if(l<=rl&&rr<=r)
	{
		merge(i,j);
		return;
	}
	int mid=(rl+rr)>>1;
	if(l<=mid)change(tree[i].ls,tree[j].ls,l,r,rl,mid);
	if(r>mid)change(tree[i].rs,tree[j].rs,l,r,mid+1,rr);
	tree[j].val=tree[tree[j].ls].val+tree[tree[j].rs].val;
	tree[i].val=tree[tree[i].ls].val+tree[tree[i].rs].val;
}
void cover(int val,int &i,int l,int r)
{
	if(!i||!tree[i].val)return;
	if(l==r)
	{
		a[l]=val;return;
	}
	int mid=(l+r)>>1;
	cover(val,tree[i].ls,l,mid);
	cover(val,tree[i].rs,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(a[i],i,1,n);
	}
	int q;
	scanf("%d",&q);
	int l,r,x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&l,&r,&x,&y);
		if(x!=y)
		    change(x,y,l,r,1,n);
	}
	for(int i=1;i<=100;i++)
		cover(i,i,1,n);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}