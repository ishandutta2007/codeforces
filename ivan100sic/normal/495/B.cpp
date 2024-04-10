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

	int a, b;
	cin >> a >> b;

	if (a == b) {
		cout << "infinity\n";
	} else if (a < b) {
		cout << "0\n";
	} else {
		a -= b;
		int sol = 0;
		for (int x=1; x*x <= a; x++) {
			if (x*x == a) {
				if (x > b)
					sol++;
				break;
			}
			if (a % x == 0) {
				sol += x > b;
				sol += a/x > b;
			}
		}
		cout << sol << '\n';
	}
}