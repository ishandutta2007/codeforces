#include<bits/stdc++.h>
using namespace std;
const int M=(1<<20)+5;
int n,k,n0;
double dp[M];
double p[25],ans[25];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%lf",&p[i]);
		if(p[i]==0)n0++;
	}
	k=min(k,n-n0);
	dp[0]=1;
	for(int i=0,si=1<<n;i<si;++i){
		double rex=0;
		for(int j=1;j<=n;++j){
			int l=1<<j-1;
			if(i&l)rex+=p[j];
		}	
		for(int j=1;j<=n;++j){
			int l=1<<j-1;
			if(i&l)continue;
			dp[i|l]+=dp[i]*p[j]/(1.0-rex);
		}
		if(__builtin_popcount(i)==k){
			for(int j=1;j<=n;++j){
				int l=1<<j-1;
				if(i&l)ans[j]+=dp[i];
			}
		}
	}
	for(int i=1;i<=n;++i){
		printf("%.10lf ",ans[i]);
	}
	return 0;
}