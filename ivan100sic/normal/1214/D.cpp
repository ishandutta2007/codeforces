#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string a[1000005];

bool ok(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	if (a[x][y] == '#')
		return false;
	return true;
}

string r[1000005];

vector<pair<int, int>> put(int dx, int dy) {
	int x=n-1, y=m-1;
	vector<pair<int, int>> v;
	while (x || y) {
		v.emplace_back(x, y);
		if (ok(x-dx, y-dy) && r[x-dx][y-dy]) {
			x -= dx;
			y -= dy;
			continue;			
		}

		x -= dy;
		y -= dx;
	}

	v.emplace_back(0, 0);
	reverse(v.begin(), v.end());
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		r[i].resize(m, 0);
	}

	r[0][0] = 1;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			r[i][j] |= ok(i, j) && ((ok(i-1, j) && r[i-1][j]) || (ok(i, j-1) && r[i][j-1]));

	
	if (!r[n-1][m-1]) {
		cout << "0\n";
	} else {
		auto u = put(1, 0);
		auto v = put(0, 1);
		auto w = u;
		auto it = set_intersection(u.begin(), u.end(), v.begin(), v.end(), w.begin());
		// cerr << it - w.begin() << '\n';
		if (it != w.begin() + 2) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
}