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
bitset<5002> aa[5010],bb[5010];
bool edge[5010][5010],u[101010];
int tt,id,tot,f[101010],h[101010],lft,rit,n,i,j,L,R;
int d[501010],a[25001010],b[25001010],cnt,low[101010],dfn[101010],stak[101010];
void add(int x,int y)
{
  cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;	
}
void tarjan(int x,int fa)
{
	tt++;dfn[x]=tt;low[x]=tt;id++;stak[id]=x;u[x]=true;
	for (int i=d[x];i;i=b[i])
	   {
	   	  if (dfn[a[i]]==0)
	   	     {
	   	     	tarjan(a[i],x);
	   	     	low[x]=min(low[x],low[a[i]]);
				}
			else if (u[a[i]]==true) low[x]=min(low[x],dfn[a[i]]);
	   }
   if (low[x]==dfn[x])
      {
      	tot++;
      	while (1)
      	{
      		f[stak[id]]=tot;
      		h[tot]+=1;
      		u[stak[id]]=false;id--;
      		if (x==stak[id+1]) break;
		  }
	  }	
}
int main()
{
	n=read();
	char s[101010];
	for (i=1;i<=n;i++)
	     {
	     	scanf("%s",s+1);
	     	for (j=1;j<=n;j++)
	     	   if (s[j]=='1')
	     	       {
	     	       	aa[i][j]=1;
	     	       	bb[j][i]=1;
	     	       	add(i,j);
	     	       	edge[i][j]=1;
					}
		 }
	for (i=1;i<=n;i++) if (dfn[i]==0) tarjan(i,0);
	if (tot==n)
	    {
	    	puts("-1");
	    	return 0;
		}
	for (lft=1;lft<=n;lft++)
	    {
		if (L+R!=0) break;
	    for (rit=1;rit<=n;rit++) 
	       if (f[lft]==f[rit])
	       if (edge[lft][rit]==1)
	        if (lft!=rit)
	            if ((bb[lft]&aa[rit])!=0)
	                {
	                	L=lft;R=rit;break;
					}
	}
	for (i=1;i<=n;i++)
	    if ((i!=L)&&(i!=R))
	        if ((edge[i][L]&edge[R][i]))
	             {
	             	printf("%d %d %d\n",i,L,R);
	             	return 0;
				 }
	return 0;
}