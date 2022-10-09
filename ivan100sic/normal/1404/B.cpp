// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

basic_string<int> e[100005];
int n, a, b, da, db;

int d[100005];

void bfs(int x) {
	for (int i=1; i<=n; i++) d[i] = -1;
	d[x] = 0;
	basic_string<int> q = {x};
	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (int y : e[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				q += y;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b >> da >> db;
		for (int i=1; i<=n; i++) e[i] = {};
		for (int i=1; i<n; i++) {
			int x, y;
			cin >> x >> y;
			e[x] += y;
			e[y] += x;
		}

		bfs(a);
		int db_ = d[b];

		int c = max_element(d+1, d+n+1) - d;
		bfs(c);

		int diam = *max_element(d+1, d+n+1);

		if (db_ <= da) {
			cout << "Alice\n";
		} else if (db > 2*da && diam > 2*da) {
			cout << "Bob\n";
		} else {
			cout << "Alice\n";
		}
	}
}