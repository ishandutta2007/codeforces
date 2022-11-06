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
	int sum,change;
};
hxz tree[2000000];
bool exist[2000000];
int e[2000000];
int x,n,T,i;
int find(int l,int r,int x,int K)
{
	if (l==r) return l;
	int tot;
	int mid=(l+r)/2;
	if (exist[x*2]) 
	    {
	    	tree[x].change=tree[x*2].change+tree[x*2+1].change;
	    	tot=tree[x*2].sum-tree[x*2].change;
	    	if (tot<K) return find(mid+1,r,x*2+1,K-tot);
	    	else return find(l,mid,x*2,K);
		}
	else
	     {
	     	tree[x].change=tree[x*2].change+tree[x*2+1].change;
	     	cout<<"?"<<" "<<l<<" "<<mid<<endl;
	     	cin>>tree[x*2].sum;tree[x*2].sum=mid-l+1-tree[x*2].sum+tree[x*2].change;exist[x*2]=true;
	     	tot=tree[x*2].sum-tree[x*2].change;
	     	cout.flush();
	     	if (tot<K) return find(mid+1,r,x*2+1,K-tot);
	    	else return find(l,mid,x*2,K);
		 }
}
void modify(int l,int r,int x,int tl,int tr,int val)
{
	if ((l>=tl)&&(r<=tr)) 
	    {
	    	tree[x].change++;return;
		}
	int mid=(l+r)/2;
	if (mid>=tl) modify(l,mid,x*2,tl,tr,val);
	if (tr>mid) modify(mid+1,r,x*2+1,tl,tr,val);
	tree[x].change=tree[x*2].change+tree[x*2+1].change; 
}
int main()
{
	n=read();T=read();
	for (i=1;i<=T;i++)
	     {
	     	e[i]=read();
	     	x=find(1,n,1,e[i]);
	     	cout<<"!"<<" "<<find(1,n,1,e[i])<<endl;
	     	modify(1,n,1,x,x,1);
	     	cout.flush();
		 }
   return 0;
}