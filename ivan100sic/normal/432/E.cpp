#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<string> vs;
int n, m;

char get(vs& a, int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m)
		return 0;
	return a[i][j];
}

void fff(vs& a, int& x, int& y) {
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (!a[i][j]) {
				x = i;
				y = j;
				return;
			}
	x = y = -1;
}


char fban(vs& a, int x, int y, int u) {
	set<char> banned;
	for (int i=0; i<u; i++) {
		banned.insert(get(a, x-1, y+i));
		banned.insert(get(a, x+u, y+i));
		banned.insert(get(a, x+i, y-1));
		banned.insert(get(a, x+i, y+u));
	}
	char c = 'A';
	while (banned.count(c))
		c++;
	return c;
}

bool nadogradi(vs& a) {
	int x, y;
	fff(a, x, y);
	if (x == -1)
		return false;
	int w = min(n-x, m-y);
	for (int i=x; i<n; i++)
		for (int j=y; j<m; j++)
			if (a[i][j])
				w = min(w, max(i-x, j-y));

	cerr << "f " << x << ' ' << y << ' ' << w << '\n';

	vs best = a, nx = a;
	best[0][0] = 'Z';
	for (int u=1; u<=w; u++) {
		vs t = a;
		char c = fban(t, x, y, u);
		for (int i=0; i<u; i++)
			for (int j=0; j<u; j++)
				t[x+i][y+j] = c;
		vs t2 = t;
		// sad opet nadji slobodno
		{
			int i, j;
			fff(t, i, j);
			if (i != -1)
				t2[i][j] = fban(t, i, j, 1);
		}
		if (t2 < best) {
			best = t2;
			nx = t;
		}
	}
	a = nx;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;

	vs a(n, string(m, 0));
	while (nadogradi(a));
	for (int i=0; i<n; i++)
		cout << a[i] << '\n';
}