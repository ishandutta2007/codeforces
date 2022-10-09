#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int x[300005], y[300005];
int dx[300005], dy[300005];

const int BAD = 1012012012;

int trazi_x(int p, int x, int y) {
	if (x == y)
		return 1; // yxyxyx...

	if (k == 1) {
		if (p == 0)
			return x == y+1 ? 1 : BAD;
		else
			return BAD;
	}

	if (x < y) {
		// proveri da nisu prepakovani
		if (y > k*1ll*x)
			return BAD;
		return 1;
	} else {
		// uzmi dovoljno xova da ne budu prepakovani
		if (p+x <= y*1ll*k) {
			return 1;
		} else if (p+x > (y+1ll)*k) {
			return BAD;
		} else {
			return p+x - y*1ll*k;
		}
	}
}

int trazi_cross(int p, int x, int y) {
	if (k == 1) {
		if (p == 0)
			return x == y || x+1 == y ? 1 : BAD;
		else
			return x+1 == y ? 1 : BAD;
	}

	if (x == y) {
		if (p == k && x == 1)
			return BAD;
		return 1; // yx(xy)+ ili (xy)+
	}

	if (x > y) {
		// samo vidi da li pokrivam
		if (p + x <= k*1ll*y)
			return 1;
		return BAD;
	} else {
		if (y <= x*1ll*k)
			return 1;
		if (y > (x+1ll)*k)
			return BAD;
		return y - x*1ll*k;
	}
}

/*
yyy x yyy
xxx y xxx
y x
xx y x
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> x[i];
	for (int i=1; i<=n; i++)
		cin >> y[i];

	dx[0] = dy[0] = 0;

	for (int i=1; i<=n; i++) {
		dx[i] = dy[i] = BAD;
		if (dx[i-1] != BAD) {
			dx[i] = min(dx[i], trazi_x(dx[i-1], x[i], y[i]));
			dy[i] = min(dy[i], trazi_cross(dx[i-1], x[i], y[i]));
		}
		if (dy[i-1] != BAD) {
			dy[i] = min(dy[i], trazi_x(dy[i-1], y[i], x[i]));
			dx[i] = min(dx[i], trazi_cross(dy[i-1], y[i], x[i]));
		}

		// cerr << dx[i] << ' ' << dy[i] << '\n';
	}

	if (dx[n] != BAD || dy[n] != BAD)
		cout << "YES\n";
	else
		cout << "NO\n";
}