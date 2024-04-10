#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> nums, nums2;
int lift[20][200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, g;
		cin >> n;
		nums.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
			if(i == 0) g = nums[i];
			else g = __gcd(g, nums[i]);
		}
		int maxi = 0;
		for(int i = 0; i < n; i++) {
			nums[i] /= g;
			maxi = max(maxi, nums[i]);
			lift[0][i] = nums[i];
		}
		// cout << '\n';
		if(maxi == 1) {
			cout << 0 << '\n';
			continue;
		}
		for(int z = 1; z < 20; z++) {
			for(int i = 0; i < n; i++) {
				lift[z][i] = __gcd(lift[z-1][i], lift[z-1][(i + (1 << (z-1)))%n]);
			}
		}
		bool found = false;
		int ans = 0;
		for(int z = 19; z >= 0; z--) {
			if(found) {
				bool good = false;
				for(int i = 0; i < n; i++) {
					// cout << lift[z][i] << ' ';
					if(__gcd(lift[z][(i + ans)%n], nums[i]) > 1) good = true;
				}
				if(good) {
					for(int i = 0; i < n; i++) {
						// cout << nums[i] << ' ';
						nums[i] = __gcd(nums[i], lift[z][(i + ans)%n]);
					}
					// for(int i = 0; i < n; i++) {
					// 	cout << nums[i] << ' ';
					// }
					ans += (1 << z);
					// cout << '\n';
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
		cout << ans << '\n';
		vector<int>().swap(nums);
	}
}