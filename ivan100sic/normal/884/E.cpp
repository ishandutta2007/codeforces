#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2][17000];
int b[2][17000];
int c[2][17000];
int brb;
int sol;
string s;

void to_row() {
	for (int i=1; i<=m; i++) {
		b[0][i] = b[1][i];
	}
	int c = 0;
	for (int i=0; i<m/4; i++) {
		int x = s[i] <= '9' ? s[i] - '0' : s[i] - 'A' + 10;
		for (int j=3; j>=0; j--) {
			c++;
			b[1][c] = (x >> j) & 1;
		}
	}

	/*
	for (int i=1; i<=m; i++) {
		cerr << b[1][i];
	}
	cerr << '\n';
	*/
}

struct dsu {
	int p[34000], sz[34000];

	void reset() {
		for (int i=0; i<34000; i++) {
			p[i] = i;
			sz[i] = 1;
		}
	}

	int endp(int x) {
		while (x != p[x]) {
			x = p[x];
		}
		return x;
	}

	bool same(int x, int y) {
		return endp(x) == endp(y);
	}

	void merge(int x, int y) {
		x = endp(x);
		y = endp(y);

		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		p[x] = y;
		sz[y] += sz[x];
	}
} ds;

int uq[34000];

void analiziraj() {
	int cl = brb;

	for (int i=1; i<=m; i++) {
		if (b[1][i] && !b[1][i-1]) {
			cl++;
			c[1][i] = cl;
			sol++;
		} else if (b[1][i] && b[1][i-1]) {
			c[1][i] = cl;
		} else {
			c[1][i] = 0;
		}
	}
	
	ds.reset();
	
	for (int i=1; i<=m; i++) {
		if (b[1][i] && b[0][i]) {
			// spoji ove dve ako vec nisu
			if (!ds.same(c[1][i], c[0][i])) {
				sol--;
				ds.merge(c[1][i], c[0][i]);
			}
		}
	}

	fill(uq, uq+34000, 0);
	brb = 0;
	for (int i=1; i<=m; i++) {
		if (b[1][i]) {
			int x = ds.endp(c[1][i]);
			if (!uq[x]) {
				uq[x] = ++brb;
			}
			c[0][i] = uq[x];
		} else {
			c[0][i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> s;
		to_row();
		analiziraj();
	}

	cout << sol;

}