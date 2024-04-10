#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,a[100500];
double dp[100500][12],b[100500];
unordered_map<int,unordered_map<int,vector<int>>> ans;
stack<int> res;
int main(){
	scanf("%d%d",&n,&m);
	for(i=0;i<=100000;i++){
		for(j=0;j<=9;j++){
			dp[i][j]=-1;
		}
	}
	dp[0][1]=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=log2(a[i]);
	}
	for(i=1;i<=n;i++){
		for(j=0;j<=9;j++){
			k=j*a[i]%10;
			if(dp[i-1][j]==-1){continue;}
			if(dp[i-1][j]+b[i]>dp[i][k]){
				ans[i][k]={1,j};
				dp[i][k]=dp[i-1][j]+b[i];
			}
			if(dp[i-1][j]>dp[i][j]){
				ans[i][j]={0,j};
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	if(dp[n][m]==-1){puts("-1");return 0;}
	if(m==1&&!dp[n][m]){
		j=0;
		for(i=1;i<=n;i++){
			if(a[i]==1){j=1;break;}
		}
		if(!j){puts("-1");return 0;}
	}
	j=m;
	for(i=n;i>=1;i--){
		if(ans[i][j][0]){res.push(a[i]);}
		j=ans[i][j][1];
	}
	printf("%d\n",res.size());
	while(!res.empty()){
		printf("%d ",res.top());res.pop();
	}
}