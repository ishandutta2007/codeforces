// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, sol;
ll a[200005], z[200005];
basic_string<int> e[32];

int r(int x) {
	return 32 - __builtin_clz(x);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i], z[i+1] = z[i] + a[i];

	auto chk = [&](int l, int r) {
		if (l >= 0 && r < n && r-l >= 2 && (a[l] ^ a[r] ^ (z[r] - z[l+1])) == 0) {
			sol++;
		}
	};

	for (int i=0; i<n; i++) {
		int h = r(a[i]);

		if (e[h].size()) chk(e[h].back(), i);
		if (e[h].size() >= 2) chk(e[h][e[h].size() - 2], i);

		for (int y=h+1; y<32; y++) {
			if (e[y].size()) chk(e[y].back(), i);
			if (e[y].size() >= 2) chk(e[y][e[y].size() - 2], i);
		}

		e[h] += i;
	}

	for (int i=0; i<32; i++) e[i] = {};

	for (int i=n-1; i>=0; i--) {
		int h = r(a[i]);

		for (int y=h+1; y<32; y++) {
			if (e[y].size()) chk(i, e[y].back());
			if (e[y].size() >= 2) chk(i, e[y][e[y].size() - 2]);
		}

		e[h] += i;
	}

	cout << sol << '\n';
}