#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> nums;

void add(int n, int k) { // changes nums
	int i = 0;
	while(n) {
		nums[i] += (n%k);
		if(nums[i] >= k) nums[i] -= k;
		n /= k; i++;
	}
}

int addnum(int n, int k) { // returns current value when originally n
	int ans = 0, g = 1;
	for(int i = 0; i < 20; i++) {
		int x = n%k - nums[i];
		if(x < 0) x += k;
		ans += x * g;
		g *= k; n /= k;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k, x;
		cin >> n >> k;
		nums.resize(20);
		for(int i = 0; i < n; i++) {
			int g = addnum(i, k);
			cout << g << endl;
			cin >> x;
			if(x) break;
			add(g, k);
		}
		vector<int>().swap(nums);
	}
}