#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int u[100005], v[100005], c[100005];
int n, m;

basic_string<int> e[100005];
int indeg[100005];
int topo_index[100005];

bool ok(int x) {
	for (int i=1; i<=n; i++) {
		e[i] = {};
		indeg[i] = 0;
	}

	for (int i=0; i<m; i++)
		if (c[i] > x) {
			e[u[i]] += v[i];
			indeg[v[i]]++;
		}

	queue<int> q;
	for (int i=1; i<=n; i++)
		if (indeg[i] == 0)
			q.push(i);

	int idx = 0;

	while (q.size()) {
		int x = q.front(); q.pop();
		topo_index[x] = ++idx;
		for (int y : e[x]) {
			indeg[y]--;
			if (indeg[y] == 0) {
				q.push(y);
			}
		}
	}

	return *max_element(indeg+1, indeg+n+1) == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i] >> c[i];
	}

	int l = 0, r = 1e9, o = -1;
	while (l <= r) {
		int mid = (l+r) >> 1;
		if (ok(mid)) {
			o = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << o << ' ';
	// nadji puteve
	ok(o);
	basic_string<int> rev;

	for (int i=0; i<m; i++) {
		int u = ::u[i];
		int v = ::v[i];
		if (c[i] > o)
			continue;
		if (topo_index[u] > topo_index[v])
			rev += i+1;
	}

	cout << rev.size() << '\n';
	for (int x : rev)
		cout << x << ' ';
	cout << '\n';
}