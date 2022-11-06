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
long long start,T,n,nx,ny,i,a[1010000],b[1010000],c[1010000],pre_1[1010000],pre_2[1010000],suf_1[1010000],suf_2[1010000];
long long x,X;
bool flag,flag_1,flag_2;
int main()
{
	T=read();
	for (;T;T--)
	   {
	   	n=read();nx=0;ny=0;
	   	for (i=1;i<=n;i++) a[i]=read();
	   	for (i=1;i<=n;i++)
	   	    {
	   	    	if (i % 2==1) {nx++;b[nx]=b[nx-1]+a[i];}
				else {ny++;c[ny]=c[ny-1]+a[i];}
			}
		flag_1=true;flag_2=(b[nx]==c[ny]);
		for (i=1;i<=nx;i++)
		     {
		     	if ((i<=ny)&&(c[i]<b[i])){flag_1=false;break;}
				if ((i>1)&&(c[i-1]>b[i])){flag_1=false;break;} 
			 }
		//c[x-1]<=b[x]+K
		//
		/*	1 3 1 1 2
			0 2 1 1 2
			a[3]-a[2]+a[1]>=0*/
		//b[2]-c[1]
		//part1
		//b[x]<=c[x]
		//c[x-1]<=b[x]-K<=c[x]+K
		//b[x]-c[x]<=2*K
		//part2
		//      b[x-1]+<=c[x-1]
		
		if (ny==nx) suf_1[ny]=-2000000000000000000;
		else suf_1[ny]=c[ny]-b[nx];
		for (i=ny-1;i>=1;i--) suf_1[i]=max(suf_1[i+1],c[i]-b[i+1]);
		suf_2[ny]=b[ny]-c[ny];suf_2[ny+1]=-2000000000000000000;
		for (i=ny-1;i>=1;i--) suf_2[i]=max(suf_2[i+1],b[i]-c[i]); 
		pre_1[1]=b[1]-c[1];
		for (i=2;i<=ny;i++) pre_1[i]=max(pre_1[i-1],b[i]-c[i]);
		if ((ny==1)&&(nx==1)) pre_2[1]=-2000000000000000000;
		else pre_2[1]=c[1]-b[2];
		for (i=2;i<=ny;i++) pre_2[i]=max(pre_2[i-1],c[i]-b[i+1]);
		if (ny==nx) pre_2[ny]=-2000000000000000000;
		/*c[x]>=b[x]
		c[x-1]<=b[x]
		c[x-1]<=b[x]-K<=c[x]+K
		//b[x-1]<=c[x]-K
		//pre_1[x-1]pre_2x-2 
		b[x-1]-K<=c[x-1]
		b[x-1]-c[x-1]<=K
		b[x]+K<=c[x]-K<=b[x+1]+K*/
		//b[x]-c[x]<=0
		//c[x]-b[x+1]<=0
		//c[x-1]-b[x]<=0
		//b[x]-c[x]<=-2K
		//c[x]-b[x+1]<=2K
		//
		// b[x]-K<=c[x]+K<=b[x+1]-K
		// b[x]-c[x]<=2K
		//b[x]+K<=c[x]-K<=b[x+1]-
		//c[x-1]<=b[x]+K
		//c[x]-b[x+1]<=-2K 
		// 
		// 
		//c[x] b[x+1]
		//b[x]<=c[x]-K<=b[x+1]+K
		//c[x-1]<=b[x]+K
		//c[1]<=b[2]
		//c[x-1]<=b[x]+K
		//c[x-1]-b[x]<=-K
		//c[x-2]-b[x-1]<=0
		//b[x]<=c[x]-K
		//b[x]-c[x]
		//b[x]<=c[x]-K<=b[x+1]+K
		//b[x+1]+K<=c[x+1]-K
		//b[x+1]-c[x+1]<=-2*K
		//1 1 2
		//b[x]<=c[x]-K
		//b[x]-c[x]<=-K
		//1 1 2
		//a[2]>=a[1]
		//c[x]+K<=b[x+1]-K
		//b[x]<=c[x]+K
		//c[x-1]<=b[x]-K
		//c[x-1]<=b[x]-K
		//c[x]+K<=b[x+1]-K
		//b[x+1]-K<=c[x+1]+K
		//c[x-1]<=b[x]-K
		
		if ((flag_1)&&(flag_2)) puts("YES");
		else if ((b[nx]-c[ny]) % 2!=0) puts("NO");
		else 
		    {
		    	X=b[nx]-c[ny];
				flag=false;
		    	//for (i=1;i<n;i++)
		    	for (i=1;i<n;i++)
		    	   if (i % 2==1)
		    	      {
		    	      	  x=2*a[i]-2*a[i+1];
		    	      	  if (x!=X) continue;
		    	      	  x=a[i]-a[i+1];
		    	      	  start=(i+1)/2;
		    	      	  //lft=start*2-1,rit=start*2
		    	      	  //b[start],c[start] 
		    	      	  if (suf_2[start]>2*x) continue;
		    	      	  if (suf_1[start]>-2*x) continue;
		    	      	  if ((start!=1)&&(c[start-1]-b[start]>-x)) continue;
		    	      	  if (pre_1[start-1]>0) continue;
		    	      	  if (pre_2[max(start-2,(long long)0)]>0) continue;
		    	      	  flag=true;
		    	      	  
					  }
				else
				    {
				    	 x=2*a[i+1]-2*a[i];
				    	 if (x!=X) continue;
				    	 x=a[i+1]-a[i];start=i/2;
				    	 if (suf_2[start+1]>2*x) continue;
				    	 if (suf_1[start]>-2*x) continue;
		    	      	  if (b[start]-c[start]>x) continue;
				    	 if (pre_1[start-1]>0) continue;
				    	 if (pre_2[start-1]>0) continue;
				    	 flag=true;
					}
				if (flag) puts("YES");
				else puts("NO");
			 } 
	   }
    return 0;
}