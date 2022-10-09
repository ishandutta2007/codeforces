#include <bits/stdc++.h>
using namespace std;

int f(int x) {
	int p = 1;
	while (x > 0) {
		if (x % 10) {
			p *= x % 10;
		}
		x /= 10;
	}
	return p;
}

int g(int n) {
	if (n < 10) {
		return n;
	}
	return g(f(n));
}

vector<int> pos[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=1; i<=1000000; i++) {
		pos[g(i)].push_back(i);
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		cout << lower_bound(pos[x].begin(), pos[x].end(), r+1) -
			lower_bound(pos[x].begin(), pos[x].end(), l) << '\n';
	}

}