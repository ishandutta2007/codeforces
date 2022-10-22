#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> nums;

bool inb(int x, int y, int z) {
	if(x <= y && y <= z) return true;
	if(x >= y && y >= z) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		nums.resize(n);
		for(int i = 0; i < n; i++) cin >> nums[i];
		ll ans = 2*n-1;
		for(int i = 0; i < n-2; i++) {
			ans++;
			if(inb(nums[i], nums[i+1], nums[i+2])) ans--;
		}
		for(int i = 0; i < n-3; i++) {
			ans++;
			if(inb(nums[i], nums[i+1], nums[i+2]) ||
				inb(nums[i], nums[i+1], nums[i+3]) ||
				inb(nums[i], nums[i+2], nums[i+3]) ||
				inb(nums[i+1], nums[i+2], nums[i+3])) ans--;
		}
		cout << ans << '\n';
		vector<int>().swap(nums);
	}
}