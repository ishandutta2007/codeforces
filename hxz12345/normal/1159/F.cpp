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
	long long x,y;
} a[1010100];
int q[1010100];
bool vis[1010100];
long long minx,miny,mn,mx;
int j,n,i,id;
string s;
long long VectorProduct(long long a,long long b,long long c,long long d)
{
	return (a*d-b*c);
}
int main()
{
	//part 1 
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>n;
	minx=1000000000;miny=1000000000;
	for (i=1;i<=n;i++)
	    {
	       cin>>a[i].x>>a[i].y;
	       if ((a[i].x<minx)||((a[i].x==minx)&&(a[i].y<miny)))
	            {
	            	minx=a[i].x;miny=a[i].y;id=i;
				}
		}
	cin>>s;
	q[1]=id;vis[id]=true;
	for (i=1;i<=n-2;i++)
	     {
	     	   if (s[i-1]=='L')
	     	       {
			     for (j=1;j<=n;j++)
			         if (vis[j]==false)
			             {
			             	if (q[i+1]==0) 
			             	    {
			             	    	q[i+1]=j;continue;
								 }
							if (VectorProduct(a[j].x-a[q[i]].x,a[j].y-a[q[i]].y,a[q[i+1]].x-a[q[i]].x,a[q[i+1]].y-a[q[i]].y)>0)
							      q[i+1]=j;
						 }
					}
			else
			     { 
			     for (j=1;j<=n;j++)
			         if (vis[j]==false)
			            {
			            	
			             	if (q[i+1]==0) 
			             	    {
			             	    	q[i+1]=j;continue;
								 }
							if (VectorProduct(a[j].x-a[q[i]].x,a[j].y-a[q[i]].y,a[q[i+1]].x-a[q[i]].x,a[q[i+1]].y-a[q[i]].y)<0)
							      q[i+1]=j;
						}
				 }
				vis[q[i+1]]=true;
	      }
	for (i=1;i<=n;i++)
	    if (vis[i]==false) q[n]=i;
	for (i=1;i<=n;i++)printf("%d ",q[i]);
	puts("");
   return 0;
}