#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1024;
int w[2][1054],n,K,x;
int main(){
	scanf("%d%d%d",&n,&K,&x);
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1); w[0][k1]++;
	}
	int now=0;
	for (;K;K--){
		int ne=now^1; memset(w[ne],0x00,sizeof w[ne]);
		int *A=w[now],*B=w[ne],pre=0;
		for (int i=0;i<N;i++){
			B[i^x]+=(A[i]>>1);
			B[i]+=(A[i]>>1);
			if (A[i]&1){
				if (pre==0) B[i^x]++; else B[i]++;
				pre^=1;
			}
		}
		now=ne;
	}
	int mi=N,ma=0;
	for (int i=0;i<N;i++) 
		if (w[now][i]) mi=min(mi,i),ma=max(ma,i);
	printf("%d %d\n",ma,mi);
	return 0;
}