#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=40;
ll dp[N][N];
ll d,m,mx;
ll solvedp(ll mn, ll i){
	if(~dp[mn][i])return dp[mn][i];
	if(mn>mx)return 1;
	dp[mn][i]=!!i;
	for(ll j=mn;j<=mx;++j){
		ll mult=1<<j;
		if(j==mx)mult=d-(1<<mx)+1;
		ll add=solvedp(j+1,i+1);
		dp[mn][i]=(dp[mn][i]+add*mult)%m;
//		if(i==1&&mn==1)cerr<<j<<" - "<<mult<<" "<<add<<endl;
//		if(!i)cerr<<j<<" "<<mult<<" "<<add<<endl;
	}
	return dp[mn][i];
}

main(){
	int tc;cin>>tc;
	while(tc--){
		cin>>d>>m;
		memset(dp,-1,sizeof(dp));
		for(ll i=0;i<32;++i)if(d&(1<<i))mx=i;
		cout<<solvedp(0,0)<<endl;
	}
}