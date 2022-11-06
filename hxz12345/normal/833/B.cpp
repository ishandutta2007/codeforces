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
long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
		if (y&1) ans=ans*x % p;
	return ans;
}
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
struct hxz{
	int tag,mx;
} tree[4010000];
int a[101000],pre[1010000],e[1010000],f[1010000],n,i,K; 
void Clear(int l,int r,int x)
{
	tree[x].mx=tree[x].tag=0;
	if (l==r) return;
	int mid=(l+r)/2;
	Clear(l,mid,x*2);Clear(mid+1,r,x*2+1);
}
void pushdown(int x)
{
	tree[x*2].mx+=tree[x].tag;tree[x*2+1].mx+=tree[x].tag;
	tree[x*2].tag+=tree[x].tag;tree[x*2+1].tag+=tree[x].tag;
	tree[x].tag=0;
}
void pushup(int x)
{
	tree[x].mx=max(tree[x*2].mx,tree[x*2+1].mx);
}
void modify(int l,int r,int x,int tl,int tr,int val)
{
	if (tl>tr) return ;
	if (l>r) return;
	if ((l>=tl)&&(r<=tr))
	     {
	     	tree[x].tag+=val;tree[x].mx+=val;
	     	return ;
		 }
	pushdown(x);
	int mid=(l+r)/2;
	if (tl<=mid) modify(l,mid,x*2,tl,tr,val);
	if (tr>mid) modify(mid+1,r,x*2+1,tl,tr,val);
	pushup(x);
}
int query_max(int l,int r,int x,int tl,int tr)
{
	if (tl>tr) return 0;
	if ((l>=tl)&&(r<=tr)) return tree[x].mx;
	pushdown(x);
	int mid=(l+r)/2,ans=0;
	if (tl<=mid) ans=max(ans,query_max(l,mid,x*2,tl,tr));
	if (tr>mid) ans=max(ans,query_max(mid+1,r,x*2+1,tl,tr));
	pushup(x);
	return ans;
}
int main()
{
	n=read();K=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++)
	     {
	     	if (pre[a[i]]==0) e[i]=e[i-1]+1;else e[i]=e[i-1];pre[a[i]]=i;
		 }
	for (;K>1;K--)
	    {
	    	for (i=1;i<=n;i++) pre[i]=0;Clear(1,n,1);
	    	for (i=1;i<=n;i++)
	    	    {
	    	       modify(1,n,1,max(pre[a[i]],1),i-1,1);
				   f[i]=query_max(1,n,1,1,i-1);
				   modify(1,n,1,i,i,e[i]);pre[a[i]]=i;
				}
			for (i=1;i<=n;i++) e[i]=f[i];
		}
	printf("%d\n",e[n]);
return 0;
}