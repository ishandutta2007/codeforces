#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int M=2009;
int n;
char s[M],t[M];
int ps[M][26],pt[M][26];
int dp[M][M];
void work(){
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j){
			ps[i][j]=ps[i-1][j];
			pt[i][j]=pt[i-1][j];
		}
		ps[i][s[i]-'a']++;
		pt[i][t[i]-'a']++;
	}
	for(int j=0;j<26;++j){
		if(ps[n][j]!=pt[n][j]){
			puts("-1");
			return;
		}
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j)dp[i][j]=n;
	}
	for(int i=0;i<=n;++i)dp[0][i]=i;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(s[i]==t[j])dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
			dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
			if(ps[i][s[i]-'a']<=pt[j][s[i]-'a'])dp[i][j]=min(dp[i][j],dp[i-1][j]);
		}
	}
	printf("%d\n",dp[n][n]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
2
ab
ba
*/