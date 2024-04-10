#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[300005], q;
int b[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	for (int i=1; i<=n; i++)
		q += i;

	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++], z = 0;
		for (int y : e[x])
			if (b[y] == b[x])
				z++;
		if (z > 1) {
			b[x] ^= 1;
			for (int y : e[x])
				q += y;
		}
	}

	for (int i=1; i<=n; i++)
		cout << b[i];
	cout << '\n';
}