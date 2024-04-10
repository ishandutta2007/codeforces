#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[500005], ans[500005];
basic_string<pair<int, int>> q[500005];
pair<int, int> g[20];

void add(pair<int, int> p) {
	for (int i=19; i>=0; i--) {
		if ((1 << i) & p.first) {
			if (g[i].first) {
				if (g[i].second < p.second)
					swap(g[i], p);
				p.first ^= g[i].first;
			} else {
				g[i] = p;
				return;
			}
		}
	}
}

int run(int x) {
	int y = 0;
	for (int i=19; i>=0; i--)
		if (g[i].second >= x)
			y = max(y, y ^ g[i].first);
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	cin >> m;

	for (int i=0; i<m; i++) {
		int l, r;
		cin >> l >> r;
		q[r] += {l, i};
	}

	for (int i=1; i<=n; i++) {
		add({a[i], i});
		for (auto p : q[i]) {
			ans[p.second] = run(p.first);
		}
	}

	for (int i=0; i<m; i++)
		cout << ans[i] << '\n';
}