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

	int k, d;
	cin >> k >> d;
	if (k == 1) {
		cout << d << '\n';
	} else {
		if (d == 0) {
			cout << "No solution\n";
		} else {
			cout << d << string(k-1, '0') << '\n';
		}
	}
}