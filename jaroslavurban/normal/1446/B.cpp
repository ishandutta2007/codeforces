#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5020;
int dp[N][N];
int n,m;
string s,t;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>m>>s>>t;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]-1);
			dp[i][j+1]=max(dp[i][j+1],dp[i][j]-1);
			if(s[i]==t[j])dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+2);
		}
	int res=0;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			res=max(res,dp[i][j]);
	cout<<res<<endl;
}