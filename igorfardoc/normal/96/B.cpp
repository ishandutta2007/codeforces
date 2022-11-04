#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;


vl get_all_good() {
	vl result;
	for(int l = 2; l <= 12; l += 2) {
		for(int mask = 0; mask < (1 << l); mask++) { // 101111 001011 // 1 or 0
			int amount0 = 0;
			int amount1 = 0;
			for(int i = 0; i < l; i++) {
				if((mask >> i) & 1) {
					++amount1;
				} else {
					++amount0;
				}
			}
			if(amount0 != amount1) continue;
			ll number = 0;
			for(int i = 0; i < l; i++) {
				if((mask >> i) & 1) {
					number = number * 10 + 7;
				} else {
					number = number * 10 + 4;
				}
			}
			result.push_back(number);
		}
	}
	return result;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	auto res = get_all_good();
	int n;
	cin >> n;
	ll ans = -1;
	for(int i = 0; i < res.size(); i++) {
		if(res[i] < n) continue;
		if(ans == -1 || ans > res[i]) {
			ans = res[i];
		}
	}
	cout << ans;
}