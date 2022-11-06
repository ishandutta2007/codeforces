#include<bits/stdc++.h>
using namespace std;
long long e[1000000],a[1000000],b[1000000];
long long i,n,m,w,l,r,mid,ans;
int lowbit(int x)
{
	return x & -x;
}
long long query(int x)
{
	long long ans=0;
	for (;x;x-=lowbit(x))
	   ans+=e[x];
	return ans;
}
void modify(int x,long long y)
{
	for (;x<=n;x+=lowbit(x))
	     e[x]+=y;
}
bool check(long long mid)
{
	int i;
	long long x,sum=0;
	for (i=1;i<=n;i++) e[i]=0;
	for (i=1;i<=n;i++)
	    if (a[i]<mid) b[i]=mid-a[i];
	else b[i]=0;
	for (i=1;i<=n;i++)
	   {
	   	  x=b[i]-query(i);
	   	  if (x>0) 
	   	     {
	   	     	sum+=x;modify(i,x);modify(min(n+1,i+w),-x);
			 }
	   }
	return (sum<=m);
}
int main()
{
	cin>>n>>m>>w;
	for (i=1;i<=n;i++) cin>>a[i];
	l=1;r=10000000000000;
	while (l<=r)
	     {
	     	mid=(l+r)/2;
	     	if (check(mid))
	     	     {
	     	     	ans=mid;l=mid+1;
				  }
		else r=mid-1;
		 }
	cout<<ans<<endl;
	return 0;
}