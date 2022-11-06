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
long long i,ext,lft,rit,final,n,A,R,M,a[1010000],pre[1010000],ans;
int main()
{
	n=read();A=read();R=read();M=read();
	for (i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for (i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    //lft rit mn=min(lft,rit)
    //M>=A+R mn*M>=mn*(A+R) wyy
    //M<A+R  mn*M+(lft-mn)*A+(rit-mn)*R
    //mn*(M-A-R)+lft*A+rit*R;
    //lft+rit   mn 
    ans=1e18;
	for (i=1;i<=n;i++) 
	     {
	     	final=a[i];
		 ans=min(ans,(a[i]*i-pre[i])*A+(-a[i]*(n-i)+pre[n]-pre[i])*R);
		 
					      	lft=final*i-pre[i];rit=lft+pre[n]-final*n;
					      	ans=min(ans,min(lft,rit)*M+(lft-min(lft,rit))*A+(rit-min(lft,rit))*R);}
	 // 0~a[1] lft=pre[n]-final*n rit=0,mn=0;
	 //3 5 5 5 6
	  {
	     	ext=pre[n]/n;
	     	for (i=1;i<n;i++)  
	     	    {
					  if ((ext>=a[i])&&(ext<=a[i+1]))
					      {
					      	final=ext;
					      	lft=final*i-pre[i];rit=lft+pre[n]-final*n;
					      	ans=min(ans,min(lft,rit)*M+(lft-min(lft,rit))*A+(rit-min(lft,rit))*R);
						  }
				 }
				ext=pre[n]/n;ext++;
	     	for (i=1;i<n;i++)  
	     	    {
					  if ((ext>=a[i])&&(ext<=a[i+1]))
					      {
					      	final=ext;
					      	lft=final*i-pre[i];rit=lft+pre[n]-final*n;
					      	ans=min(ans,min(lft,rit)*M+(lft-min(lft,rit))*A+(rit-min(lft,rit))*R);
						  }
				 }
				ext=pre[n]/n;ext--;
	     	for (i=1;i<n;i++)  
	     	    {
					  if ((ext>=a[i])&&(ext<=a[i+1]))
					      {
					      	final=ext;
					      	lft=final*i-pre[i];rit=lft+pre[n]-final*n;
					      	ans=min(ans,min(lft,rit)*M+(lft-min(lft,rit))*A+(rit-min(lft,rit))*R);
						  }
				 }
		 }
	printf("%lld\n",ans);
    return 0;
}