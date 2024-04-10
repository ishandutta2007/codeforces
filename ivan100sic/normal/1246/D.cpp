#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int p[100005];
set<int> e[100005];
int d[100005];

void dfs1(int x) {
	for (int y : e[x]) {
		d[y] = d[x] + 1;
		dfs1(y);
	}
}

void dfs2(int x) {
	cout << x << ' ';
	for (int y : e[x]) {
		dfs2(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> p[i];
		e[p[i]].insert(i);
	}

	dfs1(0);
	int r = max_element(d, d+n) - d;
	basic_string<int> op;
	while (r) {
		if (e[p[r]].size() == 1) {
			r = p[r];
			continue;
		}
		auto it = e[p[r]].begin();
		while (*it == r)
			++it;
		int y = *it;
		e[p[r]].erase(r);
		op += r;
		p[r] = y;
		e[y].insert(r);
	}

	dfs2(0);
	cout << '\n';
	reverse(op.begin(), op.end());
	cout << op.size() << '\n';
	for (int x : op)
		cout << x << ' ';
	cout << '\n';
}