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
struct node{
	long long id,lft,rit;
} a[1010100],g[1010100];
long long R,l,r,n,Q,i,L,c[1010100],f[1010100],e[1010100],Answer[1010100],len,fre[1010100],mid,ans;
bool cmp(node a,node b)
{
	return (a.lft<b.lft);
}
bool cmp1(node a,node b)
{
	return (a.lft>b.lft);
}
//f[i]  i  
int main()
{
	n=read();Q=read();
	for (i=1;i<=n;i++) e[i]=read();
	for (i=1;i<=Q;i++) a[i].lft=read(),a[i].rit=read(),a[i].id=i;
	sort(a+1,a+Q+1,cmp);L=1;
	for (i=1;i<=n;i++) f[i]=2e9;
	for (i=1;i<=n;i++)
	   {
	   	while ((a[L].lft==i)&&(L<=Q))
	   	        {
	   	        	l=1;r=len;ans=0;
	   	        	while (l<=r)
	   	        	    { 
	   	        	    mid=(l+r)/2;
	   	        	    if (a[L].rit>f[mid]) ans=mid,l=mid+1;
	   	        	    else r=mid-1;
					    }
					c[a[L].id]=ans+1;L++;
				   }
		if (e[i]>f[len]) f[++len]=e[i],g[i].lft=len;
		else
		  {
		  	   l=1;r=len;ans=0;
		  	   while (l<=r)
		  	       {
		  	       	mid=(l+r)/2;
		  	       	if (e[i]>f[mid]) ans=mid,l=mid+1;
		  	       	else r=mid-1;
					 }
			   f[ans+1]=e[i];g[i].lft=ans+1;
		  }
       }
    R=Q;
	for (i=1;i<=n;i++) f[i]=2e9;
	for (i=n;i>=1;i--)
	    {
	    	 while ((a[R].lft==i)&&(R))
	    	      {
	    	      	l=1;r=len;ans=0;
	   	        	while (l<=r)
	   	        	    { 
	   	        	    mid=(l+r)/2;
	   	        	    if ((-a[R].rit)>f[mid]) ans=mid,l=mid+1;
	   	        	    else r=mid-1;
					    }
					Answer[a[R].id]=c[a[R].id]+ans;R--;
					
				  }
			if ((-e[i])>f[len]) f[++len]=-e[i],g[i].rit=len;
		else
		  {
		  	   l=1;r=len;ans=0;
		  	   while (l<=r)
		  	       {
		  	       	mid=(l+r)/2;
		  	       	if ((-e[i])>f[mid]) ans=mid,l=mid+1;
		  	       	else r=mid-1;
					 }
			   f[ans+1]=(-e[i]);g[i].rit=ans+1;
		  }
		}
   for (i=1;i<=n;i++)
       if (g[i].lft+g[i].rit>len) fre[g[i].lft]++;
    for (i=1;i<=Q;i++)
        if ((g[a[i].lft].lft+g[a[i].lft].rit<=len)||(fre[g[a[i].lft].lft]>1)||(fre[g[a[i].lft].lft]==0)) Answer[a[i].id]=max(Answer[a[i].id],len);
        else Answer[a[i].id]=max(Answer[a[i].id],len-1);
    for (i=1;i<=Q;i++) printf("%lld\n",Answer[i]);
    return 0;
}