#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, root;
int p[100005], c[100005];
basic_string<int> e[100005], f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x, y;
		cin >> x >> y;
		if (x == -1) {
			root = i;
		} else {
			p[i] = x;
			e[x] += i;
		}
		c[i] = y;
	}

	for (int i=1; i<=n; i++) {
		if (i != root && c[i]) {
			bool ok = true;
			for (int y : e[i]) {
				ok &= c[y];
			}
			if (ok)
				f += i;
		}
	}

	if (f.size() == 0)
		f += -1;
	for (int x : f)
		cout << x << ' ';
	cout << '\n';

}