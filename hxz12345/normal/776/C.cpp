#include<bits/stdc++.h>
using namespace std;
struct hxz{
	long long x;
	int id;
};
hxz a[200000];
long long x,frequency,m,tot,l,r,mid,lft,rit,ans,sum,n,i;
inline int read()			
{
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
bool cmp(hxz a,hxz b)
{
	return ((a.x<b.x)||((a.x==b.x)&(a.id<b.id)));
}
int main()
{
    n=read();m=read();
	for (i=1;i<=n;i++) 
	     {
	     	x=read();a[i].x=a[i-1].x+x;a[i].id=i;
		}	
    n++;
	sort(a+1,a+n+1,cmp);
        	tot=1;frequency=0;
        	while ((tot>=-100000000000000)&(tot<=100000000000000))
        	      {
        	      	frequency++;
        	      	if ((m==-1))
        	      	    {
        	      	    if (frequency>2) break;
        	      	    }
        	      	if (m==1)
        	      	     {
        	      	         if (frequency>1) break;
        	      	     }
        	      	if (tot>0)
        	      	    {
        	      	    	for (i=1;i<=n;i++)
        	      	    	    {
        	      	    	    	l=1;r=i-1;lft=-1;rit=-1;
        	      	    	    	while (l<=r)
        	      	    	    	    {
        	      	    	    	    	mid=(l+r)/2;
        	      	    	    	    	if (a[i].x-a[mid].x==tot)
        	      	    	    	    	     {
        	      	    	    	    	     	lft=mid;r=mid-1;
												   }
											else if (a[i].x-a[mid].x>tot) l=mid+1;
											else r=mid-1;
										  }
									l=1;r=i-1;
        	      	    	    	while (l<=r)
        	      	    	    	    {
        	      	    	    	    	mid=(l+r)/2;
        	      	    	    	    	if (a[i].x-a[mid].x==tot)
        	      	    	    	    	     {
        	      	    	    	    	     	rit=mid;l=mid+1;
												   }
											else if (a[i].x-a[mid].x>tot) l=mid+1;
											else r=mid-1;
										  }
									if (lft!=-1)
									    {
									l=lft;r=rit;ans=-1;
									while (l<=r)
									     {
									     	mid=(l+r)/2;
									     	if (a[mid].id<a[i].id)
									     	    {
									     	    	ans=mid;l=mid+1;
												 }
											else r=mid-1;
										 }
									
									if (ans!=-1) sum+=(ans-lft+1);
									}
								  }
						  }
					else
					      {
					      	for (i=1;i<=n;i++)
        	      	    	    {
        	      	    	    	l=1;r=i-1;lft=-1;rit=-1;
        	      	    	    	while (l<=r)
        	      	    	    	    {
        	      	    	    	    	mid=(l+r)/2;
        	      	    	    	    	if (a[i].x-a[mid].x==(-tot))
        	      	    	    	    	     {
        	      	    	    	    	     	lft=mid;r=mid-1;
												   }
											else if (a[i].x-a[mid].x>(-tot)) l=mid+1;
											else r=mid-1;
										  }
									l=1;r=i-1;
        	      	    	    	while (l<=r)
        	      	    	    	    {
        	      	    	    	    	mid=(l+r)/2;
        	      	    	    	    	if (a[i].x-a[mid].x==(-tot))
        	      	    	    	    	     {
        	      	    	    	    	     	rit=mid;l=mid+1;
												   }
											else if (a[i].x-a[mid].x>(-tot)) l=mid+1;
											else r=mid-1;
										  }
									if (lft!=-1)
									    {
									l=lft;r=rit;ans=-1;
									while (l<=r)
									     {
									     	mid=(l+r)/2;
									     	if (a[mid].id>a[i].id)
									     	    {
									     	    	ans=mid;r=mid-1;
												 }
											else l=mid+1;
										 }
									if (ans!=-1) sum+=(rit-ans+1);
									}
								  }
						  }
        	      	tot=tot*m;
				 }
	printf("%lld\n",sum);
	return 0;
}