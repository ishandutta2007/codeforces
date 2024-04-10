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
struct node{
	int val,id;
} u[1010100];
bool flag;
int T,j,dep2[1010100],dep[1010100],father[1010100],exist[1010100],siz[1010100],a[1010100],b[1010100],d[1010100],cnt,n,i,x,y,dif[1010100];
void add(int x,int y)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
bool sc(int x,int fa,int rt)
{
	siz[x]=1;
	int id=0;
	for (int i=d[x];i;i=b[i])
	     if (a[i]!=fa)
	         {
	         	sc(a[i],x,rt);siz[x]+=siz[a[i]];dep[x]=max(dep[x],dep[a[i]]);
	         	if (siz[a[i]]<=n/2) dep[x]=max(dep[x],siz[a[i]]);
	         	else 
				     {
					 id=a[i];u[x].val=siz[a[i]];u[x].id=a[i];
				     }
			 }
	int fre=0;
	for (int i=d[x];i;i=b[i])
	       if (a[i]!=fa)
	           {
	           	int now=dep[a[i]];
	           	if (siz[a[i]]<=n/2) now=siz[a[i]];
	           	if (now==dep[x]) fre++;
			   }
	if (fre>1) dep2[x]=dep[x];
	for (int i=d[x];i;i=b[i])
	       if (a[i]!=fa)
	           {
	           	int now=dep[a[i]];
	           	if (siz[a[i]]<=n/2) now=siz[a[i]];
	           	if (now!=dep[x]) dep2[x]=max(dep2[x],now);
			   }
	if ((x==rt)&&(id==0)) flag=true;
	if ((x==rt)&&(id!=0)) if (siz[id]-n/2<=dep[id]) flag=true;
}
void sc_change(int x,int fa)
{
	int X;
	for (int i=d[x];i;i=b[i])
	      if (a[i]!=fa)
	          {
	             int now=dep[a[i]];
	             if (siz[a[i]]<=n/2) now=siz[a[i]];
	             if (now!=dep[x]) X=dep[x];
	             else X=dep2[x];
                 if (n-siz[a[i]]<=n/2) X=max(X,n-siz[a[i]]);
	             if (u[a[i]].id!=0)
	                 {
	                 	if (siz[u[a[i]].id]-n/2<=dep[u[a[i]].id]) exist[a[i]]=true;
					 }
				else    
				     {
				     	if (n-siz[a[i]]>n/2)
				     	     {
				     	    if (n-siz[a[i]]-n/2<=X) exist[a[i]]=true;
				     	     }
				     	else exist[a[i]]=true;
					 }
				if (X>dep[a[i]]) 
				     {
				     	dep2[a[i]]=dep[a[i]];dep[a[i]]=X;
					 }
				else dep2[a[i]]=max(dep2[a[i]],X);
				sc_change(a[i],x);
			  }
}
int main()
{
T=1;
	for (;T;T--)
	     {
	     	n=read();
	     	for (i=1;i<=n;i++) d[i]=0;
	     	cnt=0;
	     	for (i=1;i<n;i++)
	     	    {
	     	    	x=read();y=read();
	     	    	add(x,y);add(y,x);
				 }
			for (i=1;i<=n;i++) exist[i]=0,siz[i]=0,dep[i]=0,dep2[i]=0,u[i].val=0,u[i].id=0;
			flag=false;sc(1,0,1);exist[1]=flag;
			sc_change(1,0);
			for (i=1;i<=n;i++)
			    printf("%d ",exist[i]);
			puts("");
		 }
    return 0;
}