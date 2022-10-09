#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		c[u]++;
		c[v]++;
	}
	cout << count(c+1, c+n+1, 1) << '\n';
}