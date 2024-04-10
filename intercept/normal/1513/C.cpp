#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=2e5+109;
int n,m,dp[M];
int solve(int x){
	if(x<=9)return 1;
	if(dp[x])return dp[x];
	return dp[x]=(solve(x-10)+solve(x-9))%mod; 
}
void work(){
	int ans=0;
	scanf("%d%d",&n,&m);
	while(n){
		ans=(ans+solve(m+n%10))%mod;
		n/=10;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d\n",&T);
	while(T--)work();
	return 0;
}