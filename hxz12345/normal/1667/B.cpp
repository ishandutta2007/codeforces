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
long long tn,lsh[1001010],E1[1001010],E2[1001010],G[1001010],a[1001010],pre[1001010],f[1001010],n,i,j;
void modify1(int x,long long y){
	for (;x<=n;x+=x&-x) E1[x]=max(E1[x],y);
}
long long query1(long long x){
	long long ans=-1e18;
	for (;x;x-=x&-x) ans=max(ans,E1[x]);
	return ans;
}
void modify2(int x,long long y){
	for (;x;x-=x&-x) E2[x]=max(E2[x],y);
}
long long query2(long long x){
	long long ans=-1e18;
	for (;x<=n;x+=x&-x) ans=max(ans,E2[x]);
	return ans;
}
void Main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read(),pre[i]=pre[i-1]+a[i],lsh[i]=pre[i];
	sort(lsh+1,lsh+n+1);tn=unique(lsh+1,lsh+n+1)-lsh-1;
	for (i=1;i<=n;i++) pre[i]=lower_bound(lsh+1,lsh+n+1,pre[i])-lsh;
	for (i=1;i<=n;i++) G[i]=-1e18,E1[i]=-1e18,E2[i]=-1e18;
	for (i=1;i<=n;i++){
		if (lsh[pre[i]]==0) f[i]=0;
		if (lsh[pre[i]]>0) f[i]=i;
		if (lsh[pre[i]]<0) f[i]=-i;
	    f[i]=max(f[i],G[pre[i]]);
	    f[i]=max(f[i],query1(pre[i]-1)+i);
	    f[i]=max(f[i],query2(pre[i]+1)-i);
	    G[pre[i]]=max(G[pre[i]],f[i]);
	    modify1(pre[i],f[i]-i);modify2(pre[i],f[i]+i);
		/*for (j=1;j<i;j++)
		    {
			if (pre[i]>pre[j]) f[i]=max(f[i],f[j]+i-j);
		    if (pre[i]-pre[j]==0) f[i]=max(f[i],f[j]);
		    if (pre[i]<pre[j]) f[i]=max(f[i],f[j]+j-i);
		    }*/
	}
	printf("%lld\n",f[n]);
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}