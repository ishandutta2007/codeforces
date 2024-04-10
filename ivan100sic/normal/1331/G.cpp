// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<11; i++)
		cin >> a[i];
	reverse(a, a+11);
	cout << setprecision(2) << fixed;
	for (int i=0; i<11; i++) {
		ld x = a[i];
		ld v = 5*x*x*x + sqrt(abs(x));
		if (v > 400) {
			cout << "f(" << (int)x << ") = MAGNA NIMIS!\n";
		} else {
			cout << "f(" << (int)x << ") = " << v << "\n";
		}
	}
}

// I will still practice daily...