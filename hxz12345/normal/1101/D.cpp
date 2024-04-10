#include<bits/stdc++.h>
using namespace std;
inline int read()
{
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
// f[i][j]  i GCDu[i][j] 
int a[400000],prim[201000],b[400000],d[400000];
int extinct_1,len,i,j,n,cnt,u[200100][20],f[200100][20],x,y,ans;
bool vis[201000];
void add(int x,int y)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void sc(int x,int fa)
{
   int i,j,k;
   for (i=d[x];i;i=b[i])
       if (a[i]!=fa)
          { 
             sc(a[i],x);
             for (j=1;j<=u[x][0];j++)
                 for (k=1;k<=u[a[i]][0];k++)
                     if (u[x][j]==u[a[i]][k])
                         {
                         	ans=max(ans,f[x][j]+f[a[i]][k]+1);
                         	f[x][j]=max(f[x][j],f[a[i]][k]+1);
						 } 
		  }
}
int main()
{
	n=read();
	for (i=2;i<=200000;i++)
	    {
	    	if (vis[i]==false)
	    	    {
	    	    	len++;prim[len]=i;
				}
			for (j=1;j<=len,i*prim[j]<=200000;j++)
			      {
			      	vis[i*prim[j]]=true;
			      	if (i % prim[j]==0) break;
				  }
		}
	for (i=1;i<=n;i++) 
	    {
	    	x=read();extinct_1|=(x!=1);
	    	for (j=2;j<=sqrt(x);j++)
	    	     if (x % j==0)
	    	        {
	    	        	u[i][0]++;u[i][u[i][0]]=j;
	    	        	while (x % j==0) x/=j;
					}
			if (x>1) u[i][0]++,u[i][u[i][0]]=x;
		}
	if (extinct_1==0)
	    {
	    	puts("0");return 0;
		}
    for (i=1;i<n;i++)
        {
        	x=read();y=read();add(x,y);add(y,x);
		}
	sc(1,0);
	printf("%d\n",ans+1);
return 0;
}