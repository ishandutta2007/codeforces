#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[200005];

bool sa[200005], bez[200005];

void dfs1(int x, int p) {
	bool lose = false;
	int bravo = -1;
	int csa=0, cbez=0;

	for (int y : e[x]) {
		if (y != p) {
			dfs1(y, x);
			if (!sa[y] && !bez[y]) {
				lose = true;
			} else if (sa[y] && bez[y]) {
				bravo = y;
			} else if (sa[y]) {
				csa++;
			} else {
				cbez++;
			}
		}
	}

	if (lose) {
		sa[x] = bez[x] = false;
		return;
	}

	if (bravo == -1) {
		if (cbez % 2) {
			sa[x] = true;
			bez[x] = false;
		} else {
			sa[x] = false;
			bez[x] = true;
		}
	} else {
		sa[x] = bez[x] = true;
	}
}

void dfs2(int x, int p, bool gore) {
	basic_string<int> lsa, lbez, lbravo;

	for (int y : e[x]) {
		if (y != p) {
			if (!sa[y] && !bez[y]) {
				//
			} else if (sa[y] && bez[y]) {
				lbravo += y;
			} else if (sa[y]) {
				lsa += y;
			} else {
				lbez += y;
			}
		}
	}

	for (int y : lsa) {
		dfs2(y, x, true);
	}

	while (gore ^ ((lbez.size() + lbravo.size()) % 2 == 1)) {
		dfs2(lbravo.back(), x, true);
		lbravo.pop_back();
	}

	cout << x << '\n';

	for (int y : lbravo)
		dfs2(y, x, false);
	for (int y : lbez)
		dfs2(y, x, false);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (x) {
			e[i] += x;
			e[x] += i;
		}
	}

	dfs1(1, 1);

	if (!bez[1]) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	dfs2(1, 1, false);
}