#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int gcd(int x, int y) {
	x = abs(x);
	y = abs(y);
	if (x == 0 || y == 0) {
		return x + y;
	}
	return gcd(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(false);
	auto start = chrono::system_clock::now();
	int n;
	cin >> n;
	if (n <= 60) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cout << "? " << i + 1 << endl;
			cin >> v[i];
		}
		sort(all(v));
		cout << "! " << v[0] << " " << v[1] - v[0] << endl;
		return 0;
	}
	int L = -1;
	int R = 1000000000;
	int mid;
	while (R - L > 1) {
		mid = L + (R - L) / 2;
		cout << "> " << mid << endl;
		int p;
		cin >> p;
		if (p) {
			L = mid;
		} else {
			R = mid;
		}
	}
	int mx = R;
	auto cur = chrono::system_clock::now();
	mt19937 mt(chrono::duration_cast<chrono::microseconds>(cur - start).count() ^ 413);
	int diff = 0;
	uniform_int_distribution<int> uid(1, n);
	for (int i = 0; i < 30; ++i) {
		cout << "? " << uid(mt) << endl;
		int x;
		cin >> x;
		diff = gcd(diff, mx - x);
	}
	cout << "! " << mx - (n - 1) * diff << " " << diff << endl;
}