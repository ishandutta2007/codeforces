#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<ll> nums;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, k, lim = 1;
		cin >> n >> k;
		ll ans = -999999999;
		nums.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
		} //
		while(lim <= n) lim *= 2;
		for(ll i = n-1; i >= 0; i--) {
			for(ll j = i-1; j >= 0; j--) {
				if((i+1)*(j+1) < ans) break;
				ans = max(ans, ((i+1) * (j+1)) - k * (nums[i] | nums[j]));
			}
		}
		cout << ans << '\n';
		vector<ll>().swap(nums);
	}
}