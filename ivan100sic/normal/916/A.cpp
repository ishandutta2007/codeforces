// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool l(int x) {
	while (x) {
		if (x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int x, h, m;
	cin >> x >> h >> m;

	for (int i=0; i<100000; i++) {
		if (l(h) || l(m)) {
			cout << i << '\n';
			return 0;
		}

		m -= x;
		if (m < 0) {
			m += 60;
			h--;
			if (h < 0) {
				h += 24;
			}
		}
	}
}