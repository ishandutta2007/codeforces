#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
string a[55];
bool vis[55][55];
vector<basic_string<pair<int, int>>> komps;

basic_string<pair<int, int>> bfs(int x, int y) {
	vis[x][y] = 1;
	basic_string<pair<int, int>> q = {{x, y}};
	size_t qs = 0;

	auto go = [&](int x, int y) {
		if (x < 0 || x >= n || y < 0 || y >= m)
			return;
		if (vis[x][y] || a[x][y] != '.')
			return;
		vis[x][y] = 1;
		q += {x, y};
	};

	while (qs != q.size()) {
		auto [x, y] = q[qs++];
		go(x+1, y);
		go(x-1, y);
		go(x, y+1);
		go(x, y-1);
	}

	return q;
}

bool cmp(
	basic_string<pair<int, int>> const& a,
	basic_string<pair<int, int>> const& b)
{
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i][j] == '.' && !vis[i][j]) {
				auto w = bfs(i, j);
				int ok = 1;
				for (auto [x, y] : w) {
					if (x == 0 || x == n-1 || y == 0 || y == m-1)
						ok = 0;
				}
				if (ok)
					komps.push_back(w);
			}
		}
	}
	sort(komps.begin(), komps.end(), cmp);
	int h = (int)komps.size()-k;
	int z = 0;
	for (int i=0; i<h; i++) {
		for (auto [x, y] : komps[i]) {
			a[x][y] = '*';
			z++;
		}
	}
	cout << z << '\n';
	for (int i=0; i<n; i++)
		cout << a[i] << '\n';
}