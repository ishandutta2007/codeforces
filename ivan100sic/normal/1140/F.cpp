#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[300005], z[300005], sx[300005], sy[300005];
ll sumprod;

basic_string<pair<int*, int>> changes_int;
basic_string<pair<ll*, ll>> changes_ll;

int e(int x) {
	while (x != p[x])
		x = p[x];
	return x;
}

void spoji(int x, int y) {
	x = e(x);
	y = e(y);
	if (x == y)
		return;
	if (z[x] < z[y])
		swap(x, y);
	changes_int += {&p[y], p[y]};
	changes_int += {&z[x], z[x]};
	changes_int += {&sx[x], sx[x]};
	changes_int += {&sy[x], sy[x]};
	changes_ll += {&sumprod, sumprod};
	sumprod -= sx[x]*1ll*sy[x] + sx[y]*1ll*sy[y];
	p[y] = x;
	z[x] += z[y];
	sx[x] += sx[y];
	sy[x] += sy[y];
	sumprod += sx[x]*1ll*sy[x];
}

int neki_x[300005], neki_y[300005];

void dodaj_tacku(tuple<int, int, int> pt) {
	auto [x, y, id] = pt;

	// cerr << "dodajem " << x << ' ' << y << ' ' << id;
	// cerr << "   izgleda " << neki_x[x] << ' ' << neki_y[y] << '\n';

	if (neki_x[x] && neki_y[y]) {
		// spoji ih, ne dodajes nista
		spoji(neki_x[x], neki_y[y]);
	} else if (neki_x[x]) {
		// samo mu se ubaci kao novi y
		int root = e(neki_x[x]);
		changes_int += {&sy[root], sy[root]};
		changes_int += {&neki_y[y], neki_y[y]};
		changes_ll += {&sumprod, sumprod};
		sy[root] += 1;
		sumprod += sx[root];
		neki_y[y] = root;
	} else if (neki_y[y]) {
		// samo mu se ubaci kao novi x
		int root = e(neki_y[y]);
		changes_int += {&sx[root], sx[root]};
		changes_int += {&neki_x[x], neki_x[x]};
		changes_ll += {&sumprod, sumprod};
		sx[root] += 1;
		sumprod += sy[root];
		neki_x[x] = root;
	} else {
		// napravi novog
		changes_int += {&p[id], p[id]};
		changes_int += {&z[id], z[id]};
		changes_int += {&sx[id], sx[id]};
		changes_int += {&sy[id], sy[id]};
		changes_int += {&neki_x[x], neki_x[x]};
		changes_int += {&neki_y[y], neki_y[y]};
		changes_ll += {&sumprod, sumprod};
		p[id] = id;
		z[id] = 1;
		sx[id] = 1;
		sy[id] = 1;
		sumprod++;
		neki_x[x] = id;
		neki_y[y] = id;
	}
}

void flag() {
	changes_int += pair<int*, int>{nullptr, 0};
	changes_ll += pair<ll*, ll>{nullptr, 0};
}

void rollback() {
	while (changes_int.back().first) {
		*changes_int.back().first = changes_int.back().second;
		changes_int.pop_back();
	}
	changes_int.pop_back();

	while (changes_ll.back().first) {
		*changes_ll.back().first = changes_ll.back().second;
		changes_ll.pop_back();
	}
	changes_ll.pop_back();
}

int q;
map<pair<int, int>, int> life_begin;
ll ans[300005];

const int MAXN = 524288;
basic_string<tuple<int, int, int>> b[2*MAXN];

void add(int l, int r, tuple<int, int, int> p, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l)
		return;
	if (l <= xl && xr <= r) {
		b[x] += p;
		return;
	}
	int xm = (xl + xr) >> 1;
	add(l, r, p, 2*x, xl, xm);
	add(l, r, p, 2*x+1, xm+1, xr);
}

void solve(int l, int r, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l)
		return;
	flag();
	for (auto p : b[x]) {
		dodaj_tacku(p);
	}

	if (xl == xr) {
		ans[xl] = sumprod;
	} else {
		int xm = (xl+xr) >> 1;
		solve(l, r, 2*x, xl, xm);
		solve(l, r, 2*x+1, xm+1, xr);
	}

	rollback();
}

void minitest() {
	dodaj_tacku({1, 1, 1});
	dodaj_tacku({1, 2, 2});
	dodaj_tacku({2, 1, 3});
	cerr << "sumprod " << sumprod << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// minitest();
	// return 0;

	cin >> q;
	for (int i=1; i<=q; i++) {
		tuple<int, int, int> p;
		int x, y;
		cin >> x >> y;
		p = {x, y, i};
		auto it = life_begin.find({x, y});
		if (it != life_begin.end()) {
			add(it->second, i-1, p);
			life_begin.erase(it);			
		} else {
			life_begin[{x, y}] = i;
		}
	}

	for (auto [p, t] : life_begin) {
		add(t, q, {p.first, p.second, t});
	}

	solve(1, q);

	for (int i=1; i<=q; i++)
		cout << ans[i] << " \n"[i == q];
}