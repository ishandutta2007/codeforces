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

long long dubina(long long ord, long long x) {
	while (x % 2 == 0) {
		ord--;
		x >>= 1;
	}
	return ord;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long n, ord;
	int q;

	cin >> n >> q;
	ord = 0;
	while ((1ll << (ord+1))-1 < n) {
		ord++;
	}

	while (q--) {
		long long x, d;
		string s;
		cin >> x >> s;
		d = dubina(ord, x);
		for (char c : s) {
			if (c == 'L') {
				if (d == ord) {
					continue;
				} else {
					x -= 1ll << (ord - d - 1);
					d++;
				}
			} else if (c == 'R') {
				if (d == ord) {
					continue;
				} else {
					x += 1ll << (ord - d - 1);
					d++;
				}
			} else {
				if (d == 0) {
					continue;
				} else {
					long long y = (x >> (ord - d)) & 3;
					if (y == 1) {
						x += 1ll << (ord - d);
					} else {
						x -= 1ll << (ord - d);
					}
					d--;
				}
			}
		}
		cout << x << '\n';
	}

}