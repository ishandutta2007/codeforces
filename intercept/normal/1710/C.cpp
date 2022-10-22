#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int n,m;
int dp[2][2][2][2][2][2][M];
char s[M];
int dfs(int a,int b,int c,int ua,int ub,int uc,int m){
	
	if(m==n+1)return (a&b&c);
	if(dp[a][b][c][ua][ub][uc][m]!=-1)return dp[a][b][c][ua][ub][uc][m];
	int ans=0;
	int la=ua?s[m]-'0':1;
	int lb=ub?s[m]-'0':1;
	int lc=uc?s[m]-'0':1;
	
	for(int i=0;i<=la;++i){
		for(int j=0;j<=lb;++j){
			for(int k=0;k<=lc;++k){
				int na=a,nb=b,nc=c;
				if((i&j&k)!=(i|j|k)){
					na|=!(i^j);
					nb|=!(i^k);
					nc|=!(j^k);
				}
				ans=(ans+dfs(na,nb,nc,ua&(i==la),ub&(j==lb),uc&(k==lc),m+1))%mod;
			}
		}
	}
	return dp[a][b][c][ua][ub][uc][m]=ans;
}
int main(){
	cin>>(s+1);
	n=strlen(s+1);
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,0,0,1,1,1,1)<<endl;
	return 0;
}
/*
0101
*/