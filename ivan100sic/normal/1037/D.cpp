#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<int> e[200005];

int a[200005], inv[200005], b[200005];
bool v[200005];

bool cmp(int x, int y) {
	return inv[x] < inv[y];
}

void bfs() {
	int qs = 1, qe = 1;
	b[qe++] = 1;
	v[1] = 1;
	while (qs < qe) {
		int x = b[qs++];
		for (int y : e[x]) {
			if (!v[y]) {
				v[y] = 1;
				b[qe++] = y;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		inv[a[i]] = i;
	}

	for (int i=1; i<=n; i++)
		sort(e[i].begin(), e[i].end(), cmp);

	bfs();

	cout << (equal(a+1, a+n+1, b+1) ? "Yes\n" : "No\n");
}