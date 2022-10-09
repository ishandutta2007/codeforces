#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[105], b[105], c[105];
basic_string<int> e[105];

void dfs(int x, int t) {
	c[x] = t;
	for (int y : e[x]) {
		if (!c[y]) {
			dfs(y, 3-t);
		} else if (c[y] == t) {
			cout << "Impossible\n";
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++)
		cin >> a[i] >> b[i];

	for (int i=0; i<m; i++) {
		for (int j=i+1; j<m; j++) {
			set<int> s = {a[i], a[j], b[i], b[j]};
			if (s.size() < 4)
				continue;
			int k = 1, x = 0;
			for (int t : s) {
				if (t == a[i] || t == b[i])
					x += k;
				k <<= 1;
			}
			if (x == 5 || x == 10) {
				e[i] += j;
				e[j] += i;
			}
		}
	}

	for (int i=0; i<m; i++) {
		if (!c[i]) {
			dfs(i, 1);
		}
		cout << (c[i] == 1 ? 'i' : 'o');
	}
	cout << '\n';
}