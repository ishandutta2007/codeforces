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
vector<int> edge[1001010];
bool flag,exist[1001010];
long long x,i,n,val[1001010],lim[1001010],l,r,mid,ans;
void sc(int x,int fa)
{
	if (flag==false) return ;
	int y;
	for (int i=0;i<edge[x].size();i++)
	   {
	   	  y=edge[x][i];
	   	  if (y==fa) continue;
	   	  sc(y,x);
	   	  lim[x]+=lim[y];
	   	  lim[x]=min(lim[x],(long long)1e18);
	   }
	if (lim[x]<val[x]) flag=false;
	lim[x]-=val[x];
}
bool check(long long mid)
{
	for (int i=1;i<=n;i++) lim[i]=mid*exist[i];
	flag=true;sc(1,0);
	return flag;
}
int main()
{
	n=read();
	for (i=2;i<=n;i++) x=read(),edge[x].push_back(i),exist[x]=true;
	for (i=1;i<=n;i++) exist[i]=exist[i]^1;
	for (i=1;i<=n;i++) val[i]=read(),r+=val[i];
	while (l<=r)
	   { 
	    mid=(l+r)/2;
	    if (check(mid))
	       { 
	       ans=mid;r=mid-1;
		   }
		else l=mid+1;
	   }
	printf("%lld\n",ans);
	return 0;
}