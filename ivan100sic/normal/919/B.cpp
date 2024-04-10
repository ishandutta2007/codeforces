#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool p(int x) {
	int z = 0;
	while (x) {
		z += x % 10;
		x /= 10;
	}
	return z == 10;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int k;
	cin >> k;
	for (int i=1; ; i++) {
		if (p(i)) {
			k--;
			if (k == 0) {
				cout << i;
				return 0;
			}
		}
	}
}