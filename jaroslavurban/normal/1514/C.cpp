#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(int n){
	vector<int>res={1};
	vector<int>same;
	for(int i=2;i<n;++i)if(__gcd(i,n)==1){
		if(i*ll(i)%n==1)same.push_back(i);
		else res.push_back(i);
	}
	vector<vector<int>>dp(same.size()+1,vector<int>(n));
	vector<vector<int>>prv(same.size()+1,vector<int>(n));
	vector<vector<int>>len(same.size()+1,vector<int>(n));
	auto update=[&](int i,int j,int p,int ln){
		if(len[i][j]<=ln+1){
			len[i][j]=ln+1;
			dp[i][j]=1;
			prv[i][j]=p;
		}
	};
	dp[0][1]=1;
	prv[0][1]=-1;
	for(int i=0;i<same.size();++i){
		for(ll j=1;j<n;++j)
			if(dp[i][j]){
				int nxt=j*same[i]%n;
				update(i+1,nxt,j,len[i][j]);
				update(i+1,j,j,len[i][j]-1);
			}
	}
	int i=same.size();
	int j=1;
	if(dp[i][j]){
		while(i>0){
			if(prv[i][j]*ll(same[i-1])%n==j)res.push_back(same[i-1]);
			j=prv[i][j];
			--i;
		}
	}
	sort(res.begin(),res.end());
	cout<<res.size()<<endl;
	for(auto r:res)cout<<r<<" ";cout<<endl;
}

main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;cin>>n;
	solve(n);
//	for(int i=2;i<10000;++i)solve(i);
}