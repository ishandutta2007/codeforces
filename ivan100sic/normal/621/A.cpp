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

	int lo = 1123123123;
	int n;
	ll z = 0;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		z += x;
		if (x % 2)
			lo = min(lo, x);
	}
	if (z % 2)
		z -= lo;
	cout << z << '\n';
}