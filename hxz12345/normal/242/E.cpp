#include <bits/stdc++.h>
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
	long long sum,tag;
} tree[22][701010];
long long x,a[1001010],n,i,now,T,opt,l,r,ans;
void pushup(int now,int x){
	tree[now][x].sum=tree[now][x*2].sum+tree[now][x*2+1].sum;
}
void pushdown(int now,int x,int l,int r)
{
	int mid=(l+r)/2;
	if (tree[now][x].tag % 2==1) 
	    {
	    	tree[now][x*2].sum=(1ll<<now)*(mid-l+1)-tree[now][x*2].sum;
	    	tree[now][x*2+1].sum=(1ll<<now)*(r-mid)-tree[now][x*2+1].sum;
	    	tree[now][x*2].tag+=tree[now][x].tag;tree[now][x*2+1].tag+=tree[now][x].tag;
		}
    tree[now][x].tag=0;
}
void build(int now,int x,int l,int r)
{
	if (l==r)
	   { 
	   tree[now][x].sum=a[l]&(1<<now);
	   return ;
	   }
    int mid=(l+r)/2;
    build(now,x*2,l,mid);build(now,x*2+1,mid+1,r);
    pushup(now,x);
}
long long query(int now,int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr)) return tree[now][x].sum;
	int mid=(l+r)/2;
	long long ans=0;
	pushdown(now,x,l,r);
	if (mid>=tl) ans+=query(now,x*2,l,mid,tl,tr);
    if (mid<tr) ans+=query(now,x*2+1,mid+1,r,tl,tr);
    pushup(now,x);
    return ans;
}

void modify(int now,int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr))
	    { 
	    tree[now][x].sum=(1ll<<now)*(r-l+1)-tree[now][x].sum;
	    tree[now][x].tag++;
	    return ;
		}
	int mid=(l+r)/2;
	pushdown(now,x,l,r);
	if (mid>=tl) modify(now,x*2,l,mid,tl,tr);
    if (mid<tr) modify(now,x*2+1,mid+1,r,tl,tr);
    pushup(now,x);
}
int main()
{
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (now=0;now<=20;now++)
	      build(now,1,1,n);
	for (T=read();T;T--)
	    {
	    	opt=read();
	    	if (opt==1)
	    	    {
	    	    	l=read();r=read();
	    	    	ans=0;
	    	    	for (now=0;now<=20;now++) ans+=query(now,1,1,n,l,r);
	    	    	printf("%lld\n",ans);
				}
		else
		     {
		       l=read();r=read();x=read();
		       for (now=0;now<=20;now++)
		           if (x&(1<<now))
                       modify(now,1,1,n,l,r);
  			 }
		}
	return 0;
}