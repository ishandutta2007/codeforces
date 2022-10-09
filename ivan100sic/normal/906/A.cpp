#include <bits/stdc++.h>
using namespace std;

const int base = (1 << 26) - 1;

int ms(string s) {
	int m = 0;
	for (char x : s) {
		m |= (1 << (x - 'a'));
	}
	return m;
}

bool kec(int x) {
	return __builtin_popcount(x) == 1;
}

int s;

void evo() {
	s++;
	// cerr << "ovde\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	int mask = base;

	while (n--) {
		string a, b;
		cin >> a >> b;
		if (a == ".") {
			mask &= (base - ms(b));
		} else if (a == "!") {
			if (kec(mask)) {
				evo();
			}
			mask &= ms(b);
		} else {
			if (kec(mask) && (mask != ms(b))) {
				evo();
			}
			mask &= (base - ms(b));
		}
	}

	cout << s;
}