#include <bits/stdc++.h>
using namespace std;

int c[105], n, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	for (int i=1; i<=n; i++) {
		int y;
		cin >> y;
		c[y]++;
	}

	int sol = 0;

	for (int i=0; i<x; i++) {
		if (c[i] == 0) {
			sol++;
		}
	}

	if (c[x]) {
		sol++;
	}

	cout << sol;
}