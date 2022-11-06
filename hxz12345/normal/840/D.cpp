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
struct SegmentTree{
	int lft,rit,sum;
} tree[10001010];
int rt[1001010],a[1001010],sz,n,Testing,i,l,r,k,V;
void pushup(int x){
	tree[x].sum=tree[tree[x].lft].sum+tree[tree[x].rit].sum;
}
void build(int x,int l,int r){
	if (l==r){
		if (l==a[1]) tree[x].sum=1;
		sz=max(sz,x);
		return ;
	}
	int mid=(l+r)>>1;
	tree[x].lft=x<<1;tree[x].rit=x<<1|1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
    pushup(x);
}
int modify(int x,int l,int r,int tx){
	if (l==r){sz++;tree[sz].sum=tree[x].sum+1;return sz;}
	sz++;int lst=sz;
	int mid=(l+r)>>1;
	tree[sz]=tree[x];tree[sz].sum++;
	if (tx<=mid) tree[sz].lft=modify(tree[x].lft,l,mid,tx);
	else tree[sz].rit=modify(tree[x].rit,mid+1,r,tx);
	pushup(x);
	return lst;
}
int calc(int xl,int xr,int l,int r){
	if ((l==r)){
		if (tree[xr].sum-tree[xl].sum>V) return l;return -1;
	}
	int mid=(l+r)>>1,ans=-1;
	if (tree[tree[xr].lft].sum-tree[tree[xl].lft].sum>V) ans=calc(tree[xl].lft,tree[xr].lft,l,mid);
	if (ans==-1) ans=calc(tree[xl].rit,tree[xr].rit,mid+1,r);
	return ans;
}
int main()
{
	n=read();Testing=read();
	for (i=1;i<=n;i++) a[i]=read();
	rt[1]=1;build(1,1,n);
	for (i=2;i<=n;i++) rt[i]=modify(rt[i-1],1,n,a[i]);
    for (;Testing;Testing--){
    	l=read();r=read();k=read();V=(r-l+1)/k;
    	printf("%d\n",calc(rt[l-1],rt[r],1,n));
	}
return 0;
}

/*




k=2
 
*/