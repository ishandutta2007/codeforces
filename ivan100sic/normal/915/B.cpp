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

	int n, p, l, r;
	cin >> n >> p >> l >> r;
	if (l > 1 && r < n) {
		cout << 2 + min(abs(p-l) + abs(l-r), abs(p-r) + abs(r-l));
	} else if (l > 1) {
		cout << 1 + abs(p-l);		
	} else if (r < n) {
		cout << 1 + abs(p-r);
	} else {
		cout << 0;
	}
}