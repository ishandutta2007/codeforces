#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int, int> a[88];
int n, m;
int d[88][100005];

void mn(int& x, int y) {
	x = min(x, y);
}

void rb(int j) {
	for (int i=m; i>=0; i--)
		mn(d[j][i], d[j][i+1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a+n);
	memset(d, 63, sizeof d);
	d[0][0] = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<=m; j++) {
			int l = a[i].first - a[i].second - j;
			int r = a[i].first + a[i].second + j;
			mn(d[i+1][min(r, m)], j + d[i][max(0, l-1)]);
			mn(d[i+1][j], d[i][j]);
		}
		rb(i+1);
	}

	cout << d[n][m] << '\n';
}