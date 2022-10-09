#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> b[100005], r[100005], movs, cl0, cl1;
int sol = 123123123;
int cl[100005];
bool failed;

void dfs(int x, int c) {
	if (cl[x] != -1) {
		if (cl[x] != c) {
			failed = true;
		}
		return;
	}

	cl[x] = c;
	(c ? cl1 : cl0) += x;
	for (int y : b[x])
		dfs(y, c);
	for (int y : r[x])
		dfs(y, c^1);
}

void resi() {
	// postavi sve na B
	fill(cl+1, cl+n+1, -1);
	basic_string<int> sve0, sve1;
	for (int i=1; i<=n; i++) {
		if (cl[i] == -1) {
			failed = false;
			cl0 = {};
			cl1 = {};
			dfs(i, 0);
			if (failed)
				return;
			if (cl0.size() > cl1.size())
				swap(cl0, cl1);
			sve0 += cl0;
			sve1 += cl0;
		}
	}

	if (!failed) {
		if ((int)sve0.size() < sol) {
			sol = sve0.size();
			movs = sve0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		if (c == 'B') {
			b[x] += y;
			b[y] += x;
		} else {
			r[x] += y;
			r[y] += x;
		}
	}

	resi();

	for (int i=1; i<=n; i++) {
		swap(b[i], r[i]);
	}

	resi();

	if (sol == 123123123)
		sol = -1;

	cout << sol << '\n';
	for (int x : movs)
		cout << x << ' ';
	cout << '\n';
}