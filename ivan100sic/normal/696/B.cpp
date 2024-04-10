#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[100005];
int p[100005], sz[100005];
ld sol[100005];

void dfs1(int x) {
	sz[x] = 1;
	for (int y : e[x]) {
		dfs1(y);
		sz[x] += sz[y];
	}
}

void dfs2(int x, ld above) {
	above += 1;
	sol[x] = above;
	for (int y : e[x]) {
		dfs2(y, above + ld(sz[x] - 1 - sz[y]) / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++) {
		cin >> p[i];
		e[p[i]] += i;
	}

	dfs1(1);
	dfs2(1, 0);

	cout.precision(8);
	cout << fixed;
	for (int i=1; i<=n; i++)
		cout << sol[i] << " \n"[i == n];
}