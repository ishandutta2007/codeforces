// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[100005];
vector<tuple<int, int, int>> sol;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	if (n % 2 == 0 && accumulate(a+1, a+n+1, 0, bit_xor<int>()) != 0) {
		cout << "NO\n";
		return 0;
	}

	for (int i=1; i+2<=n; i+=2) {
		int x = a[i] ^ a[i+1] ^ a[i+2];
		a[i] = a[i+1] = a[i+2] = x;
		sol.emplace_back(i, i+1, i+2);
	}

	if (n % 2 == 1) {
		for (int i=1; i+2<=n; i+=2) {
			int x = a[i] ^ a[i+1] ^ a[n];
			a[i] = a[i+1] = a[n] = x;
			sol.emplace_back(i, i+1, n);
		}
	} else {
		n--;
		for (int i=1; i+2<=n; i+=2) {
			int x = a[i] ^ a[i+1] ^ a[n];
			a[i] = a[i+1] = a[n] = x;
			sol.emplace_back(i, i+1, n);
		}
	}

	cout << "YES\n";
	cout << sol.size() << "\n";
	for (auto [x, y, z] : sol) {
		cout << x << ' ' << y << ' ' << z << '\n';
	}
}