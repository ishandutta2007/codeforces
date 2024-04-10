#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s[1005];
int da[1005][1005], db[1005][1005], dc[1005][1005];

template<class T>
void resi(char t, T d) {
	deque<pair<int, int>> q;
	memset(d, 31, sizeof(da));
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (s[i][j] == t) {
				q.push_back({i, j});
				d[i][j] = 0;
			}

	auto visit = [&](int x, int y, int dd) {
		if (x < 0 || x >= n || y < 0 || y >= m)
			return;
		if (s[x][y] == '#')
			return;
		if (d[x][y] < 12312312)
			return;
		if (s[x][y] == '.') {
			d[x][y] = dd + 1;
			q.emplace_back(x, y);
		} else {
			d[x][y] = dd;
			q.emplace_front(x, y);
		}
	};

	while (q.size()) {
		auto [x, y] = q.front(); q.pop_front();
		int dd = d[x][y];
		visit(x+1, y, dd);
		visit(x-1, y, dd);
		visit(x, y+1, dd);
		visit(x, y-1, dd);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	resi('1', da);
	resi('2', db);
	resi('3', dc);

	int sol = 123123123;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			sol = min(sol, da[i][j] + db[i][j] + dc[i][j] - (s[i][j] == '.' ? 2 : 0));

	if (sol > 1231231)
		sol = -1;
	cout << sol << '\n';
}