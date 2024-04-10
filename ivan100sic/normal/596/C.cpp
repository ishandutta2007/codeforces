#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> d[200005], a[200005];
int x[100005], y[100005], w[100005];
int hy[100005], hx;

int aget(int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	if (y >= (int)a[x].size())
		return 0;
	return a[x][y];
}

void no() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> x[i] >> y[i];
	for (int i=1; i<=n; i++) {
		cin >> w[i];
		d[w[i] + n] += i;
	}

	for (int i=0; i<=2*n; i++)
		reverse(d[i].begin(), d[i].end());

	for (int i=1; i<=n; i++) {
		hy[x[i]] = max(hy[x[i]], y[i]);
		hx = max(hx, x[i]);
	}

	for (int i=0; i<=hx; i++)
		a[i].resize(hy[i] + 1);

	for (int i=0; i<=hx; i++) {
		for (int j=0; j<=hy[i]; j++) {
			if (!d[j-i+n].size())
				no();
			a[i][j] = d[j-i+n].back();
			d[j-i+n].pop_back();
			if (a[i][j] < aget(i, j-1))
				no();
			if (a[i][j] < aget(i-1, j))
				no();
			x[a[i][j]] = i;
			y[a[i][j]] = j;
		}
	}

	cout << "YES\n";
	for (int i=1; i<=n; i++)
		cout << x[i] << ' ' << y[i] << '\n';
}