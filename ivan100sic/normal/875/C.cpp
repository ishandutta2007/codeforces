#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> s[100005], e[100005], red;
basic_string<pair<int, int>> crit;
bool v[100005];
int n, m;

void no() {
	cout << "No\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int l;
		cin >> l;
		while (l--) {
			int x;
			cin >> x;
			s[i] += x;
		}
	}

	for (int i=0; i<n-1; i++) {
		size_t j = 0;
		while (j < s[i].size() && j < s[i+1].size()) {
			if (s[i][j] != s[i+1][j]) {
				int p = s[i][j];
				int q = s[i+1][j];
				crit += {p, q};
				if (p < q) {
					e[q] += p;
				} else {
					if (!v[p]) {
						v[p] = 1;
						red += p;
					}
				}
				break;
			} else {
				j++;
			}
		}

		if (j == s[i].size() || j == s[i+1].size()) {
			if (s[i].size() > s[i+1].size())
				no();
		}
	}

	size_t qs = 0;
	while (qs != red.size()) {
		int x = red[qs++];
		for (int y : e[x])
			if (!v[y]) {
				v[y] = 1;
				red += y;
			}
	}
	for (auto [x, y] : crit) {
		if (v[x])
			x -= 123123123;
		if (v[y])
			y -= 123123123;
		if (x > y)
			no();
	}

	cout << "Yes\n";
	cout << count(v+1, v+m+1, true) << '\n';
	for (int i=1; i<=m; i++)
		if (v[i])
			cout << i << ' ';
	cout << "\n";
}