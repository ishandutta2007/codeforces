#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[200005], b[200005];
int c[200005], d[200005], e[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n+m; i++)
		cin >> a[i];
	int f=0, g=0;
	for (int i=0; i<n+m; i++) {
		int t;
		cin >> t;
		if (t == 0)
			c[f++] = a[i];
		else
			d[g++] = a[i];
	}
	for (int i=0; i<f; i++) {
		int k = lower_bound(d, d+g, c[i]) - d;
		int j = k - 1;
		bool first = false; // j ili k (j < k)
		if (j < 0) {
			first = false;
		} else if (k == g) {
			first = true;
		} else {
			first = abs(c[i] - d[j]) <= abs(c[i] - d[k]);
		}
		if (first)
			e[j]++;
		else
			e[k]++;
	}
	for (int i=0; i<g; i++)
		cout << e[i] << ' ';
	cout << '\n';
}