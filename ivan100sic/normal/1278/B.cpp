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

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		a = abs(a - b);
		int z = 0;
		for (int i=0;; i++) {
			z += i;
			if (z >= a && z % 2 == a % 2) {
				cout << i << '\n';
				break;
			}
		}
	}
}