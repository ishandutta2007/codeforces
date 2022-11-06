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
	long long sum,mn,tag1,tag2;
} tree[4000000];
long long X,tot,now,n,K,a[1001000],b[1001000],L,R,lft,rit,mid,i;
void build(int l,int r,int x)
{
	tree[x].tag1=1000000000;tree[x].sum=r-l+1;tree[x].mn=1000000000;
	if (l==r) return ;
	int mid=(l+r)/2;
	build(l,mid,x*2);
	build(mid+1,r,x*2+1);
}
void pushdown(int x,int l,int r)
{
	if (tree[x].tag2==1)
	     {
	     	tree[x*2].sum=0;tree[x*2].tag2=tree[x].tag2;
	     	tree[x*2+1].sum=0;tree[x*2+1].tag2=tree[x].tag2;
		 }
	tree[x*2].mn=min(tree[x*2].mn,tree[x].tag1);
	tree[x*2+1].mn=min(tree[x*2+1].mn,tree[x].tag1);
	tree[x*2].tag1=min(tree[x*2].tag1,tree[x].tag1);
	tree[x*2+1].tag1=min(tree[x*2+1].tag1,tree[x].tag1);
	tree[x].tag2=0;
}
void pushup(int x)
{
	tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
	tree[x].mn=min(tree[x*2].mn,tree[x*2+1].mn);
}
void modify(int l,int r,int x,int tl,int tr,long long val)
{
	if ((l>=tl)&&(r<=tr))
	      {
	      	tree[x].tag1=min(tree[x].tag1,val);tree[x].tag2=1;tree[x].sum=0;tree[x].mn=min(tree[x].mn,val);
	      	return;
		  }
	pushdown(x,l,r);
	int mid=(l+r)/2;
	if (tl<=mid) modify(l,mid,x*2,tl,tr,val);
	if (tr>mid) modify(mid+1,r,x*2+1,tl,tr,val);
	pushup(x);
}
int query_sum(int l,int r,int x,int tl,int tr)
{
	if (tl>tr) return 0;
	if ((l>=tl)&&(r<=tr)) return tree[x].sum;
	pushdown(x,l,r);
	int mid=(l+r)/2,ans=0;
	if (tl<=mid) ans+=query_sum(l,mid,x*2,tl,tr);
	if (tr>mid) ans+=query_sum(mid+1,r,x*2+1,tl,tr);
	pushup(x);
	return ans;
}
int query_min(int l,int r,int x,int tl,int tr)
{
	if (tl>tr) return 0;
	if ((l>=tl)&&(r<=tr)) return tree[x].mn;
	pushdown(x,l,r);
	int mid=(l+r)/2,ans=1000000000;
	if (tl<=mid) ans=min(ans,query_min(l,mid,x*2,tl,tr));
	if (tr>mid) ans=min(ans,query_min(mid+1,r,x*2+1,tl,tr));
	pushup(x);
	return ans;
}
int main()
{
n=read();K=read();
for (i=1;i<=n;i++) a[i]=read(),b[a[i]]=i;
build(1,n,1);
for (now=n;now>=1;now--)
    if (query_min(1,n,1,b[now],b[now])==1000000000)
      {
      	
      	      {
      	  lft=1;rit=max(b[now]-K,(long long )1);L=b[now];tot++;
      	  while (lft<=rit)
      	       {
      	       	mid=(lft+rit)/2;X=query_sum(1,n,1,mid,b[now]-1);
      	       	if (X<=K)
      	       	       {
      	       	       	L=mid;rit=mid-1;
      	       	      	if (X==K) break;
					   }
				else lft=mid+1;
			}
	      }
	        {
		   lft=min(b[now]+K,n);rit=n;R=b[now];
      	  while (lft<=rit)
      	       {
      	       	mid=(lft+rit)/2;X=query_sum(1,n,1,b[now]+1,mid);
      	       	if (X<=K)
      	       	       {
      	       	       	R=mid;lft=mid+1;
      	       	      	if (X==K) break;
					   }
				else rit=mid-1;
				 }
		   }
			modify(1,n,1,L,R,tot);
	  }
for (i=1;i<=n;i++)
    if (query_min(1,n,1,i,i) % 2==1) printf("1");else printf("2");
puts("");
return 0;
}