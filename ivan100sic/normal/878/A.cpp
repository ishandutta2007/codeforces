#include <bits/stdc++.h>
using namespace std;

int n;

string comm[500005];
int a[500005];

int f0[10], f1[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> comm[i] >> a[i];
	}

	int x = 0;
	for (int j=1; j<=n; j++) {
		if (comm[j] == "|") {
			x |= a[j];
		} else if (comm[j] == "^") {
			x ^= a[j];
		} else {
			x &= a[j];
		}
	}
	for (int i=0; i<10; i++) {
		f0[i] = (x >> i) & 1;
	}

	x = 1023;

	for (int j=1; j<=n; j++) {
		if (comm[j] == "|") {
			x |= a[j];
		} else if (comm[j] == "^") {
			x ^= a[j];
		} else {
			x &= a[j];
		}
	}
	for (int i=0; i<10; i++) {
		f1[i] = (x >> i) & 1;
	}

	// xor sa cime?
	x = 0;
	for (int i=0; i<10; i++) {
		if (f0[i] && !f1[i]) {
			x ^= (1 << i);
			f0[i] ^= 1;
			f1[i] ^= 1;
		}
	}
	cout << "3\n";
	cout << "^ " << x << '\n';

	// and sa cime
	x = 0;
	for (int i=0; i<10; i++) {
		if (!f1[i]) {
			//
		} else {
			x += (1 << i);
		}
	}
	cout << "& " << x << '\n';

	// or sa cime
	x = 0;
	for (int i=0; i<10; i++) {
		if (f0[i]) {
			x += (1 << i);
		} else {
			// 
		}
	}
	cout << "| " << x << '\n';

}