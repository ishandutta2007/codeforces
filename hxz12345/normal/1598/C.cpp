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
long long n,mid,Testing ,a[1001010],tot,lft,rit,now,sum,L,R,i;
int main()
{
	Testing=read();
	for (;Testing;Testing--)
	   { 
	   n=read();tot=0;
	   for (i=1;i<=n;i++) a[i]=read(),tot+=a[i];
	   if ((2*tot) % n!=0) puts("0");
	   else
	       { 
	           now=2*tot/n;
	           sort(a+1,a+n+1);sum=0;
	           a[0]=-1;a[n+1]=-1;
	           for (i=1;i<=n;i++)
	               { 
	                 lft=1;rit=n;L=0;R=0;
	                 if (now-a[i]<0) continue;
	                 while (lft<=rit)
	                     {
	                     	 mid=(lft+rit)/2;
	                     	 if (a[mid]>=now-a[i])
	                     	    { 
	                     	    L=mid;rit=mid-1;
								 }
							else lft=mid+1;
						 }
						lft=1;rit=n;
					while (lft<=rit)
	                     {
	                     	 mid=(lft+rit)/2;
	                     	 if (a[mid]<=now-a[i])
	                     	    { 
	                     	    R=mid;lft=mid+1;
								 }
							else rit=mid-1;
						 }
					if ((L<=R)&&(a[L]==now-a[i])) sum+=R-L+1;
				   }
		    for (i=1;i<=n;i++)
		       if (2*a[i]*n==2*tot)
		            sum--;
		    sum/=2;
		    printf("%lld\n",sum);
		   }
	   }
	return 0;
}