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
long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
	    if (y&1) ans=ans*x % p;
	return ans;
}
long long j,lst,sum,x,A[101001],M,tot,dom,fac[1001010],fre[1001010],ifac[1001010],n,i,a[100101],MOD;
int main()
{
	n=read();
	for (x=n;x;x/=10) fre[x%10]++;
	n=19;
	fac[0]=1;
	for (i=1;i<=n;i++) fac[i]=fac[i-1]*i ;
	for (i=0;i<=9;i++)
	     A[++M]=i;
	for (a[0]=0;a[0]<=fre[0];a[0]++)
	     if ((a[0]!=0)||(fre[0]==0))
	         
	for (a[1]=0;a[1]<=fre[1];a[1]++)
	     if ((a[1]!=0)||(fre[1]==0))
	        
	for (a[2]=0;a[2]<=fre[2];a[2]++)
	     if ((a[2]!=0)||(fre[2]==0))
	     
	for (a[3]=0;a[3]<=fre[3];a[3]++)
	     if ((a[3]!=0)||(fre[3]==0))
	     
	for (a[4]=0;a[4]<=fre[4];a[4]++)
	     if ((a[4]!=0)||(fre[4]==0))
	     
	for (a[5]=0;a[5]<=fre[5];a[5]++)
	     if ((a[5]!=0)||(fre[5]==0))
	     
	for (a[6]=0;a[6]<=fre[6];a[6]++)
	     if ((a[6]!=0)||(fre[6]==0))
	     
	for (a[7]=0;a[7]<=fre[7];a[7]++)
	     if ((a[7]!=0)||(fre[7]==0))
	     
	for (a[8]=0;a[8]<=fre[8];a[8]++)
	     if ((a[8]!=0)||(fre[8]==0))
	     
	for (a[9]=0;a[9]<=fre[9];a[9]++)
	     if ((a[9]!=0)||(fre[9]==0))
	         { 
	         if (fre[0]==0)
	            { 
	            tot=0;
	            for (i=1;i<=M;i++) 
				    
					tot+=a[A[i]];dom=fac[tot];
				for (i=1;i<=M;i++)	for (j=1;j<=a[A[i]];j++) dom/=j;
				    
	            sum=(sum+dom ) ;
				}
			else 
			    {
			    	tot=0;
	                 for (i=1;i<=M;i++)  tot+=a[A[i]];
						 dom=fac[tot];
					for (i=1;i<=M;i++)	 for (j=1;j<=a[A[i]];j++) dom/=j;
					     
			    	for (i=1;i<=M;i++)
			    	   if (A[i]!=0)
			    	    	sum=sum+(dom*a[A[i]]/tot);
				}
			 }
	printf("%lld\n",sum);
	return 0;
}