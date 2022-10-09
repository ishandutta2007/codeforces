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

	int q;
	cin >> q;
	while (q--) {
		int z=0, n;
		cin >> n;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			z += x;
		}
		cout << (z+n-1)/n << '\n';
	}
}