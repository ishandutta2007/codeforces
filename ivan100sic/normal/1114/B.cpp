#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, m;
int a[200005], b[200005], c[200005];

bool cmp(int x, int y) {
	return a[x] > a[y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	iota(b, b+n, 0);
	sort(b, b+n, cmp);
	ll w = 0;
	for (int i=0; i<m*k; i++) {
		c[b[i]] = 1;
		w += a[b[i]];
	}
	cout << w << '\n';
	int z = 0;
	for (int i=0; i<n; i++) {
		if (c[i]) {
			z++;
			if (z % m == 0 && z != m*k) {
				cout << i+1 << ' ';
			}
		}
	}
	cout << '\n';
}