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

	int n;
	cin >> n;
	ll sol = 1;
	int last = -1;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (!x)
			continue;
		if (last == -1) {
			last = i;
		} else {
			sol *= i - last;
			last = i;
		}
	}
	if (last == -1)
		sol = 0;
	cout << sol << '\n';
}