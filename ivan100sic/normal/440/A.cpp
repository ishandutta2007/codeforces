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

	int n, y=0;
	cin >> n;
	for (int i=1; i<=n; i++) {
		if (i < n) {
			int x;
			cin >> x;
			y ^= x;
		}
		y ^= i;
	}
	cout << y << '\n';
}