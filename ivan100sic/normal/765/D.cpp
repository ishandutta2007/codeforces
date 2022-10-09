#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, m;
int f[100005], g[100005], h[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> f[i];
	}

	// proverimo da li moze
	for (int i=1; i<=n; i++) {
		if (f[i] != f[f[i]]) {
			cout << -1;
			return 0;
		}
	}

	for (int i=1; i<=n; i++) {
		if (f[i] == i) {
			g[i] = ++m;
			h[m] = i;
		}
	}

	for (int i=1; i<=n; i++) {
		if (f[i] != i) {
			g[i] = g[f[i]];
		}
	}

	cout << m << '\n';
	for (int i=1; i<=n; i++) {
		cout << g[i] << ' ';
	}
	cout << '\n';
	for (int i=1; i<=m; i++) {
		cout << h[i] << ' ';
	}

}