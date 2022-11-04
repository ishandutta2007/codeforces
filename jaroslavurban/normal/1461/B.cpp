#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=550;
string f[N];
int dp[N][N];
int n,m;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n>>m;
		for(int i=0;i<n;++i)cin>>f[i];
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				dp[i][j]=0;
		int res=0;
		for(int i=n-1;i>=0;--i)
			for(int j=0;j<m;++j)
				if(f[i][j]=='*'){
					dp[i][j]=1;
					if(j&&j<m-1&&i<n-1)
						dp[i][j]+=min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
					res+=dp[i][j];
				}
		cout<<res<<endl;
	}
}