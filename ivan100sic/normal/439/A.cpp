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

	int n, t;
	cin >> n >> t;
	int z = 10 * (n-1), j = 2*(n-1);
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		z += x;
	}
	if (z > t) {
		cout << "-1\n";
	} else {
		cout << (t-z) / 5 + j << '\n';
	}
}