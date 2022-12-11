#include <bits/stdc++.h>
using namespace std;

const int N = 2050;
int p[N], id[N], rmd[N], P[N], n;
int qry(vector<int> vec) {
	cout << "? " << vec.size() << ' ';
	for (auto t: vec) cout << t << ' ';
	cout << endl, fflush(stdout);
	int ok; cin >> ok; return ok;
}

int query(int x) {
	vector<int> vec;
	for (int i = 1;i <= n; ++i) if (!p[i] && x != i)
		vec.push_back(i);
	return qry(vec);
}

void query(int x, int y, int xx, int yy) {
	for (int i = 1;i <= n; ++i)
		if (!id[x] && !p[i] && rmd[i] == y) {
			if (query(i)) id[x] = i;
		} else if (!id[xx] && !p[i] && rmd[i] == yy) 
			if (query(i)) id[xx] = i;
	p[id[x]] = x, p[id[xx]] = xx;
}

int main() {
	cin >> n, query(1, 0, n, 0);
	for (int t = 2, l = 2, r = n - 1;l <= r; t <<= 1)  {
		for (int i = 1;i <= n; ++i) if (!p[i]) {
				vector<int> vec;
				for (int j = 1;j <= t; ++j)
					if (j % t != rmd[i]) vec.push_back(id[j]);
				vec.push_back(i);
				if (qry(vec)) rmd[i] += t >> 1;
			}
		while (l <= 2 * t && l <= r) query(l, l % t, r, r % t), ++l, --r;
	}
	if (p[1] * 2 > n) 
		for (int i = 1;i <= n; ++i) p[i] = n - p[i] + 1;
	cout << "! ";
	for (int i = 1;i <= n; ++i)
		cout << p[i] << ' ';
	cout << endl, fflush(stdout);
	return 0;
}