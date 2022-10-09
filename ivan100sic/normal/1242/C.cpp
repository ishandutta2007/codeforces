#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<ll> a[15], b[15];
map<ll, pair<int, int>> gde;
bool vis[15][5005];
pair<int, int> nx[15][5005];

ll gr[15][15], delta[15];
bool has[15][15];

vector<pair<int, int>> tr[1 << 15];
int pre[1 << 15];
pair<ll, int> ans[15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	ll z = 0;
	for (int i=0; i<n; i++) {
		int k;
		cin >> k;
		a[i].resize(k);
		for (ll& x : a[i]) {
			cin >> x;
			z += x;
		}
		sort(a[i].begin(), a[i].end());
		for (int j=0; j<k; j++)
			gde[a[i][j]] = {i, j};
	}
	if (z % n) {
		cout << "No\n";
		return 0;
	}

	z /= n;

	for (int i=0; i<n; i++) {
		ll d = z - accumulate(a[i].begin(), a[i].end(), 0ll);
		delta[i] = d;
		b[i].resize(a[i].size());
		for (int j=0; j<(int)a[i].size(); j++)
			b[i][j] = a[i][j] + d;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<(int)b[i].size(); j++) {
			if (gde.count(b[i][j])) {
				nx[i][j] = gde[b[i][j]];
			} else {
				nx[i][j] = {-1, -1};
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<(int)b[i].size(); j++) {
			int x = i, y = j;
			int mask = 1 << x;
			vector<pair<int, int>> trace;
			while (1) {
				auto [xx, yy] = nx[x][y];
				if (xx == -1) {
					mask = -1;
					break;
				}
				trace.emplace_back(x, y);
				x = xx;
				y = yy;
				if (mask & (1 << x))
					break;
				mask |= 1 << x;
			}
			if (x == i && y == j && mask != -1) {
				tr[mask] = trace;
			}
		}
	}

	int full = (1<<n) - 1;

	for (int base=0; base<=full; base++) {
		int comp = full - base;
		if (base && !pre[base])
			continue;
		for (int mask=comp; mask; mask=(mask-1)&comp) {
			if (tr[mask].size()) {
				pre[base | mask] = mask;
			}
		}
	}

	if (!pre[full]) {
		cout << "No\n";
		return 0;
	}

	int curr = full;
	while (curr) {
		auto trace = tr[pre[curr]];
		for (auto [x, y] : trace) {
			ans[gde[b[x][y]].first] = {b[x][y], x};
		}
		curr -= pre[curr];
	}

	cout << "Yes\n";
	for (int i=0; i<n; i++)
		cout << ans[i].first << ' ' << ans[i].second + 1 << '\n';
}