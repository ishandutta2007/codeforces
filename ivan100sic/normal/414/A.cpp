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

	int n, k;
	cin >> n >> k;

	if (n == 1) {
		if (k > 0)
			cout << "-1\n";
		else
			cout << "1\n";
		return 0;
	}

	if (n/2 > k) {
		cout << "-1\n";
		return 0;
	}

	int z = n/2 - 1;

	for (int i=1; i<=2*z; i++)
		cout << i << ' ';

	k -= z;

	int p = 2*z/k*k + k;
	int q = p + k;
	cout << p << ' ' << q;

	if (n % 2) {
		cout << " 999999999\n";
	} else {
		cout << '\n';
	}
}