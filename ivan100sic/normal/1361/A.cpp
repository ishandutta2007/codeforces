// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
basic_string<int> e[500005];
int b[500005], a[500005], c[500005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	for (int i=1; i<=n; i++) cin >> b[i];

	iota(a, a+n+1, 0);
	sort(a+1, a+n+1, [&](int x, int y) { return b[x] < b[y]; });

	for (int i=1; i<=n; i++) {
		int x = a[i], ok = 1;
		vector<int> t(b[x]);
		for (int y : e[x]) {
			if (c[y] && c[y] < b[x]) {
				t[c[y]] = 1;
			} else if (c[y] == b[x]) {
				ok = 0;
			}
		}

		c[x] = b[x];

		if (count(begin(t)+1, end(t), 0) || !ok) {
			cout << "-1\n";
			return 0;
		}
	}

	for (int i=1; i<=n; i++) {
		cout << a[i] << " \n"[i == n];
	}
}