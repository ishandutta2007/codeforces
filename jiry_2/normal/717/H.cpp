#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int A[1100000],n,m,T,pd[1100000],L[51000],R[51000],bo[51000];
struct bian{
	int u,v;
}b[210000];
vector<int>x[51000];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&b[i].u,&b[i].v);
	T=0;
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1);
		for (;k1;k1--){
			int k2; scanf("%d",&k2); x[i].push_back(k2);
			T=max(T,k2);
		}
	}
	while (1){
		for (int i=1;i<=T;i++) pd[i]=rand()&1;
		int flag=0;
		for (int i=1;i<=n;i++){
			L[i]=-1; R[i]=-1;
			for (int j=0;j<x[i].size();j++)
				if (pd[x[i][j]]==0) L[i]=x[i][j]; else R[i]=x[i][j];
			if (L[i]==-1||R[i]==-1) {flag=1; break;}
		}
		if (flag==0) break;
	}
	while (1){
		for (int i=1;i<=n;i++) bo[i]=rand()&1;
		int num=0;
		for (int i=1;i<=m;i++)
			if (bo[b[i].u]^bo[b[i].v]) num++;
		if (num*2>=m) break;
	}
	for (int i=1;i<=n;i++) if (bo[i]) printf("%d ",L[i]); else printf("%d ",R[i]);
	printf("\n");
	for (int i=1;i<=T;i++) printf("%d ",pd[i]+1); printf("\n");
	return 0;
}