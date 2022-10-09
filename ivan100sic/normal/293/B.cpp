#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 1'000'000'007;

int n, m, k;
int a[10][10];
vector<pair<int, int>> pos;

ll rek(int id) {
	if (id == n*m)
		return 1;

	auto [x, y] = pos[id];

	bool ok[11], any[11];
	memset(any, 0, sizeof any);
	if (a[x][y] == 0) {
		fill(ok+1, ok+k+1, true);
	} else {
		fill(ok+1, ok+k+1, false);
		ok[a[x][y]] = true;
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			any[a[i][j]] = true;

	int t = a[x][y];
	a[x][y] = 0;

	for (int i=0; i<=x; i++)
		for (int j=0; j<=y; j++)
			ok[a[i][j]] = false;

	for (int i=x; i<n; i++)
		for (int j=y; j<m; j++)
			ok[a[i][j]] = false;

	bool anydone = false;
	ll anyval = 0;
	ll ret = 0;

	for (int i=1; i<=k; i++) {
		if (ok[i]) {
			if (!any[i]) {
				if (!anydone) {
					a[x][y] = i;
					ll t = rek(id+1);
					anydone = true;
					ret += t;
					anyval = t;
				} else {
					ret += anyval;
				}
			} else {
				a[x][y] = i;
				ret += rek(id+1);
			}
		}
	}

	a[x][y] = t;
	return ret;
}

int cnt(pair<int, int> p) {
	auto [x, y] = p;
	int z = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if ((i <= x && j <= y) || (i >= x && j >= y))
				z++;
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;

	if (n+m-1 > k) {
		cout << "0\n";
		return 0;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int x;
			cin >> x;
			a[i][j] = x;
			pos.emplace_back(i, j);
		}
	}

	sort(pos.begin(), pos.end(), [&](auto p, auto q) {
		return cnt(p) > cnt(q);
	});

	ll sol = rek(0);

	cout << sol % mod << '\n';
}