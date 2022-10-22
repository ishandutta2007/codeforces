#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=109;
int n,k;
int a[M],b[M],dp[M][M][2];
void work(){
	cin>>n;
	int l=0,r=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		if(x&1)l++;
		else r++;
	}
	cout<<(dp[l][r][0]?"Alice":"Bob")<<"\n";
}
int main(){
	cin.tie(0);
	cout.tie(0);
	dp[0][0][0]=1;
	dp[0][0][1]=0;
	for(int i=0;i<=100;++i){
		for(int j=0;j<=100;++j){
			if(i){
				dp[i][j][0]|=dp[i-1][j][(i-1)&1]^1;
				dp[i][j][1]|=dp[i-1][j][i&1]^1;
			}
			if(j){
				dp[i][j][0]|=dp[i][j-1][(i-1)&1]^1;
				dp[i][j][1]|=dp[i][j-1][i&1]^1;
			}
		}
	}
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 1
4
*/