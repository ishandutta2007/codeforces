#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin>>n;
	vector<int> a(n),f(n),cf(n);
	vector<pair<int,int>> at(n,{-1,-1});
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
		f[a[i]]++;
		if(at[a[i]].first == -1)at[a[i]] = {i,i};
		at[a[i]].second = i;
	}
	vector<int> dp(n+1);

	for(int i=n-1;i>=0;i--){
		dp[i] = dp[i+1];
		cf[a[i]]++;
		if(i == at[a[i]].first)dp[i] = max(dp[i] , dp[at[a[i]].second + 1] + f[a[i]]);
		else dp[i] = max(dp[i] , cf[a[i]]);
	}

	cout << n - dp[0] << '\n';
}