#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int pow[31];
	pow[0] = 1;
	for (int i = 1; i <= 29; i++) {
		pow[i] = pow[i - 1] * 2;
	}
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		int min1 = 1000000000000LL;
		int ind = -1LL;
		for (int j = 0; j <= 29; j++) {
			if (abs(pow[j] - arr[i]) < min1) {
				min1 = abs(pow[j] - arr[i]);
				ind = j;
			}
		}
		b[i] = pow[ind];
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}