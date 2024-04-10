// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct upit {
	ld ang;
	int idx;
};

const ld g = 9.8;
int n;
ld v;
upit u[10005];
pair<ld, ld> ans[10005];

int m;
struct wall { ld x, y; } w[100005];

ld yhit(ld ang, ld x) {
	ld t = x / (v * cos(ang));
	return v * sin(ang)*t - g*t*t/2;
}

bool flyover(ld ang, ld x, ld y) {
	return yhit(ang, x) > y;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cout << setprecision(8) << fixed;

	cin >> n >> v;
	for (int i=0; i<n; i++) {
		ld a;
		cin >> a;
		u[i] = {a, i};
	}

	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> w[i].x >> w[i].y;
	}

	sort(w, w+m, [](auto u, auto v) { return u.x < v.x; });

	sort(u, u+n, [](auto u, auto v) { return u.ang < v.ang; });
	int h = 0;

	for (int i=0; i<n; i++) {
		while (h < m && flyover(u[i].ang, w[h].x, w[h].y)) {
			h++;
		}

		if (h == m || !flyover(u[i].ang, w[h].x, 0)) {
			// patos
			ld al = u[i].ang;
			ld cx = v*v*sin(2*al)/g;
			ans[u[i].idx] = {cx, 0};
		} else {
			ans[u[i].idx] = {w[h].x, yhit(u[i].ang, w[h].x)};
		}
	}

	for (int i=0; i<n; i++) {
		auto [x, y] = ans[i];
		cout << x << ' ' << y << '\n';
	}
}