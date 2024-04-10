#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[200005];
int d[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=1; i<=n; i++) {
			e[i] = {};
			d[i] = 123123123;
		}
		while (m--) {
			int u, v;
			cin >> u >> v;
			e[u] += v;
			e[v] += u;
		}
		basic_string<int> q = {1};
		size_t qs = 0;
		while (qs != q.size()) {
			int x = q[qs++];
			for (int y : e[x]) {
				if (d[y] == 123123123) {
					d[y] = d[x] + 1;
					q += y;
				}
			}
		}
		int r[2] = {0, 0};
		for (int i=1; i<=n; i++) {
			r[d[i] % 2]++;
		}	
		int z = r[1] < r[0];	
		cout << count_if(d+1, d+n+1, [&](int x) { return x % 2 == z; }) << '\n';
		for (int i=1; i<=n; i++)
			if (d[i] % 2 == z)
				cout << i << ' ';
		cout << '\n';
	}

}