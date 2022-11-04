#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Pt {
	ld x, y;
};
bool operator<(Pt a, Pt b) {
	return a.y * b.x - a.x * b.y < 0;
}

const ld EPS = 1e-9;

void ProGamerMove() {
	int n; cin >> n;
	Pt cur; cin >> cur.x >> cur.y;
	vector<ld> x(n), y(n);
	for (ld& v : x) cin >> v;
	for (ld& v : y) cin >> v;
	multiset<Pt> dirs;
	ld totx = 0;
	auto clip = [&] (ld x) { return max(ld(0), min(ld(1), x)); };
	auto ins = [&] (ld i, ld j) {
		if (abs(i) <= EPS || abs(j) <= EPS) return;
		dirs.insert({i, j});
		totx += i;
	};
	auto check = [&] () {
		while (totx > cur.x + EPS) {
			if (dirs.empty()) return;
			auto [dx, dy] = *dirs.rbegin();
			dirs.erase(prev(dirs.end()));
			totx -= dx;
			if (totx <= cur.x) {
				ld t = clip((cur.x - totx) / dx);
				ins(t * dx, t * dy);
				break;
			}
		}
	};
	for (int i = 0; i < n; ++i) {
		while (1) {
			if (dirs.empty()) {
				ld t = clip(cur.y / y[i]);
				cur.x += t * x[i], cur.y -= t * y[i];
				ins((1 + t) * x[i], - (1 + t) * y[i]);
				break;
			}
			auto [dx, dy] = *dirs.begin();
			if (Pt{x[i], -y[i]} < Pt{dx, dy}) {
				ld t = clip(cur.y / y[i]);
				cur.x += t * x[i], cur.y -= t * y[i];
				ins((1 + t) * x[i], - (1 + t) * y[i]);
				break;
			} else {
				dirs.erase(dirs.begin());
				totx -= dx;
				cur.x -= dx, cur.y -= dy;
				if (cur.y - y[i] > EPS) {
					ld t = clip(- (cur.y - y[i]) / dy);
					cur.x += t * dx, cur.y += t * dy;
					cur.x += x[i], cur.y -= y[i];
					ins(t * dx, t * dy);
					ins(2 * x[i], - 2 * y[i]);
					break;
				} else continue;
			}
		}
		check();
		cout << cur.x << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc; cin >> tc;
	while (tc--) ProGamerMove();
}