#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct put {
	int id, v;
	ll w;
};

int n, m;
basic_string<put> e[100005];
ll d[100005];
int p[100005], pid[100005];
bool sp_ids[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x] += put{i, y, 1000001-z};
		e[y] += put{i, x, 1000001-z};
	}

	set<pair<ll, int>> pq;
	pq.insert({0, 1});
	memset(d, 63, sizeof(d));
	d[1] = 0;
	while (pq.size()) {
		auto [dx, x] = *pq.begin();
		pq.erase(pq.begin());
		for (auto [id, y, w] : e[x]) {
			if (d[y] > d[x] + w) {
				pq.erase({d[y], y});
				d[y] = d[x] + w;
				pq.insert({d[y], y});
				p[y] = x;
				pid[y] = id;
			}
		}
	}

	basic_string<put> sol;

	for (int x=n; x!=1; x=p[x])
		sp_ids[pid[x]] = 1;

	for (int x=1; x<=n; x++) {
		for (auto [id, y, w] : e[x]) {
			if (x > y)
				continue;
			if (sp_ids[id] ^ (w == 1000000)) {
				sol += {x, y, w - 1000000};
			}
		}
	}

	cout << sol.size() << '\n';
	for (auto [x, y, z] : sol)
		cout << x << ' ' << y << ' ' << z << '\n';
}