#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

int a[4005], z[4005], n;
unordered_map<int, int> dp1;
unordered_map<int, int> dp2;

inline int hsh(short a, short b, short c) {
	return a + 4096 * b + 16777216 * c;
}

int solve_player1(short l, short r, short k);

int solve_player2(short l, short r, short k) {
	int h = hsh(l, r, k);
	auto it = dp2.find(h);
	if (it != dp2.end()) {
		return it->second;
	}

	int& itt = dp2[h];
	itt = 0;

	int val = -1999999999;

	if (k <= r-l+1) {
		val = max(val, z[r] - z[r-k] - solve_player1(l, r-k, k));
	}

	if (k+1 <= r-l+1) {
		val = max(val, z[r] - z[r-k-1] - solve_player1(l, r-k-1, k+1));
	}

	if (val == -1999999999) {
		return 0;
	} else {
		return itt = val;
	}
}

int solve_player1(short l, short r, short k) {
	int h = hsh(l, r, k);
	auto it = dp1.find(h);
	if (it != dp1.end()) {
		return it->second;
	}

	int& itt = dp1[h];
	itt = 0;

	int val = -1999999999;

	if (k <= r-l+1) {
		val = max(val, z[l+k-1] - z[l-1] - solve_player2(l+k, r, k));
	}

	if (k+1 <= r-l+1) {
		val = max(val, z[l+k] - z[l-1] - solve_player2(l+k+1, r, k+1));
	}

	if (val == -1999999999) {
		return 0;
	} else {
		return itt = val;
	}
}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1] + a[i];
	}

	dp1.rehash(6000000);
	dp2.rehash(12000000);

	cout << solve_player1(1, n, 1) << '\n';
	cerr << dp1.size() << ' ' << dp2.size() << '\n';
}