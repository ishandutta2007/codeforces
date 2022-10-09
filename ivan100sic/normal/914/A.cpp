#include <bits/stdc++.h>
using namespace std;

bool is_psq(int x) {
	for (int i=0; i<=1000; i++) {
		if (i*i == x) {
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t, y= -1e9;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (!is_psq(x)) {
			y = max(y, x);
		}
	}

	cout << y;
}