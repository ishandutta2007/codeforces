#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

long long klika(long long e) {
	long long l = 1, r = 1e9, o = -1;
	while (l <= r) {
		long long m = (l+r) / 2;
		if (m * (m-1) / 2 >= e) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	return o;
}

long long reverz(long long g) {
	long long m = (g+1) / 2;

	long long vertices = m + 1;
	long long nonbridges = g - m;

	return klika(nonbridges) + vertices - 1;
}

long long ans(long long x) {
	if (x == 1) {
		return 0;
	}
	if (x == 2) {
		return 1;
	}
	if (x == 3) {
		return 2;
	}
	if (x == 4) {
		return 3;
	}
	if (x == 5) {
		return 4;
	} else {
		long long l = 6, r = 2e10, o = -1;
		while (l <= r) {
			long long m = (l + r) / 2;
			long long p = reverz(m);
			if (p <= x) {
				o = m;
				l = m+1;
			} else {
				r = m-1;
			}
		}
		return o;
		// return 123123;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	/*
	for (int i=6; i<=20; i++) {
		cerr << i << ' ' << reverz(i) << '\n';
	}
	

	for (int i=1; i<=20; i++) {
		cerr << i << ' ' << ans(i) << '\n';
		if (i % 5 == 0) {
			cerr << '\n';
		}
	}
	*/

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << ans(x) << '\n';
	}
}