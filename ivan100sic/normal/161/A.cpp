#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[100005], x, y, n, m;
basic_string<pair<int, int>> sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> x >> y;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int p = 0, z = 0;
	for (int i=0; i<m; i++) {
		int b;
		cin >> b;
		while (p < n && b > a[p]+y)
			p++;
		if (p < n && a[p]-x <= b) {
			z++;
			sol += {p, i};
			p++;
		}
	}
	cout << z << '\n';
	for (auto [x, y] : sol)
		cout << x+1 << ' ' << y+1 << '\n';
}