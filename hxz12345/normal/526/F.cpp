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
struct SegmentTree{long long mn,cnt,tag;} tree[2001010];
long long wu,wd,a[1001010],c[1001010],b[1001010],n,x,y,ans,i;
void pushup(int x){
	tree[x].mn=min(tree[x<<1].mn,tree[x<<1|1].mn);tree[x].cnt=0;
	if (tree[x].mn==tree[x<<1].mn) tree[x].cnt+=tree[x<<1].cnt;
	if (tree[x].mn==tree[x<<1|1].mn) tree[x].cnt+=tree[x<<1|1].cnt;return; 
}
void build(int x,int l,int r){
	if (l==r){tree[x].mn=l;tree[x].cnt=1;return ;}
	int mid=(l+r)>>1;build(x<<1,l,mid);build(x<<1|1,mid+1,r);pushup(x);
}
void pushdown(int x){
	tree[x<<1].mn+=tree[x].tag;tree[x<<1|1].mn+=tree[x].tag;
	tree[x<<1].tag+=tree[x].tag;tree[x<<1|1].tag+=tree[x].tag;tree[x].tag=0;
}
void modify(int x,int l,int r,int tl,int tr,int val){
	if ((l>=tl)&&(r<=tr)){tree[x].mn+=val;tree[x].tag+=val;return ;}
	int mid=(l+r)>>1;pushdown(x);
	if (tl<=mid) modify(x<<1,l,mid,tl,tr,val);
	if (tr>mid) modify(x<<1|1,mid+1,r,tl,tr,val);
	pushup(x);
}
int query(int x,int l,int r,int tl,int tr){
	if ((l>=tl)&&(r<=tr)) {if (tree[x].mn==0) return tree[x].cnt;return 0;}
	int mid=(l+r)>>1;pushdown(x);long long ans=0;
	if (tl<=mid) ans+=query(x<<1,l,mid,tl,tr);
	if (tr>mid) ans+=query(x<<1|1,mid+1,r,tl,tr);
	pushup(x);
	return ans;
}
int main()
{
	n=read();
	for (i=1;i<=n;i++){
		x=read();y=read();a[x]=y;}
	build(1,1,n);
	for (i=1;i<=n;i++){
		modify(1,1,n,1,n,-1);
		while ((wu>0)&&(a[i]>a[b[wu]])){modify(1,1,n,b[wu-1]+1,b[wu],-a[b[wu]]+a[i]);wu--;} wu++;b[wu]=i;
		while ((wd>0)&&(a[i]<a[c[wd]])){modify(1,1,n,c[wd-1]+1,c[wd],a[c[wd]]-a[i]);wd--;} wd++;c[wd]=i;
		ans+=query(1,1,n,1,i);
	}
	printf("%lld\n",ans);
return 0;
}