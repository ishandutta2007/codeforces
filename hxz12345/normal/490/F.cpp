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
int tag[6010][6010];
int id[101010],Gq,cnt,i,rt,d[101010],a[101010],b[101010],n,val[101010],lsh[101010],tn,x,y,dp[101010],E[101010],ans;
void add(int  x,int y){
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void modify(int x,int y){Gq++;for (;x<=n;x+=x&-x) tag[Gq][x]=E[x],E[x]=max(E[x],y);}
void Remake(int x,int y){for (;x<=n;x+=x&-x) E[x]=tag[id[y]][x];}
int findmax(int x){int ans=0;for (;x;x-=x&-x) ans=max(ans,E[x]);return ans;}
void sc(int x,int fa){
	modify(val[x],dp[x]);id[x]=Gq;ans=max(ans,dp[x]);
	for (int i=d[x];i;i=b[i])
	      if (a[i]!=fa)
	          {
	          dp[a[i]]=findmax(val[a[i]]-1)+1;
			  sc(a[i],x);
			  }
	Remake(val[x],x);
}
int main()
{
	n=read();
	for (i=1;i<=n;i++) val[i]=read(),lsh[i]=val[i];
    sort(lsh+1,lsh+n+1);tn=unique(lsh+1,lsh+n+1)-lsh-1;
    for (i=1;i<=n;i++) val[i]=lower_bound(lsh+1,lsh+tn+1,val[i])-lsh;
		for (i=1;i<n;i++){
     x=read();y=read();add(x,y);add(y,x);}
    for (rt=1;rt<=n;rt++) 
	    {Gq=0;
	    for (i=1;i<=n;i++) dp[i]=0,E[i]=0;dp[rt]=1;
		sc(rt,0);
	    }
 printf("%d\n",ans);return 0;
}