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
vector<int> Edge[101010];
int lst[101010][13],e[101010][13];
int f2[5001010],tt,xx,yy,sta,g[1010101],h[1010110],w,now1,now2,now3,mn,cnt,f[101010][13],t,j,x,y,z,n,father[101010],f1[5001010],m,i,a[501010],b[501010],c[501010],d[501010],dis[101010];
bool exist[5001010];
bool flag;
void add(int x,int y,int z)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];c[cnt]=z;d[x]=cnt;
}
int check(int xf,int yf,int xe,int ye)
{
	int xx,yy;
	while((xe!=0)&&(xf!=0))
	     {
	     	if ((xf==xe)&&(yf==ye)) return 2;
	     	if (yf>ye) return 1;
	     	if (yf<ye) return 3;
	     	xx=lst[xf][yf];yy=e[xf][yf];xf=xx;yf=yy;
	     	xx=lst[xe][ye];yy=e[xe][ye];xe=xx;ye=yy;
		 }
	return 2;
}
void Pretreat()
{
	int t,w,y,i;
	t=1;w=1;f1[1]=n;
	for (i=1;i<=n;i++) dis[i]=1e9;
	dis[n]=0;
	while (t<=w)
	    {
	    	for (i=0;i<Edge[f1[t]].size();i++)
	    	     {
	    	     	y=Edge[f1[t]][i];
	    	     	if (dis[f1[t]]+1<dis[y])
	    	     	     {
	    	     	     	dis[y]=dis[f1[t]]+1;father[y]=f1[t];w++;f1[w]=y;
						  }
				 }
	    	t++;
		}
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();m=read();
	for (i=1;i<=m;i++)
	    {
	    	x=read();y=read();z=read();
	    	x++;y++;
	    	add(x,y,z);add(y,x,z);
	    	if (z==0) Edge[x].push_back(y),Edge[y].push_back(x); 
		}
	Pretreat();
	for (i=1;i<=n;i++)
	   for (j=0;j<=9;j++)
	        f[i][j]=1e9;
	f[1][0]=0;
	t=1;w=1;f1[1]=1;f2[1]=0;
	while (t<=w)
	    {
	    	x=f1[t];
	    	//jc[i]
			//
			//T. 
	    	for (i=d[x];i;i=b[i])
	    	   {
			   flag=false;
	    	       if ((f[x][f2[t]]+1<f[a[i]][c[i]]))
	    	                {
	    	             	f[a[i]][c[i]]=f[x][f2[t]]+1;e[a[i]][c[i]]=f2[t];lst[a[i]][c[i]]=x;
	    	                flag=true;
	    	                 }
					else if (f[x][f2[t]]+1==f[a[i]][c[i]])
					        if (check(lst[a[i]][c[i]],e[a[i]][c[i]],x,f2[t])==1)
                                    {
							    	e[a[i]][c[i]]=f2[t];lst[a[i]][c[i]]=x;
							    flag=true;
							       }
					if (flag) 
					    {
					    	w++;f1[w]=a[i];f2[w]=c[i];
						}
			}
	    	t++;
		}
	if (dis[1]!=1e9)
	    {
	    	puts("0");
	    	printf("%d\n",dis[1]+1);
	    	printf("0 ");
    for (i=father[1];i;i=father[i])
           	printf("%d ",i-1);
           	puts("");
	    	return 
			0;
		}
	now1=0;now2=0;mn=1e9;
	for (i=1;i<=n;i++)
	    if (dis[i]!=1e9)
	        for (j=1;j<=9;j++)
	            mn=min(mn,f[i][j]);
	now3=1e9;
	for (i=1;i<=n;i++)
	   if (dis[i]!=1e9)
	       for (j=1;j<=9;j++)
	           if (f[i][j]==mn)
	               {
	               	if (now1==0)  
	               	    {
	               	    	now1=i;now2=j;now3=dis[i];continue;
						}
					sta=check(now1,now2,i,j);
					if (sta==1)
					   {
					   	now1=i;now2=j;now3=dis[i];
					   }
					else if ((sta==2)&&(dis[i]<now3))
					         {
					         	now1=i;now2=j;now3=dis[i];
							 }
				   }
	i=now1,j=now2;
	while (i)
	   {
	   	tt++;g[tt]=i-1;h[tt]=j;
	   	xx=lst[i][j];yy=e[i][j];
	   	i=xx;j=yy;
	   }
	for (i=1;i<=tt-1;i++) printf("%d",h[i]);puts("");
	printf("%d\n",tt+dis[now1]);
	for (i=tt;i>=1;i--) printf("%d ",g[i]);
    for (i=father[now1];i;i=father[i])
           	printf("%d ",i-1);
return 0;
}