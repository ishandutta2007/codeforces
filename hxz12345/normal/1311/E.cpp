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
long long xx,now,len,fa,lr,x,n,D,lim,dep_mx,dep_now,T,i,lg[101000],dep[101000],e[101000],father[101000],son[101000][3];
bool f[101000];
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
    for (i=2;i<=5000;i++) lg[i]=lg[i/2]+1;
	for (T=read();T;T--)
         {
         	n=read();D=read();
         	lim=0;
         	for (i=1;i<=n;i++) lim+=lg[i];
         	if ((D<lim)||(D>n*(n-1)/2)) puts("NO");
         	else
         	   {
         	puts("YES");
         	D-=lim;
         	for (i=1;i<=n;i++) e[i]=0;
            for (i=1;i<=n;i++) dep[i]=lg[i];
            for (i=1;i<=n;i++) f[i]=false;
         	for (i=2;i<=n;i++)
         	    if ((1<<lg[i])==i) f[i]=true;
         	for (i=1;i<=n;i++) son[i][1]=son[i][2]=0;
         	for (i=1;i<=n;i++)
         	      {
         	      	if (i*2<=n) son[i][1]=i*2;
         	      	if (i*2+1<=n) son[i][2]=i*2+1;
         	      	if (i!=1) father[i]=i/2;
         	      	if (i!=1) e[i/2]++;
				   }
			dep_mx=dep[1<<lg[n]];
         	while (D)
         	     {
         	    	x=0;
         	       for (i=1;i<=n;i++)
					    if ((f[i]==false)&&(e[i]==0))
					        if (dep[i]>dep[x]) x=i;
					for (i=1,lr=2;i<=n;i++)
					    if (son[i][1]==x) lr=1;
				   for (i=1;i<=n;i++)
				       if ((f[i])&&(dep[i]==dep[x]))
				           fa=i;
				    len=dep_mx-dep[fa]+1;
				    for (i=1;i<=n;i++)
				       if ((f[i])&&(dep[i]==dep_mx)) xx=i;
				    if (len<=D)
				        {
				        	dep_mx++;
				        	son[father[x]][lr]=0;
				        	son[xx][1]=x;e[father[x]]--;father[x]=xx;e[xx]++;
				        	dep[x]=dep[xx]+1;
				        	f[x]=true;D-=len;
						}
				    else
					   {
					   	   e[father[x]]--;son[father[x]][lr]=0;dep_now=dep[fa]+D-1;
					   	   for (i=1;i<=n;i++)
					   	       if ((f[i])&&(dep[i]==dep_now)) now=i;
					   	    e[now]++;
					   	    father[x]=now;break;
							}      
				 }
			for(i=2;i<=n;i++) printf("%d ",father[i]);
			puts("");
	      	}
		 }
return 0;
}