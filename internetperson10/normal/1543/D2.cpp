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

int addnum(int n, int k, int c) { // returns current value when originally n
	int ans = 0, g = 1;
	for(int i = 0; i < c; i++) {
		int x = nums[i] + (n%k);
		if(x >= k) x -= k;
		ans += x * g;
		g *= k; n /= k;
	}
	return ans;
}

int subnum(int n, int k, int c) { // returns current value when originally n
	int ans = 0, g = 1;
	for(int i = 0; i < c; i++) {
		int x = nums[i] - (n%k);
		if(x < 0) x += k;
		ans += x * g;
		g *= k; n /= k;
	}
	return ans;
}

void reverse(int c, int k) {
	int g = 1, i = 0;
	while(i != c) {
		nums[i] = k - nums[i];
		nums[i] %= k;
		i++; g *= k;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k, x;
		int base = 1, g = 0;
		cin >> n >> k;
		while(base < n) {
			base *= k; g++;
		}
		nums.resize(20);
		for(int i = 0; i < n; i++) {
			int guess;
			if(i%2) guess = subnum(i, k, g);
			else guess = addnum(i, k, g);
			cout << guess << endl;
			cin >> x;
			if(x) break;
			reverse(g, k);
			add(guess, k);
			// cout << nums[2] << nums[1] << nums[0] << '\n';
		}
		vector<int>().swap(nums);
	}
}