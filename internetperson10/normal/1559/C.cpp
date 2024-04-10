#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<int> nums;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, f = -1;
		cin >> n;
		nums.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		for(int i = 0; i < n-1; i++) {
			if(nums[i] == 0 && nums[i+1] == 1) {
				f = i+1;
			}
		}
		if(f != -1) {
			for(int i = 0; i < f; i++) {
				cout << i+1 << ' ';
			}
			cout << n+1 << ' ';
			for(int i = f; i < n; i++) {
				cout << i+1 << ' ';
			}
		}
		else if(nums[n-1] == 0) {
			for(int i = 0; i < n+1; i++) {
				cout << i+1 << ' ';
			}
		}
		else {
			cout << n+1 << ' ';
			for(int i = 0; i < n; i++) {
				cout << i+1 << ' ';
			}
		}
		cout << '\n';
	}
}