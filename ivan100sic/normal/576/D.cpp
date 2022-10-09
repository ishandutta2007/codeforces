#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int h = 150;

struct matrix {
	bitset<h> a[h];

	bitset<h>& operator[] (int x) { return a[x]; }
	const bitset<h>& operator[] (int x) const { return a[x]; }

	void transpose() {
		for (int i=0; i<h; i++)
			for (int j=i+1; j<h; j++) {
				int x = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = x;
			}
	}

	matrix operator* (matrix b) const {
		matrix tmp;
		b.transpose();
		for (int i=0; i<h; i++)
			for (int j=0; j<h; j++)
				tmp[i][j] = (a[i] & b[j]).any();
		return tmp;
	}

	static matrix diag() {
		matrix a;
		for (int i=0; i<h; i++)
			a[i][i] = 1;
		return a;
	}

	matrix operator^ (int x) {
		if (x == 0)
			return diag();
		matrix t = *this ^ (x >> 1);
		t = t * t;
		if (x & 1)
			t = t * *this;
		return t;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<int, vector<pair<int, int>>> mp;
	int n, m, has0 = 0;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		if (z == 0)
			has0 = 1;
		mp[z].emplace_back(x, y);
	}

	if (!has0) {
		cout << "Impossible\n";
		return 0;
	}

	matrix a = matrix::diag(), ea;
	vector<basic_string<int>> e(n);
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		for (auto [x, y] : it->second)
			e[x] += y, ea[x][y] = 1;
		basic_string<int> q;
		vector<int> d(n, -1);
		for (int i=0; i<n; i++)
			if (a[0][i])
				q += i, d[i] = 0;
		size_t qs = 0;
		while (qs != q.size()) {
			int x = q[qs++];
			for (int y : e[x])
				if (d[y] == -1)
					d[y] = d[x] + 1, q += y;
		}
		if (next(it) == mp.end()) {
			if (d[n-1] != -1)
				cout << it->first + d[n-1] << '\n';
			else
				cout << "Impossible\n";
			return 0;
		} else {
			if (d[n-1] != -1 && d[n-1] <= next(it)->first - it->first) {
				cout << it->first + d[n-1] << '\n';
				return 0;
			} else {
				a = a * (ea ^ (next(it)->first - it->first));
			}
		}
	}

}