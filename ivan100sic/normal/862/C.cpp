#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;

	if (n == 1) {
		cout << "YES\n" << x << '\n';
		return 0;
	}

	if (n == 2) {
		if (x == 0) {
			cout << "NO\n";
		} else {
			cout << "YES\n0 " << x << '\n';
		}
		return 0;
	}

	if (n % 2 == 1) {
		int t = 200000, res = 0;
		cout << "YES\n";
		for (int i=0; i<n-1; i++) {
			res ^= t;
			cout << t << ' ';
			t++;
			
		}
		cout << (x ^ res) << '\n';
		return 0;
	}

	if (n % 2 == 0) {
		int t = 200000, res = 0;
		cout << "YES\n";
		cout << (19 << 14) << ' ' << (32 << 14) << ' ' << (51 << 14) << ' ';

		for (int i=0; i<n-4; i++) {
			res ^= t;
			cout << t << ' ';
			t++;
		}
		cout << (x ^ res) << '\n';
		return 0;
	}




	

}