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

	int x;
	cin >> x;
	if (!x) {
		cout << "0\n";
		return 0;
	}
	else if (x < 0)
		x = -x;
	int z = 0;
	for (int i=1;; i++) {
		z += i;
		if (z >= x && z % 2 == x % 2) {
			cout << i << '\n';
			return 0;
		}
	}
}