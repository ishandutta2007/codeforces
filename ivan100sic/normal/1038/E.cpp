#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dsu {
	int p[4], s[4];

	dsu() { // najjadniji dsu ikad
		iota(p, p+4, 0);
		fill(s, s+4, 1);
	}

	int e(int x) {
		while (x != p[x])
			x = p[x];
		return x;
	}

	void merge(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return;
		p[x] = y;
		s[y] += s[x];
	}
};

bool is_edge_connected(int a, int b, int c, int d, int e, int f) {
	dsu s;
	if (a) s.merge(0, 1);
	if (b) s.merge(0, 2);
	if (c) s.merge(0, 3);
	if (d) s.merge(1, 2);
	if (e) s.merge(1, 3);
	if (f) s.merge(2, 3);

	int l = 0;
	for (int i=0; i<4; i++)
		if (i == s.e(i) && s.s[i] > 1)
			l++;

	return l <= 1;
}

bool is_valid(int a, int b, int c, int d, int e, int f) {
	int g[4];
	g[0] = a + b + c;
	g[1] = a + d + e;
	g[2] = b + d + f;
	g[3] = c + e + f;
	int sm2 = 0;
	for (int i=0; i<4; i++)
		sm2 += g[i] & 1;
	return is_edge_connected(a, b, c, d, e, f) && sm2 != 4;
}

int sm[4][4][3];
int self[4];
vector<int> val[4][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int x, v, y;
		cin >> x >> v >> y;
		x--, y--;
		if (x > y)
			swap(x, y);
		if (x != y)
			val[x][y].push_back(v);
		else
			self[x] += v;
	}

	for (int x=0; x<4; x++) {
		for (int y=x+1; y<4; y++) {
			sort(val[x][y].begin(), val[x][y].end());
			reverse(val[x][y].begin(), val[x][y].end());
			int zbir = 0;
			sm[x][y][1] = -123123123;
			sm[x][y][2] = -123213123;
			for (int k=0; k<(int)val[x][y].size(); k++) {
				zbir += val[x][y][k];
				sm[x][y][2 - (k+1)%2] = zbir;
			}
		}
	}

	int sol = 0;

	for (int a=0; a<=2; a++)
	for (int b=0; b<=2; b++)
	for (int c=0; c<=2; c++)
	for (int d=0; d<=2; d++)
	for (int e=0; e<=2; e++)
	for (int f=0; f<=2; f++) // yes, even GMs sometimes do this :(
	{
		if (is_valid(a, b, c, d, e, f)) {

			int v = 0;
			v += sm[0][1][a];
			v += sm[0][2][b];
			v += sm[0][3][c];
			v += sm[1][2][d];
			v += sm[1][3][e];
			v += sm[2][3][f];

			int uzo0 = sm[0][1][a] + sm[0][2][b] + sm[0][3][c];
			int uzo1 = sm[0][1][a] + sm[1][2][d] + sm[1][3][e];
			int uzo2 = sm[0][2][b] + sm[1][2][d] + sm[2][3][f];
			int uzo3 = sm[0][3][c] + sm[1][3][e] + sm[2][3][f];

			if (uzo0)
				v += self[0];
			if (uzo1)
				v += self[1];
			if (uzo2)
				v += self[2];
			if (uzo3)
				v += self[3];

			sol = max(sol, v);
		}
	}

	sol = max(sol, *max_element(self, self+4));

	cout << sol << '\n';
}