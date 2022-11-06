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
	int x,y,id;
} a[100000];
int ans,w,f[101000],c[101000],e[101000],tem,W,H,x,y,i,n,j,lst;
bool cmp(hxz a,hxz b)
{
	return ((a.x<b.x)||((a.x==b.x)&&(a.y<b.y)));
}
int main()
{
	tem=read();W=read();H=read();
	for (i=1;i<=tem;i++)
	    {
	    	x=read();y=read();
	    	if ((x>W)&&(y>H)){a[++n].x=x;a[n].y=y;a[n].id=i;}
		}
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++)
	     {
	     	f[i]=1;e[i]=0;
	     	for (j=1;j<i;j++)
	     	   if ((a[i].x>a[j].x)&&(a[i].y>a[j].y)&&(f[j]+1>f[i]))
	     	        {
	     	        	f[i]=f[j]+1;e[i]=j;
					 }
			if (f[i]>ans)
			   {
			   	ans=f[i];lst=i;
			   }
		 }
	printf("%d\n",ans);
	for (;lst;lst=e[lst]) c[++w]=a[lst].id;
	for (i=w;i>=1;i--) printf("%d ",c[i]);
    return 0;
}