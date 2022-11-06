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
int tem1,tag,ggg,tem,j,t,w,f1[10001010],f2[10001010],fre,father1[1010][10010],father2[1010][10010],now[1010][10010],tag1,tag2,ttt,cnt,a[101010],b[101010],d[101010],aa[101010],bb[101010],cc[101010],id1,c[101010],g[101010],n,m,L,st,ed,i,x,y,z;
int f[1010][10010];
bool exist[100101];
void add(int x,int y,int z,int k)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];c[cnt]=z;g[cnt]=k;d[x]=cnt;
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();m=read();L=read();st=read();ed=read();st++;ed++;
    for (i=1;i<=m;i++)
         { 
         x=read();y=read();z=read();
         aa[i]=x;bb[i]=y;cc[i]=z;
         x++;y++;
         add(x,y,z,i);add(y,x,z,i);
         if (z==0) id1++;
        
		}
	for (i=1;i<=n;i++) 
	    for (j=0;j<=id1;j++)
	         f[i][j]=2e9;
	f[st][0]=0;t=1;w=1;f1[1]=st;f2[1]=0;
	while (t<=w)
	     {
	     	x=f1[t];
	     	for (i=d[x];i;i=b[i])
	     	     {
	     	     	y=a[i];fre=f2[t];
	     	     	if (c[i]==0) fre++;
	     	     	if (f[x][f2[t]]+c[i]>L) continue;
	     	     	if(f[y][fre]>f[x][f2[t]]+c[i])
	     	     	     {
	     	     	     	f[y][fre]=f[x][f2[t]]+c[i];
	     	     	     	father1[y][fre]=x;father2[y][fre]=f2[t];now[y][fre]=g[i];
	     	     	     	w++;f1[w]=y;f2[w]=fre;
						   }
				  }
	     	t++;
		 }
	if (f[ed][0]==L)
	     {
	     	puts("YES");
	     	for (i=1;i<=m;i++)
	     	    if (cc[i]==0) printf("%d %d 100000000001\n",aa[i],bb[i]);
	     	    else printf("%d %d %d\n",aa[i],bb[i],cc[i]);
	     return 0;	
		 }
	else if (f[ed][0]<L)
	       {
	       	puts("NO");return 0;
		   }
	tag1=ed;tag2=-1;
	for (i=1;i<=id1;i++)
	    if (f[ed][i]<=L)
	        if ((L-f[ed][i])>=i)
	            { 
	            tag2=i;break;
				}
ttt=L-f[ed][i];
	if (tag2==-1)
	    { 
	    puts("NO");return 0;
		}
	puts("YES");
	tag=tag2;
    while ( tag1!=st)
         {
         	exist[now[tag1][tag2]]=true;
         	tem=father1[tag1][tag2];tem1=father2[tag1][tag2];
         	tag1=tem;tag2=tem1;
		 }
	for (i=1;i<=m;i++)
	     if (cc[i]!=0)
	         { 
	         printf("%d %d %d\n",aa[i],bb[i],cc[i]);
			 }
		else 
		     {
		     	if (exist[i]==false ) printf("%d %d 1000000000001\n",aa[i],bb[i]);
		     	else 
		     	    {
		     	    	ggg++;
		     	    	if (ggg==tag) printf("%d %d %d\n",aa[i],bb[i],ttt-(tag-1));
		     	    	else printf("%d %d 1\n",aa[i],bb[i]);
					 }
			 }
    return 0;
}