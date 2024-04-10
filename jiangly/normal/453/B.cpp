#include<bits/stdc++.h>
using namespace std;
const int N=105,M=54,pn=16,inf=1e9,P=1<<pn;
const int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n,cur,a,ans,t;
int dp[N][P],g[M],c[N][P];
stack<int>st;
int main(){
	scanf("%d",&n);
	for(int i=1;i<M;++i){
		for(int j=0;j<pn;++j){
			if(i%p[j]==0){
				g[i]=g[i]^(1<<j);
			}
		}
	}
	for(int i=1;i<=n;++i){
		cur=cur^1;
		scanf("%d",&a);
		for(int j=0;j<P;++j){
			dp[i][j]=inf;
			for(int k=1;k<M;++k){
				if(!(g[k]&~j)&&dp[i-1][j^g[k]]+abs(k-a)<dp[i][j]){
					dp[i][j]=dp[i-1][j^g[k]]+abs(k-a);
					c[i][j]=k;
				}
			}
		}
	}
	ans=inf;
	for(int i=0;i<P;++i){
		if(dp[n][i]<ans){
			ans=dp[n][i];
			t=i;
		}
	}
	for(int i=n,j=t;i;--i){
		st.push(c[i][j]);
		j=j^g[c[i][j]];
	}
	while(!st.empty()){
		printf("%d ",st.top());
		st.pop();
	}
	return 0;
}