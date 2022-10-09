#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s[1005];
int l[1005], r[1005], sol = 123123123, x, y;
int p[1005], q[1005];

bool ima(int x, int y) {
	if (x >= n || y >= m)
		return false;
	return s[x][y] == 'X';
}

void probaj(int h, int w) {
	int x = ::x, y = ::y;
	memset(p, 0xff, sizeof(p));
	memset(q, 0xff, sizeof(q));

	int u = y, v = y+w-1;
	for (int i=0; i<h; i++) {
		p[x+i] = u;
	}

	while (1) {
		if (ima(x+h, y) && ima(x, y+w))
			return;
		if (ima(x+h, y)) {
			q[x] = v;
			u = y, v = y+w-1;
			p[x+h] = u; 
			x++;
		} else if (ima(x, y+w)) {
			v++;
			y++;
		} else {
			for (int i=0; i<h; i++) {
				q[x+i] = v;
			}
			break;
		}
	}

	if (equal(l, l+n, p) && equal(r, r+n, q)) {
		sol = min(sol, h*w);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;

	memset(l, 0xff, sizeof(l));
	memset(r, 0xff, sizeof(r));
	for (int i=0; i<n; i++) {
		cin >> s[i];
		int c = 0;
		for (int j=0; j<m; j++) {
			if (s[i][j] == 'X') {
				if (!c)
					l[i] = j;
				r[i] = j;
				c++;
			}
		}

		if (l[i] == -1)
			continue;

		if (c != r[i] - l[i] + 1) {
			cout << "-1\n";
			return 0;
		}
	}

	x = find_if(l, l+n, [](int x) { return x != -1; }) - l;
	y = l[x];

	int h = 0, w = 0;
	while (h+x < n && s[h+x][y] == 'X')
		h++;
	while (w+y < m && s[x][w+y] == 'X')
		w++;

	for (int i=1; i<=h; i++)
		probaj(i, w);
	for (int j=1; j<=w; j++)
		probaj(h, j);

	if (sol == 123123123)
		sol = -1;
	cout << sol << '\n';
}