#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct bian{
	int u,v;
}A[210000];
struct ask{
	int u,v,l,r,where;
}B[210000];
int compare(ask k1,ask k2){
	return k1.l>k2.l;
}
int go[1100][1100],n,m,q,ans[210000];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	memset(go,0x3f,sizeof go);
	for (int i=1;i<=m;i++) scanf("%d%d",&A[i].u,&A[i].v);
	for (int i=1;i<=q;i++){
		scanf("%d%d%d%d",&B[i].l,&B[i].r,&B[i].u,&B[i].v);
		B[i].where=i;
	}
	sort(B+1,B+q+1,compare);
	int now=1;
	for (int t=m;t;t--){
		go[A[t].u][A[t].u]=t; go[A[t].v][A[t].v]=t;
		int *x=go[A[t].u],*y=go[A[t].v];
		for (int i=1;i<=n;i++)
			if (x[i]<y[i]) y[i]=x[i]; else x[i]=y[i];
	//	cout<<"solve "<<t<<endl;
	//	for (int i=1;i<=n;i++){
	//		for (int j=1;j<=n;j++) cout<<go[i][j]<<" "; cout<<endl;}
		while (now<=q&&B[now].l==t){
			ans[B[now].where]=(go[B[now].u][B[now].v]<=B[now].r);
	//		cout<<B[now].where<<" "<<B[now].r<<" "<<go[B[now].u][B[now].v]<<endl;
			now++;
		}
	}
	for (int i=1;i<=q;i++) if (ans[i]) printf("Yes\n"); else printf("No\n");
	return 0;
}