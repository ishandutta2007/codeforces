#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long


ll dp[11][1 << 6][1 << 10], dp2[11][64][1024], sdp2[11][64][1024];

ll MAX = 1e18 + 10;
void go(int b){
	dp[b][0][0] = 1;
	int i = 1;
	ll val = b;
	for(; val <= MAX; i++, val *= b){
		for(int dig = 0; dig < b; dig++){
			for(int k = 0; k < 1024; k++){
				dp[b][i][k ^ (1 << dig)] += dp[b][i - 1][k];
				// if(k == 1 && b == 2 && i == 2 && dig == 1)
			}
		}
	}

	for(int i = 1; i < b; i++) dp2[b][1][1 << i] = 1;

	i = 2;
	val = b * b;

	for(; val <= MAX; i++, val *= b){

		// dig = 0;
		for(int k = 0; k < 1024; k++) dp2[b][i][k] = dp2[b][i - 1][k];
		for(int dig = 1; dig < b; dig++){
			for(int k = 0; k < 1024; k++)
				dp2[b][i][k ^ (1 << dig)] += dp[b][i - 1][k];
		}
	}

	for(int j = 1; j < i; j++){
		for(int k = 0; k < 1024; k++)
			sdp2[b][j][k] = sdp2[b][j - 1][k] + dp2[b][j][k];
	}
}

ll get(ll n, int b){
	if(n == 0) return 0;
	vector<int> vec;
	while(n > 0){
		vec.push_back(n % b);
		n /= b;
	}
	reverse(vec.begin(), vec.end());
	int req = 0;
	ll  ans = dp2[b][vec.size() - 1][req];
	// for(int i = 1; i < vec.size(); i++){
	// 	ans += dp2[b][i][req];

	// }
	
	for(int i = 0; i < vec.size(); i++){
		int h = vec[i];
		int rem = vec.size() - i - 1;
		for(int j = 0; j < h; j++){
			if(i == 0 && j == 0) continue;
			ans += dp[b][rem][req ^ (1 << j)];
		}

		// put h here
		req ^= (1 << h);
		if(i == vec.size() - 1 && req == 0)
			ans++;
	}
	return ans;
}

int main(){
	for(int b = 2; b <= 10; b++) go(b);
	int t;
	scanf("%d", &t);
	// cerr << dp2[10][18][0] << endl;
	while(t--){
		ll l, r;
		int b;
		scanf("%d %lld %lld", &b, &l, &r);
		printf("%lld\n", get(r, b) - get(l - 1, b));
	}
}