#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], f[N], p[N];
vector<int> ps[N];

int fa(int u) { return f[u] == u ? u : f[u] = fa(f[u]); }
bool mg(int u, int v) { return (u = fa(u)) != (v = fa(v)) ? f[u] = v, 1 : 0; }

#define setv(i, v) p[i] = ps[v].back(), ps[v].pop_back()

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		ps[i].clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[a[i]].push_back(i);
	}

	for (int i = 1, cnt = n & 1; i <= n; i++)
		if (ps[i].size() & 1) {
			if (ps[i].back() == (n + 1) / 2)
				swap(ps[i].back(), ps[i][0]);
			if (ps[i].back() == (n + 1) / 2 || cnt -- == 0)
				return cout << "NO\n", (void) 0;
			setv((n + 1) / 2, i);
		}

	cout << "YES\n";

	for (int i = 1, l = 1, r = n; i <= n; i++) {
		while (ps[i].size()) {
			setv(l ++, i);
			setv(r --, i);
		}
	}

	iota(f + 1, f + n + 1, 1);

	for (int i = 1; i <= n; i++) mg(i, p[i]);

	for (int l = 1, r = n; l < r; l ++, r --)
		if (mg(l, r)) swap(p[l], p[r]);

	for (int l = 1, r = n; l < n / 2; l ++, r --)
		if (mg(l, l + 1)) {
			swap(p[l], p[r]);
			swap(p[l], p[l + 1]);
			swap(p[r], p[r - 1]);
		}

	for (int i = 1; i <= n; i++)
		cout << p[i] << " \n"[i == n];
}

int main() {
	int t;
	for (cin >> t; t --; )
		solve();
}