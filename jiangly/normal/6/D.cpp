//Time Complexity : O(N)
//Space Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
const int N=10,H=16,inf=1e9;
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	vector<int>h(n);
	for(int i=0;i<=n-1;++i){
		scanf("%d",&h[i]);
		++h[i];
	}
	int dp[N][H+1][H+1]={};
	pair<int,int>g[N][H+1][H+1]={};
	for(int i=0;i<=N-1;++i){
		for(int j=0;j<=H;++j){
			for(int k=0;k<=H;++k){
				dp[i][j][k]=inf;
			}
		}
	}
	dp[0][h[0]][0]=0;
	for(int i=0;i<=n-3;++i){
		for(int j=0;j<=H;++j){
			for(int k=0;k<=H;++k){
				for(int l=0;l<=H;++l){
					if(j-l*b<=0&&dp[i+1][max(h[i+1]-a*l-b*k,0)][l]>dp[i][j][k]+l){
						dp[i+1][max(h[i+1]-a*l-b*k,0)][l]=dp[i][j][k]+l;
						g[i+1][max(h[i+1]-a*l-b*k,0)][l]={j,k};
					}
				}
			}
		}
	}
	int ans=inf,prev;
	for(int i=0;i<=H;++i){
		if(h[n-1]-i*b<=0&&ans>dp[n-2][0][i]){
			ans=dp[n-2][0][i];
			prev=i;
		}
	}
	printf("%d\n",ans);
	for(int i=n-2,j=0,k=prev;i;--i){
		auto p=g[i][j][k];
		for(int l=1;l<=k;++l){
			printf("%d ",i+1);
		}
		j=p.first;
		k=p.second;
	}
	return 0;
}