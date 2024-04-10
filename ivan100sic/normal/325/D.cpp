#include <bits/stdc++.h>
using namespace std;

#define CH(x) {&(x), (x)}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;

int n, m;
pii par[3005][6005];
int sz[3005][6005];
int alive[3005][6005];

template<class T>
inline auto S(T& x, pii a) -> decltype(x[0][0])& {
	return x[a.first][a.second];
}

pii e(pii a) {
	while (a != S(par, a))
		a = S(par, a);
	return a;
}

basic_string<pair<int*, int>> changes;

void spoji(pii a, pii b) {
	a = e(a);
	b = e(b);
	if (a == b)
		return;
	if (S(sz, a) < S(sz, b))
		swap(a, b);

	changes += CH(S(par, b).first);
	changes += CH(S(par, b).second);
	changes += CH(S(sz, a));

	S(par, b) = a;
	S(sz, a) += S(sz, b);
}

void flag() {
	changes += pair<int*, int>(nullptr, 0);
}

void rollback() {
	while (1) {
		auto [x, y] = changes.back();
		changes.pop_back();
		if (!x) return;
		*x = y;
	}
}

void dodaj(int u, int v) {
	changes += CH(alive[u][v]);
	changes += CH(par[u][v].first);
	changes += CH(par[u][v].second);
	changes += CH(sz[u][v]);
	alive[u][v] = 1;
	par[u][v] = {u, v};
	sz[u][v] = 1;
	for (int x=-1; x<=1; x++)
		for (int y=-1; y<=1; y++) {
			if (x == 0 && y == 0)
				continue;
			int p = u+x;
			int q = v+y;
			if (p < 0 || p >= n)
				continue;
			q = (q+2*m) % (2*m);
			if (alive[p][q])
				spoji({u, v}, {p, q});
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t, z=0;
	cin >> n >> m >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		flag();
		dodaj(x, y);
		dodaj(x, y+m);
		if (e({x, y}) == e({x, y+m})) {
			rollback();
		} else {
			z++;
			changes.clear();
		}
	}
	cout << z << '\n';
}