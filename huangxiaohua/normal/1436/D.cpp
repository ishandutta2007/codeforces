#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
 
int n,m,i,j,t,son[200500],sb[200500],v[200500],k,ye[200500];
ll dp[200500][3];
queue<int> q;
int main(){
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		scanf("%d",&v[i]);
		son[v[i]]++;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&sb[i]);
	}
	for(i=1;i<=n;i++){
		if(!son[i]){q.push(i);dp[i][0]=1;dp[i][1]=dp[i][2]=sb[i];ye[i]=1;}
		
	}
	while(!q.empty()){
		k=q.front();q.pop();
		son[v[k]]--;
		if(!son[v[k]]){q.push(v[k]);}
		if(ye[k]){goto aaa;}
		if(sb[k]<=(dp[k][1]*dp[k][0]-dp[k][2])){}
		else{
			if((sb[k]-(dp[k][1]*dp[k][0]-dp[k][2]))%dp[k][0]){dp[k][1]+=1+(sb[k]-(dp[k][1]*dp[k][0]-dp[k][2]))/dp[k][0];}
			else{dp[k][1]+=(sb[k]-(dp[k][1]*dp[k][0]-dp[k][2]))/dp[k][0];}
		}
		dp[k][2]+=sb[k];
		aaa:
		dp[v[k]][0]+=dp[k][0];
		dp[v[k]][1]=max(dp[v[k]][1],dp[k][1]);
		dp[v[k]][2]+=dp[k][2];
		//printf("%d %d %d %d\n",k,dp[k][0],dp[k][1],dp[k][2]);
	}
	printf("%lld\n",dp[1][1]);
}