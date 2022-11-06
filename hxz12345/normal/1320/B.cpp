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
vector<int> edge[301010];
int x,y,n,m,i,Q,t,w,f1[1001010],f[1001010],ans1,ans2,nxt,now,e[1001010],road[1001010];

int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();m=read();
	for (i=1;i<=m;i++)   
	    {
	    	x=read();y=read();edge[y].push_back(x);
		}
	Q=read();
	for (i=1;i<=Q;i++) road[i]=read();
    for (i=1;i<=n;i++) f[i]=1e9,e[i]=0;
	t=1;w=1;f1[1]=road[Q];f[road[Q]]=0;e[road[Q]]=1;
    while (t<=w)
         {
         	x=f1[t];
         	for (i=0;i<edge[x].size();i++)
         	    {
         	    	y=edge[x][i];
         	    	if (f[x]+1<f[y])
         	    	    {
         	    	    	f[y]=f[x]+1;e[y]=1;
						    w++;f1[w]=y;
				      }
				else if (f[x]+1==f[y]) e[y]=2;
				 }
         	t++;
		 }
	for (i=1;i<Q;i++)
	      {
	      	now=road[i];nxt=road[i+1];
	      	if (f[now]-1==f[nxt])
	      	    {
	      	    	if (e[now]!=1) ans2++;
				  }
			else ans1++,ans2++;
		  }
	printf("%d %d\n",ans1,ans2);
    return 0;
}