#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s[2005];
int d[2005][2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, x0, y0, x, y;

	cin >> n >> m;
	cin >> x0 >> y0;
	cin >> x >> y;
	s[0] = s[n+1] = string(m+2, '*');
	for (int i=1; i<=n; i++) {
		cin >> s[i];
		s[i] = string("*") + s[i] + '*';
	}

	memset(d, 63, sizeof(d));
	d[x0][y0] = 0;

	deque<pair<int, int>> dq;
	dq.push_front({x0, y0});

	while (dq.size()) {
		auto p = dq.front(); dq.pop_front();
		int x = p.first;
		int y = p.second;
		int dold = d[x][y];

		auto mv = [&](int x, int y, int dold, int penalty) {
			if (s[x][y] == '*')
				return;
			if (d[x][y] <= dold + penalty)
				return;

			d[x][y] = dold + penalty;
			if (penalty == 0)
				dq.push_front({x, y});
			else
				dq.push_back({x, y});
		};

		mv(x+1, y, dold, 0);
		mv(x-1, y, dold, 0);
		mv(x, y+1, dold, 0);
		mv(x, y-1, dold, 1);
	}

	int z = 0;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int rm = j - y0 + d[i][j];
			if (d[i][j] < 123123123 && d[i][j] <= x && rm <= y)
				z++;
		}
	}

	cout << z << '\n';

}