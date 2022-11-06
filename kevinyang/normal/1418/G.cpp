#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<vector<int>>h(n+1,vector<int>(3));
	vector<int>freq(n+1);
	vector<int>freq2(n+1);
	for(int i = 1; i<=n; i++){
		for(int j = 0; j<3; j++){
			h[i][j] = rng();
		}
	}
	map<int,int>hm;
	int cur = 1;
	int hsh = 0;
	for(int i = 1; i<=n; i++){
		hsh^=h[i][0];
	}
	hm[hsh] = 1;
	int ans = 0;
	vector<int>dp(n+1);
	dp[0] = hsh;
	for(int i = 1; i<=n; i++){
		hsh^=h[arr[i]][freq[arr[i]]%3];
		freq[arr[i]]++;
		freq2[arr[i]]++;
		hsh^=h[arr[i]][freq[arr[i]]%3];
		while(freq2[arr[i]]>3){
			hm[dp[cur-1]]--;
			freq2[arr[cur]]--;
			cur++;
		}
		ans+=hm[hsh];
		hm[hsh]++;
		dp[i] = hsh;
	}
	cout << ans << "\n";
	return 0;
}