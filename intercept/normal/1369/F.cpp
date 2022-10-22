#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,m;
ll p[M];
int dp[M][2],ans[M][2];//01
unordered_map<ll,pii>mp;
pii dfs(ll l,ll r){
	if(l>r)return make_pair(0,1);
	ll z=*lower_bound(p+1,p+m+1,l);
	if(l%2==z%2)l=z;
	else l=z-1;
	if(mp.count(l))return mp[l];
	auto x=dfs(l+1,r);
	auto y=dfs(l*2,r);
	int u,v;
	for(int j=0;j<3;++j){
		if(x.fi!=j&&y.fi!=j){
			u=j;
			break;
		}
	}
	for(int j=0;j<3;++j){
		if(x.se!=j&&y.se!=j){
			v=j;
			break;
		}
	}
	return mp[l]=make_pair(u,v);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
	 	ll l,r;
	 	cin>>l>>r;
	 	ll x=r;
	 	m=0;
	 	while(x>=l)p[++m]=x,x/=2;
	 	for(int i=1;i<=m/2;++i)swap(p[i],p[m-i+1]);
	 	mp.clear();
	 	auto o=dfs(l,r);
	 	dp[i][0]=o.fi;
	 	dp[i][1]=o.se;
	}
	ans[0][0]=1;
	for(int i=1;i<=n;++i){
		ans[i][0]|=ans[i-1][0]&(dp[i][0]!=0);
		ans[i][0]|=ans[i-1][1]&(dp[i][0]==0);
		ans[i][1]|=ans[i-1][0]&(dp[i][1]!=0);
		ans[i][1]|=ans[i-1][1]&(dp[i][1]==0);
	}
	cout<<ans[n][1]<<" "<<ans[n][0]<<"\n";
	return 0;
}
/*
1
5 7

2 3

4 5

2 4

1 4

1 2

3 5

3 4


*/