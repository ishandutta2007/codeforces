// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int b[2], n, m;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		b[x > 0]++;
	}

	while (m--) {
		int l, r;
		cin >> l >> r;
		r = r-l+1;
		cout << (r % 2 == 0 && min(b[0], b[1]) >= r/2) << '\n';
	}
}