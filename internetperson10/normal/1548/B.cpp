#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<ll> nums;
ll lift[20][200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<ll>().swap(nums);
		nums.resize(n-1);
		ll x, y, g;
		cin >> y;
		for(int i = 0; i < n-1; i++) {
			cin >> x;
			nums[i] = abs(x-y);
			y = x;
			if(i == 0) g = nums[i];
			else g = __gcd(nums[i], g);
			// cout << nums[i] << ' ';
		}
		if(n == 1) {
			cout << 1 << '\n';
			continue;
		}
		n--;
		for(int i = 0; i < n; i++) lift[0][i] = nums[i];
		for(int z = 1; z < 20; z++) {
			for(int i = 0; i < n; i++) {
				if(i + (1 << z) > n) lift[z][i] = 1;
				else lift[z][i] = __gcd(lift[z-1][i], lift[z-1][i + (1 << (z-1))]);
			}
		}
		int ans = 0;
		bool found = false;
		for(int z = 19; z >= 0; z--) {
			if(found) {
				bool good = false;
				for(int i = 0; i < n; i++) {
					if(i+ans >= n) continue;
					else if(__gcd(lift[z][i+ans], nums[i]) > 1) good = true;
				}
				if(good) {
					for(int i = 0; i < n; i++) {
						if(i+ans < n) nums[i] = __gcd(nums[i], lift[z][i+ans]);
						else nums[i] = 1;
					}
					ans += (1 << z);
				}
			}
			else {
				bool good = false;
				for(int i = 0; i < n; i++) {
					if(lift[z][i] > 1) good = true;
				}
				if(good) {
					found = true;
					ans += (1 << z);
					for(int i = 0; i < n; i++) {
						nums[i] = lift[z][i];
					}
				}
			}
		}
		cout << ans+1 << '\n';
	}
}