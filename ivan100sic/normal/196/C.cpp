#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	int id;

	bool operator< (const pt& b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

int n;
pt a[1505];
basic_string<int> e[1505];
int sol[1505], sz[1505];

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y
		 - a.y*b.x - b.y*c.x - c.y*a.x;
}

bool cmp(pt a, pt b) {
	return det({0, 0}, a, b) < 0; // ili vece?
}

void dfs(int x, int p) {
	sz[x]++;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
		sz[x] += sz[y];
	}
}

void nadji(int tx, int tp, pt r, basic_string<pt> a) {
	for (pt& p : a) {
		p.x -= r.x;
		p.y -= r.y;
	}
	sort(a.begin(), a.end(), cmp);
	int lb = 0;
	sol[r.id] = tx;
	for (int ty : e[tx]) {
		if (ty == tp)
			continue;
		basic_string<pt> parce(a.begin() + lb, a.begin() + lb + sz[ty]);
		lb += sz[ty];
		nadji(ty, tx, parce[0], parce.substr(1));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	for (int i=1; i<=n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	dfs(1, 1);
	for (int i=2; i<=n; i++)
		if (a[i] < a[1])
			swap(a[1], a[i]);
	nadji(1, 1, a[1], basic_string<pt>(a+2, a+n+1));
	for (int i=1; i<=n; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}