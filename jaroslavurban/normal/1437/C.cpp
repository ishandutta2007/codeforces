#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=520,inf=1e9;
int dp[N][N]; // time,dish
int t[N];
int n;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tt;cin>>tt;
	while(tt--){
		cin>>n;
		for(int i=0;i<N;++i)
			for(int j=0;j<=n;++j)
				dp[i][j]=inf;
		for(int i=0;i<n;++i)cin>>t[i];
		sort(t,t+n);
		reverse(t,t+n);
		dp[1][n]=0;
		for(int i=1;i<N-1;++i)
			for(int j=1;j<=n;++j)
				if(dp[i][j]!=inf){
					dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
					dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+abs(t[j-1]-i));
				}
		int res=inf;
		for(int i=0;i<N;++i)res=min(res,dp[i][0]);
		cout<<res<<endl;
	}
}