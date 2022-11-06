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
struct node{
	long long mn,sum,ans,tag;
} tree[5010100];
struct data1{
	long long l,r,val;
} a[601010];
long long R,L,l,r,ans,n,m,i;
bool cmp(data1 a,data1 b)
{
	return (a.val<b.val);
}
void pushup(int x,int l,int r)
{
	int mid=(l+r)/2;
    tree[x].mn=min(tree[x*2].mn,tree[x*2+1].mn);
	tree[x].sum=0;
	if (tree[x*2].mn==tree[x].mn) tree[x].sum+=tree[x*2].sum;
	if (tree[x*2].mn==tree[x].mn) tree[x].sum+=tree[x*2+1].sum;
}
void pushdown(int  x,int l,int r)
{
tree[x*2].mn+=tree[x].tag;tree[x*2+1].mn+=tree[x].tag;
tree[x*2].tag+=tree[x].tag;tree[x*2+1].tag+=tree[x].tag;
tree[x].tag=0;
}
void modify(int x,int l,int r,int tl,int tr,int val)
{
	//if ((L==10)&&(R==11)) cout<<"tag:"<<l<<" "<<r<<endl;
	if ((l>=tl)&&(r<=tr))
	      {
	      	  tree[x].mn+=val;tree[x].tag+=val;
				pushdown(x,l,r);pushup(x,l,r);
		      return ;
	     }
	pushdown(x,l,r);
	int mid=(l+r)/2;
	if (mid>=tl) modify(x*2,l,mid,tl,tr,val);
	if (mid<tr) modify(x*2+1,mid+1,r,tl,tr,val);
	pushup(x,l,r);
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();m=read();m--;
	for (i=1;i<=n;i++) a[i].l=read(),a[i].r=read(),a[i].val=read();
	sort(a+1,a+n+1,cmp);
	r=0;ans=1e9;
	for (l=1;l<=n;l++)
	     {
	        while ((r<n)&&(tree[1].mn==0))
			      {
			      	r++;
					  modify(1,1,m,a[r].l,a[r].r-1,1);
					   }
			if (tree[1].mn==0) break;
			ans=min(ans,a[r].val-a[l].val);
			L=a[l].l;R=a[l].r-1;
			modify(1,1,m,a[l].l,a[l].r-1,-1);
		 }
	printf("%d\n",ans);
 return 0;
}