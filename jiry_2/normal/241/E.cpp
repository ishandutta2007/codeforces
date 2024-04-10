#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
	int u,v;
}b[6000];
int n,m,A[6000],B[6000],d[6000];
void dfs(int k){
	if (A[k]) return; A[k]=1;
	for (int i=1;i<=m;i++) if (b[i].u==k) dfs(b[i].v);
}
void dfs2(int k){
	if (B[k]) return; B[k]=1;
	for (int i=1;i<=m;i++) if (b[i].v==k) dfs2(b[i].u);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&b[i].u,&b[i].v);
	dfs(1); dfs2(n); memset(d,0x00,sizeof d);
	for (int i=0;i<=n+m;i++)
		for (int j=1;j<=m;j++)
			if (A[b[j].u]&&B[b[j].v]){
				d[b[j].v]=min(d[b[j].v],d[b[j].u]+2); d[b[j].u]=min(d[b[j].u],d[b[j].v]-1);
			}
	for (int i=1;i<=m;i++) if (A[b[i].u]&&B[b[i].v]&&(d[b[i].v]-d[b[i].u]<1||d[b[i].v]-d[b[i].u]>2)){cout<<"No"<<endl; return 0;}
	cout<<"Yes"<<endl; for (int i=1;i<=m;i++) cout<<max(1,min(2,d[b[i].v]-d[b[i].u]))<<endl;
	return 0;
}