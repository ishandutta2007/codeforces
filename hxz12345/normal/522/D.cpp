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
vector<pair<int,int>> V[1001010];
int i,l,r,n,m,a[1001010],lsh[1001010],tot,val[1001010];
int j,vpre[1001010],Ans[1001010],pre[1001010],E[1001010];
void modify(int x,int y){
	for (;x;x-=x&-x) E[x]=min(E[x],y);
}
int findmax(int x){
	int ans=1e9;for (;x<=n;x+=x&-x) ans=min(ans,E[x]);return ans;
}
int main()
{
	n=read();m=read();
	for (i=1;i<=n;i++) a[i]=read(),lsh[i]=a[i];
	sort(lsh+1,lsh+n+1);tot=unique(lsh+1,lsh+n+1)-lsh-1;
	for (i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+tot+1,a[i])-lsh;
	for (i=1;i<=n;i++){
		val[i]=i-pre[a[i]];vpre[i]=pre[a[i]];
		pre[a[i]]=i;
	}
	for (i=1;i<=m;i++) l=read(),r=read(),V[r].push_back(make_pair(l,i));
	for (i=1;i<=n;i++) E[i]=1e9;
	for (i=1;i<=n;i++){
		if (vpre[i]!=0) modify(vpre[i],val[i]);
		for (j=0;j<V[i].size();j++) Ans[V[i][j].second]=findmax(V[i][j].first);
	}
	for (i=1;i<=m;i++) if (Ans[i]==1e9) puts("-1");else printf("%d\n",Ans[i]);
	//l<=i<=r &&pre[i]>=l
return 0;
}
/*
l<=i<=r &&l<=pre[i]ival[i]

l<=pre[i] i>=l

i<=r&&pre[i]>=l
r 
*/