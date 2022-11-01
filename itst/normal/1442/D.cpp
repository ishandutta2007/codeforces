#include<bits/stdc++.h>
using namespace std;

#define int long long
int ans , N , K , dp[3003]; vector < int > pot[3003];

void divide(int l , int r){
	if(l == r){
		for(int i = 0 ; i < pot[l].size() && i <= K ; ++i)
			ans = max(ans , dp[K - i] + pot[l][i]);
		return;
	}
	int mid = (l + r) / 2 , tmp[3003]; memcpy(tmp , dp , sizeof(tmp));
	for(int i = l ; i <= mid ; ++i)
		for(int j = K ; j >= pot[i].size() - 1 ; --j)
			dp[j] = max(dp[j] , dp[j - pot[i].size() + 1] + pot[i].back());
	divide(mid + 1 , r); memcpy(dp , tmp , sizeof(dp));
	for(int i = mid + 1 ; i <= r ; ++i)
		for(int j = K ; j >= pot[i].size() - 1 ; --j)
			dp[j] = max(dp[j] , dp[j - pot[i].size() + 1] + pot[i].back());
	divide(l , mid); memcpy(dp , tmp , sizeof(dp));
}

signed main(){
	ios::sync_with_stdio(0); memset(dp , -0x3f , sizeof(dp));
	cin >> N >> K;
	for(int i = 1 ; i <= N ; ++i){
		pot[i].push_back(0); int S; cin >> S;
		for(int j = 1 ; j <= S ; ++j){int x; cin >> x; pot[i].push_back(pot[i].back() + x);}
	}
	memset(dp , -0x3f , sizeof(dp)); dp[0] = 0; ans = -1e18;
	divide(1 , N); cout << ans; return 0;
}