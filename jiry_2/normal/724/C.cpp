#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,m,pdA[210000],pdB[210000],K;
long long ans[210000];
int x[210000],y[210000];
vector<int>A[210000],B[210000];
void dfs(int k1,int k2,int k3,int k4,long long k5){
	if (k3==k4){
		int now=k1-k2+m;
		if (pdB[now]) return; pdB[now]=1;
		for (int i=0;i<B[now].size();i++){
			int k=B[now][i];
			long long t=abs(x[k]-k1)+k5;
			if (ans[k]==-1) ans[k]=t;
		}
	} else {
		int now=k1+k2;
		if (pdA[now]) return; pdA[now]=1;
		for (int i=0;i<A[now].size();i++){
			int k=A[now][i];
			long long t=abs(x[k]-k1)+k5;
			if (ans[k]==-1) ans[k]=t;
		}
	}
	int t1=0,t2=0;
	if (k3==1) t1=n-k1; else t1=k1;
	if (k4==1) t2=m-k2; else t2=k2;
	if (t1==t2) return;
	if (t1<t2){
		dfs(k1+k3*t1,k2+k4*t1,-k3,k4,k5+t1);
	} else dfs(k1+k3*t2,k2+k4*t2,k3,-k4,k5+t2);
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	memset(ans,0xff,sizeof ans);
	for (int i=1;i<=K;i++){
		int k1,k2; scanf("%d%d",&x[i],&y[i]);
		A[x[i]+y[i]].push_back(i);
		B[x[i]-y[i]+m].push_back(i);
	}
	dfs(0,0,1,1,0);
	for (int i=1;i<=K;i++) printf("%I64d\n",ans[i]);
	return 0;
}