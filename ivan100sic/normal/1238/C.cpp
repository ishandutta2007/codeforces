// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int h, n;
		cin >> h >> n;
		int last = h, odd = 0, sol = 0;
		{ int x; cin >> x; }
		for (int i=0; i<n-1; i++) {
			int x;
			cin >> x;
			if (x == last - 1) {
				odd ^= 1;
			} else {
				if (odd) {
					// mora ubacim
					sol++;
					odd = 0;
					last--;
					if (x == last - 1) {
						odd ^= 1;
					} else {
						odd = 1;
					}
				} else {
					odd = 1;
				}
			}
			last = x;
		}
		cout << sol + (last > 1 && odd) << '\n';
	}
}

// I will still practice daily...