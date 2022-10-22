#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int a[2][M],dp[M][2];
void work(){
	int n;
	cin>>n;
	for(int o=0;o<2;++o){
		for(int i=1;i<=n;++i)cin>>a[o][i],a[o][i]++;
	}
	a[0][1]=0;
	dp[n+1][0]=dp[n+1][1]=0;
	for(int i=n;i>=1;--i){
		dp[i][0]=max({dp[i+1][0]-1,a[0][i]+n*2-1,a[1][i]-((n-i+1)*2-1)+n*2-1});
		dp[i][1]=max({dp[i+1][1]-1,a[1][i]+n*2-1,a[0][i]-((n-i+1)*2-1)+n*2-1});
	}
	int ans=2e9;
	for(int i=1,now=0;i<=n;++i){
		ans=min(ans,max(dp[i][(i&1)^1]-(i-1)*2,now));
		if(i&1){
			now=max({now,a[0][i]-(i-1)*2+n*2-1,a[1][i]-(i-1)*2-1+n*2-1});
		}
		else now=max({now,a[1][i]-(i-1)*2+n*2-1,a[0][i]-(i-1)*2-1+n*2-1});
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
4
0 10 10 10
10 10 10 10
*/