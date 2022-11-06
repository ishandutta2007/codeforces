#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  while(ch=='-')f=-1,ch=getchar();
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
struct node{
	long long lft,rit,val;
} a[1001010];
struct charm{
	long long val,id;
}b[1001010];
long long i,r1,r2,n,m,lft,ans[1001010],sum,f[1001010],e[1001010];
bool cmp(node a,node b){return a.val<b.val;}
bool cmp1(charm a,charm b){return a.val<b.val;}
int find(int x)
{
	if (f[x]!=x) f[x]=find(f[x]);return f[x];
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();m=read();
	for (i=1;i<=n-1;i++) a[i].lft=read(),a[i].rit=read(),a[i].val=read();
	sort(a+1,a+n,cmp);
	for (i=1;i<=m;i++) b[i].val=read(),b[i].id=i;
	sort(b+1,b+m+1,cmp1);
	lft=1;
	for (i=1;i<=n;i++) f[i]=i,e[i]=1;
	for (i=1;i<=m;i++)
	    {
	    	while ((lft<n)&&(a[lft].val<=b[i].val))
	    	     {
	    	     	r1=find(a[lft].lft);r2=find(a[lft].rit);
	    	     	sum+=e[r2]*e[r1];
	    	     	f[r1]=r2;e[r2]+=e[r1];
					lft++;
			      }
			ans[b[i].id]=sum;
		}
	for (i=1;i<=m;i++) printf("%lld ",ans[i]);
    return 0;
}