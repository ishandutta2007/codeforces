#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, s;
int c[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		c[u]++;
		c[v]++;
	}
	cout << setprecision(20) << fixed << s * 2.0 / count(c+1, c+n+1, 1) << '\n';
}