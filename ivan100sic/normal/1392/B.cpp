// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		ll k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& x : a)
			cin >> x;
		if (k >= 3) {
			k = 2 + k % 2;
		}

		while (k--) {
			int d = *max_element(begin(a), end(a));
			for (int& x : a)
				x = d - x;
		}

		for (int x : a)
			cout << x << ' ';
		cout << '\n';
	}
}