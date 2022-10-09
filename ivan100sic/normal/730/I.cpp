#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct skil {
	int x, y, id;
	bool operator< (const skil& b) const {
		return y-x < b.y-b.x;
	}
};

int n, p, s;
skil a[3005];

int d[3005][3005], q[3005][3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> p >> s;
	for (int i=0; i<n; i++)
		cin >> a[i].x;
	for (int i=0; i<n; i++)
		cin >> a[i].y, a[i].id = i+1;

	memset(d, 192, sizeof d);
	d[0][0] = 0;

	sort(a, a+n);
	for (int i=0; i<n; i++) {
		auto [x, y, _] = a[i];

		for (int j=0; j<=p+s; j++)
			d[i+1][j] = d[i][j], q[i+1][j] = 0;

		for (int j=0; j<p+s; j++) {
			int z = j < p ? x : y;
			int t = j < p ? 1 : 2;
			if (d[i+1][j+1] < d[i][j] + z) {
				d[i+1][j+1] = d[i][j] + z;
				q[i+1][j+1] = t;
			}
		}
	}

	cout << d[n][p+s] << '\n';
	basic_string<int> u, v;
	int j = p + s;
	for (int i=n; i>=1; i--) {
		if (q[i][j] == 1)
			u += a[i-1].id, j--;
		else if (q[i][j] == 2)
			v += a[i-1].id, j--;
	}
	for (int x : u)
		cout << x << ' ';
	cout << '\n';
	for (int x : v)
		cout << x << ' ';
	cout << '\n';
}