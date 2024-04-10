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

const long long MOD = 1'000'000'007;

long long pw(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	long long t = pw(a, b/2);
	t = t*t % MOD;
	if (b % 2) {
		t = a*t % MOD;
	}
	return t;
}

long long brut(int n, int m) {
	long long h = pw(2*n, m);

	long long sol = 0;

	for (long long i=0; i<h; i++) {
		vector<int> occ(n, 0);
		bool bad = false;

		long long t = i;

		for (int j=0; j<m; j++) {
			int pos = t % (2*n);
			int dir = pos / n;
			pos %= n;
			t /= 2*n;

			if (dir == 0) {
				dir = 1;
			} else {
				dir = -1;
			}

			while (pos >= 0 && pos < n) {
				if (!occ[pos]) {
					occ[pos] = 1;
					break;
				} else {
					pos++;
				}
			}

			if (pos < 0 || pos >= n) {
				bad = true;
				break;
			}
		}

		if (!bad) {
			sol++;
		}
	}

	return sol;
}

long long fast(long long n, long long m) {
	if (m > n) {
		return 0;
	}

	return pw(2*n+2, m-1) * 2 * (n - m + 1) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	/*
	for (int i=1; i<=7; i++) {
		for (int j=1; j<=7; j++) {
			cout << '\t' << brut(i, j);
		}
		cout << '\n';
	}
	*/

	for (int i=1; i<=7; i++) {
		for (int j=1; j<=7; j++) {
			cerr << '\t' << fast(i, j);
		}
		cerr << '\n';
	}

	long long seats, ppl;
	cin >> seats >> ppl;

	cout << fast(seats, ppl) << '\n';
}