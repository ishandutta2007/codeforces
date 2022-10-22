#include<bits/stdc++.h>
using namespace std;
int n,a[210000],p[210000],fa[210000],sz[210000],Ans[210000];
bool cmp(int x,int y){ return a[x]>a[y];}
int findset(int x){
	if (x!=fa[x]) fa[x]=findset(fa[x]);
	return fa[x];
}
void Union(int x,int y){
	x=findset(x); y=findset(y);
	fa[y]=x; sz[x]+=sz[y];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+n+1,cmp);
	
	for (int i=1;i<=n;i++) fa[i]=i;
	
	int now=0;
	for (int i=1;i<=n;i++){
		int x=p[i];
		sz[x]=1; int tmp=now;
		if (sz[x-1]) Union(x-1,x);
		if (sz[x+1]) Union(x+1,x);
		now=max(now,sz[findset(x)]);
		for (int j=tmp+1;j<=now;j++) Ans[j]=a[x];
	}
	for (int i=1;i<=n;i++) printf("%d ",Ans[i]);
	return 0;
}