#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


void ProGamerMove(){
	int n,k;cin>>n>>k;
	vector<int>a(n),dp(n+2,-1e9);
	for(auto&v:a)cin>>v;
	dp[1]=0;
	for(int i=1;i<=n;++i){
		vector<int>ndp(n+2,-1e9);
		for(int j=1;j<=n+1;++j)ndp[j]=max(dp[j],dp[j-1]+(a[i-1]==j-1));
		swap(dp,ndp);
	}
	for(int j=n+1;j>=1;--j)if(dp[j]>=k){
		cout<<n-j+1<<"\n";
		return;
	}
	cout<<"-1\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}