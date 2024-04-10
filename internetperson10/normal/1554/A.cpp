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
		int n;
		ll ans = 0;
		cin >> n;
		nums.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		for(int i = 0; i < n-1; i++) {
			ans = max(ans, nums[i] * nums[i+1]);
		}
		cout << ans << '\n';
		vector<ll>().swap(nums);
	}
}