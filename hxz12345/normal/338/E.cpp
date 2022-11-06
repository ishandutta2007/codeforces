#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
struct SegmentTree{int mn,tag;} tree[4001010];
long long c[1001010],b[1001010],l,r,mid,a[1001010],i,ans,n,m,H;
void pushup(int x){tree[x].mn=min(tree[x<<1].mn,tree[x<<1|1].mn);}
void build(int x,int l,int r){
	if (l==r){tree[x].mn=-l;return; }
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);pushup(x);
}
void pushdown(int x){
	tree[x<<1].mn+=tree[x].tag;tree[x<<1|1].mn+=tree[x].tag;
	tree[x<<1].tag+=tree[x].tag;tree[x<<1|1].tag+=tree[x].tag;
	tree[x].tag=0;
}
void modify(int x,int l,int r,int tl,int tr,int val){
	if ((l>=tl)&&(r<=tr)){tree[x].mn+=val;tree[x].tag+=val;return ;}
	int mid=(l+r)>>1;pushdown(x);
	if (tl<=mid) modify(x<<1,l,mid,tl,tr,val);
	if (tr>mid) modify(x<<1|1,mid+1,r,tl,tr,val);
	pushup(x);
}
bool cmp(long long x,long long y){return x>y;}
int main()
{
	n=read();m=read();H=read();
	for (i=1;i<=m;i++) a[i]=read(),a[i]=H-a[i];
	sort(a+1,a+m+1,cmp);
	for (i=1;i<=n;i++) {
		b[i]=read();c[i]=m+1;
		l=1;r=m;
		while (l<=r){
			mid=(l+r)>>1;
			if (b[i]>=a[mid]) c[i]=mid,r=mid-1;
			else l=mid+1;
		}
	}
	build(1,1,m);
	for (i=1;i<=m;i++) 
	    if (c[i]<=m) modify(1,1,m,c[i],m,1);
	if (tree[1].mn>=0) ans++;
	for (i=m+1;i<=n;i++){
		if (c[i-m]<=m) modify(1,1,m,c[i-m],m,-1);
		if (c[i]<=m) modify(1,1,m,c[i],m,1);
		if (tree[1].mn>=0) ans++;
	}
	printf("%d\n",ans);
return 0;
}