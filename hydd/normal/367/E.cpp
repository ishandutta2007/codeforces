#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
int n,m,k,dp[2][330][330];
int main(){
	cin>>n>>m>>k;
	if (n>m){
		cout<<0<<endl;
		return 0;
	}
	dp[0][0][0]=1;
	int now=0,lst=1;
	for (int i=1;i<=m;i++){
		now^=1; lst^=1;
		for (int x=0;x<=i+1&&x<=n+1;x++)
			for (int y=0;y<=i+1&&y<=n+1;y++)
				dp[now][x][y]=0;
		for (int x=0;x<=i&&x<=n;x++)
			for (int y=0;y<=x;y++){
				int v=dp[lst][x][y];
				dp[now][x+1][y]=(dp[now][x+1][y]+v)%Mod;//(
				dp[now][x+1][y+1]=(dp[now][x+1][y+1]+v)%Mod;//()
				if (i!=k){
					dp[now][x][y]=(dp[now][x][y]+v)%Mod;//
					if (y<x) dp[now][x][y+1]=(dp[now][x][y+1]+v)%Mod;//)
				}
			}
	}
	int mul=1;
	for (int i=1;i<=n;i++) mul=1ll*mul*i%Mod;
	cout<<1ll*dp[now][n][n]*mul%Mod<<endl;
	return 0;
}