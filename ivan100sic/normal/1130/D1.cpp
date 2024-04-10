#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> b[5005];
int nearest[5005];

int dist(int x, int y) {
	if (y >= x)
		return y-x;
	else
		return y-x+n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		b[x] += y;
	}

	for (int i=1; i<=n; i++) {
		int z = 123123123;
		for (int x : b[i]) {
			z = min(z, dist(i, x));
		}
		nearest[i] = z;
	}

	for (int i=1; i<=n; i++) {
		int z = 0;
		for (int j=1; j<=n; j++) {
			int s = b[j].size();
			if (!s)
				continue;
			z = max(z, dist(i, j) + (s-1)*n + nearest[j]);
		}
		cout << z << " \n"[i == n];
	}

}