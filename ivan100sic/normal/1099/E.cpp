#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct problem {
	int n, m;
	vector<string> a;
	vector<vector<int>> b, dp, pre;
	int transponovano;

	char kodiraj(char x) {
		switch (x) {
			case 'A': return 0;
			case 'C': return 1;
			case 'G': return 2;
			case 'T': return 3;
		}
		return -1;
	}

	char dekodiraj(char x) {
		switch (x) {
			case 0: return 'A';
			case 1: return 'C';
			case 2: return 'G';
			case 3: return 'T';
		}
		return -1;
	}

	void ucitaj() {
		cin >> n >> m;
		a.assign(n, "");
		for (int i=0; i<n; i++) {
			cin >> a[i];
			for (int j=0; j<m; j++) {
				a[i][j] = kodiraj(a[i][j]);
			}
		}
		transponovano = 0;
	}

	void transponuj() {
		vector<string> b(m, string(n, '.'));
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				b[j][i] = a[i][j];
		swap(n, m);
		swap(a, b);
		transponovano ^= 1;
	}

	void precompute() {
		b.assign(m, vector<int>(8, 0));
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				b[j][((i&1) << 2) + (int)a[i][j]]++;
	}

	int column_cost(int i, int x, int y) {
		return b[i][x] + b[i][4+y];
	}

	int __x, __y;

	void probaj(int x, int y) {
		__x = x;
		__y = y;
		int p = (x ^ y) % 3 + 1;
		int q = p % 3 + 1;

		dp.assign(m, vector<int>(4, -1123123123));
		pre.assign(m, vector<int>(4, 0));

		dp[0][x] = column_cost(0, x, y);

		for (int i=1; i<m; i++) {
			for (int j=0; j<4; j++) {
				int kand;

				kand = dp[i-1][j ^ p] + column_cost(i, j, j ^ x ^ y);
				if (kand > dp[i][j]) {
					dp[i][j] = kand;
					pre[i][j] = j ^ p;
				}

				kand = dp[i-1][j ^ q] + column_cost(i, j, j ^ x ^ y);
				if (kand > dp[i][j]) {
					dp[i][j] = kand;
					pre[i][j] = j ^ q;
				}
			}
		}
	}

	int cena() {
		if (dp.size() == 0)
			return -1;
		return *max_element(dp[m-1].begin(), dp[m-1].end());
	}

	void rekonstruisi() {
		int x = __x;
		int y = __y;
		int j = max_element(dp[m-1].begin(), dp[m-1].end()) - dp[m-1].begin();
		vector<int> h(m);
		for (int i=m-1; i>=0; j = pre[i][j], i--) {
			h[i] = j;
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int v = (i&1 ? x ^ y : 0) ^ h[j];
				a[i][j] = dekodiraj(v);
			}
		}
	}

	void stampaj() {
		for (int i=0; i<n; i++)
			cout << a[i] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	problem pr, best;
	pr.ucitaj();
	pr.precompute();

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (i == j)
				continue;
			auto tmp = pr;
			tmp.probaj(i, j);
			if (tmp.cena() > best.cena()) {
				best = tmp;
			}
		}
	}

	pr.transponuj();
	pr.precompute();

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (i == j)
				continue;
			auto tmp = pr;
			tmp.probaj(i, j);
			if (tmp.cena() > best.cena()) {
				best = tmp;
			}
		}
	}

	best.rekonstruisi();

	if (best.transponovano)
		best.transponuj();

	best.stampaj();
}