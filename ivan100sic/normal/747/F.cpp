#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int k, t;

int a[20];

// vrati na koliko nacina moze da se popuni places brojevima 1-16,
// ako broj i ne smemo da koristimo vise od amount[i] puta

int amount[20];

long long bik[40][40];

long long count_variants(int active, int places) {
	if (places < 0) {
		return 0;
	}

	if (active == 16) {
		if (places == 0) {
			return 1;
		} else {
			return 0;
		}
	}

	long long z = 0;

	for (int a=0; a<=amount[active] && a <= places; a++) {
		auto t = count_variants(active+1, places-a);
		z += t * bik[a][places-a];
		if (z > 2000000001ll) {
			z = 2000000001ll;
		}
	}

	return z;
}

void init_bik() {
	for (int i=0; i<40; i++) {
		for (int j=0; j<40; j++) {
			if (i == 0 || j == 0) {
				bik[i][j] = 1;
			} else {
				bik[i][j] = bik[i-1][j] + bik[i][j-1];
				if (bik[i][j] > 2000000001ll) {
					bik[i][j] = 2000000001ll;
				}
			}
		}
	}
}

void solve() {
	int len = 1;

	// u pocetku
	for (int i=0; i<16; i++) {
		amount[i] = t;
	}

	while (1) {
		long long z = 0;
		for (int d=1; d<16; d++) {
			amount[d]--;
			z += count_variants(0, len-1);
			amount[d]++;
		}
		if (z < k) {
			len++;
			k -= z;
		} else {
			break;
		}
	}

	cerr << "len: " << len << '\n';


	// i = 1
	{
		for (int d=1; d<16; d++) {
			amount[d]--;
			auto z = count_variants(0, len-1);

			cerr << d << ' ' << z << ' ' << k << '\n';

			if (z < k) {
				k -= z;
				amount[d]++;
			} else {
				a[1] = d;
				break;
			}
		}
	}

	for (int i=2; i<=len; i++) {
		for (int d=0; d<16; d++) {
			amount[d]--;
			auto z = count_variants(0, len-i);

			cerr << d << ' ' << z << '\n';

			if (z < k) {
				// nista, salili smo se, idemo dalje
				k -= z;
				amount[d]++;
			} else {
				// stoj
				a[i] = d;
				break;
			}
		}
	}

	for (int i=1; i<=len; i++) {
		cout << "0123456789abcdef"[a[i]];
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	init_bik();

	cin >> k >> t;

	solve();
}