#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, z, c[1005], a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> m;
	fill(c, c+n, 123123123);
	for (int i=0; i<m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		c[y] = min(c[y], w);
	}
	if (count(c, c+n, 123123123) > 1) 
		z = -1;
	else
		z = accumulate(c, c+n, -123123123);
	cout << z << '\n';
}