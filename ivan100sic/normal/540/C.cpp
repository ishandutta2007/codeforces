#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int r1, c1, r2, c2;
string s[505];
int d[505][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];
	cin >> r1 >> c1 >> r2 >> c2;

	r1--, c1--, r2--, c2--;

	queue<pair<int, int>> q;
	q.push({r1, c1});
	memset(d, 255, sizeof(d));
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		auto go = [&](int i, int j) {
			if (i < 0 || j < 0 || i >= n || j >= m)
				return;
			if (d[i][j] != -1)
				return;
			if (s[i][j] == 'X') {
				d[i][j] = 444444444;
				return;
			}
			q.push({i, j});
			d[i][j] = d[x][y] + 1;
		};

		go(x+1, y);
		go(x-1, y);
		go(x, y+1);
		go(x, y-1);
	}

	int susdot = 0;
	auto sus = [&](int i, int j) {
		if (i < 0 || j < 0 || i >= n || j >= m)
			return;
		if (s[i][j] == 'X') {
			if (i == r1 && j == c1)
				susdot++;
			else;
		} else
			susdot++;
	};

	sus(r2+1, c2);
	sus(r2-1, c2);
	sus(r2, c2+1);
	sus(r2, c2-1);

	if (d[r2][c2] != -1 && (susdot >= 2 || d[r2][c2] == 444444444))
		cout << "YES\n";
	else
		cout << "NO\n";
}