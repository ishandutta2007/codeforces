// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct blok {
	int x, y, id;
} a[100005];

vector<pair<int, int>> e[100005];
int sx, sy, fx, fy, n, m;
ll d[100005];

void ae(int x, int y, int w) {
	e[x].emplace_back(y, w);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> sx >> sy >> fx >> fy;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, y, i};

		ae(m, i, min(abs(sx-x), abs(sy-y)));
		ae(i, m+1, abs(fx-x) + abs(fy-y));
	}

	sort(a, a+m, [](auto x, auto y) { return x.x < y.x; });
	for (int i=0; i<m-1; i++) {
		ae(a[i].id, a[i+1].id, a[i+1].x - a[i].x);
		ae(a[i+1].id, a[i].id, a[i+1].x - a[i].x);
	}

	sort(a, a+m, [](auto x, auto y) { return x.y < y.y; });
	for (int i=0; i<m-1; i++) {
		ae(a[i].id, a[i+1].id, a[i+1].y - a[i].y);
		ae(a[i+1].id, a[i].id, a[i+1].y - a[i].y);
	}

	memset(d, 63, sizeof d);
	d[m] = 0;
	set<pair<ll, int>> pq;
	pq.insert({0, m});

	while (pq.size()) {
		auto [dx, x] = *pq.begin();
		pq.erase(pq.begin());
		for (auto [y, w] : e[x]) {
			if (d[y] > dx + w) {
				pq.erase({d[y], y});
				d[y] = dx + w;
				pq.insert({d[y], y});
			}
		}
	}

	cout << min((ll)abs(sx-fx) + abs(sy-fy), d[m+1]) << '\n';
}