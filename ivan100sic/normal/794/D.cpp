#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;
vector<int> e[300005];

int c[300005];
size_t h[300005];
int d[300005];

// stolen from https://stackoverflow.com/questions/20511347/a-good-hash-function-for-a-vector
size_t hasher(const vector<int>& a) {
	size_t seed = a.size();
	for (size_t x : a) {
		seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
	}
	return seed;
}

bool ima(int x, int y) {
	auto it = lower_bound(e[x].begin(), e[x].end(), y);
	if (it == e[x].end()) {
		return false;
	}
	return *it == y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	for (int i=1; i<=n; i++) {
		e[i].push_back(i);
		sort(e[i].begin(), e[i].end());
		h[i] = hasher(e[i]);
	}

	/*
	for (int i=1; i<=n; i++) {
		cerr << "h: " << h[i] << '\n';
	}
	*/

	deque<int> q;
	q.push_back(1);
	fill(d+1, d+n+1, -1);
	d[1] = 0;

	while (!q.empty()) {
		int x = q.front(); q.pop_front();

		for (int y : e[x]) {
			int l = h[x] == h[y] ? 0 : 1;
			if (d[y] == -1) {
				d[y] = d[x] + l;
				if (l == 0) {
					q.push_front(y);
				} else {
					q.push_back(y);
				}
			}
		}
	}

	// nadji najdalji i ponovi iz njega
	int x0 = max_element(d+1, d+n+1) - d;

	cerr << x0 << '\n';

	q.push_back(x0);
	fill(d+1, d+n+1, -1);
	d[x0] = 1;

	while (!q.empty()) {
		int x = q.front(); q.pop_front();

		for (int y : e[x]) {
			int l = h[x] == h[y] ? 0 : 1;
			if (d[y] == -1) {
				d[y] = d[x] + l;
				if (l == 0) {
					q.push_front(y);
				} else {
					q.push_back(y);
				}
			}
		}
	}

	/*
	for (int i=1; i<=n; i++) {
		cerr << "d " << d[i] << '\n';
	}
	*/

	// verify

	vector<int> br(n+1, 0);
	for (int x=1; x<=n; x++) {
		br[d[x]]++;
	}

	ll ocek = 0;
	for (int i=1; i<=n; i++) {
		ocek += br[i] * (br[i]-1ll) / 2;
		ocek += br[i] * 1ll * (br[i-1]);
	}

	if (ocek != m) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (int i=1; i<=n; i++) {
			cout << d[i] << ' ';
		}
	}
		

}