#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[500005], s[500005];

int e(int x) {
	if (x == p[x])
		return x;
	return p[x] = e(p[x]);
}

void spoji(int x, int y) {
	x = e(x);
	y = e(y);
	if (x == y)
		return;
	if (s[x] < s[y]) {
		swap(x, y);
	}
	p[y] = x;
	s[x] += s[y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	iota(p+1, p+n+1, 1);
	fill(s+1, s+n+1, 1);
	while (m--) {
		int x;
		cin >> x;
		if (x) {
			int y;
			cin >> y;
			while (--x) {
				int z;
				cin >> z;
				spoji(y, z);
			}
		}
	}
	for (int i=1; i<=n; i++) {
		cout << s[e(i)] << " \n"[i == n];
	}
}