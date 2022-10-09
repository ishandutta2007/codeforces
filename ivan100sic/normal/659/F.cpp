#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;

int n, m;
ll tot;
int a[1005][1005];
bool added[1005][1005];
basic_string<pii> v;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

template<class T>
auto R(T& p, pii u) -> decltype(p[0][0]) {
	return p[u.first][u.second];
}

bool cmp(pii u, pii v) {
	return R(a, u) > R(a, v);
}

pii p[1005][1005];
int z[1005][1005];

pii ep(pii u) {
	if (u == R(p, u))
		return u;
	return R(p, u) = ep(R(p, u));
}

void spoji(pii u, pii v) {
	// cerr << "spajam " << u.first << ' ' << u.second << " : " << v.first
		 // << ' ' << v.second << '\n';
	u = ep(u);
	v = ep(v);
	if (u == v)
		return;
	R(p, u) = v;
	R(z, v) += R(z, u);
}

void aktiviraj(pair<int, int> u) {
	R(added, u) = 1;
	R(z, u) = 1;
	for (int d=0; d<4; d++) {
		int x = u.first + dx[d];
		int y = u.second + dy[d];
		if (x < 0 || x >= n || y < 0 || y >= m)
			continue;
		if (added[x][y])
			spoji(u, {x, y});
	}
}

int ans[1005][1005];

void flood(pii p, ll val, ll cnt) {
	basic_string<pii> q = {p};
	R(a, p) = 0;
	ll qs = 0;
	while (qs < cnt) {
		auto r = q[qs++];
		// cerr << r.first << ' ' << r.second << '\n';
		R(ans, r) = val;
		for (int d=0; d<4; d++) {
			int x = r.first + dx[d];
			int y = r.second + dy[d];
			if (x < 0 || x >= n || y < 0 || y >= m)
				continue;
			if (a[x][y] < val)
				continue;
			a[x][y] = 0;
			q += {x, y};
		}
	}
	// cerr << "done: " << qs << ' ' << cnt << '\n';

	cout << "YES\n";
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cout << ans[i][j] << " \n"[j == m-1];
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> tot;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			cin >> a[i][j];
			v += {i, j};
			p[i][j] = {i, j};
		}
	sort(v.begin(), v.end(), cmp);

	for (auto p : v) {
		aktiviraj(p);
		// cerr << tot << ' ' << R(a, p) << ' ' << R(z, ep(p)) << '\n';

		if (tot % R(a, p) == 0 && tot / R(a, p) <= R(z, ep(p))) {
			flood(p, R(a, p), tot / R(a, p));
		}
	}

	cout << "NO\n";
}