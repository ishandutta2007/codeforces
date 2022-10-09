#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAXN = 2048;
const ll INF = 1e18;
mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

struct problem {
	int n, m, k, p;
	vector<int> ri, cj;
	shared_ptr<vector<vector<int>>> a;
};

problem read_problem() {
	problem pl;
	cin >> pl.n >> pl.m >> pl.k >> pl.p;
	pl.ri.resize(pl.n);
	pl.cj.resize(pl.m);
	for (int i=0; i<pl.n; i++) {
		for (int j=0; j<pl.m; j++) {
			int x;
			cin >> x;
			pl.ri[i] += x;
			pl.cj[j] += x;
		}
	}
	return pl;
}

struct solver_segtree {
	struct node {
		ll x;
		int id;
	};

	node max(node a, node b) {
		return a.x < b.x ? b : a;
	}

	ll c[2*MAXN];
	node b[2*MAXN];

	void push(int x) {
		if (c[x] == 0)
			return;
		if (x < MAXN) {
			c[2*x] += c[x];
			c[2*x+1] += c[x];
		}
		b[x].x += c[x];
		c[x] = 0;
	}

	void update(int l, int r, int v, int x=1, int xl=0, int xr=MAXN-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			c[x] += v;
			push(x);
			return;
		}
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		b[x] = max(b[2*x], b[2*x+1]);
	}

	ll solve(problem pl) {
		for (int i=0; i<MAXN; i++)
			b[i + MAXN] = {-INF, -1};
		for (int i=0; i<pl.n; i++)
			b[i + MAXN] = {pl.ri[i], i};
		for (int j=0; j<pl.m; j++)
			b[j + 1024 + MAXN] = {pl.cj[j], j + 1024};

		for (int i=MAXN-1; i>=1; i--) {
			b[i] = max(b[2*i], b[2*i+1]);
		}

		ll z = 0;
		for (int i=0; i<pl.k; i++) {
			push(1);
			auto [zad, j] = b[1];
			z += zad;
			if (j < 1024) {
				update(j, j, -pl.m*pl.p);
				update(1024, 2047, -pl.p);
			} else {
				update(j, j, -pl.n*pl.p);
				update(0, 1023, -pl.p);
			}
		}
		return z;
	}
};

struct solver_backtrack {
	ll solve(problem pl) {
		if (pl.k == 0)
			return 0;
		ll sol = -INF;

		for (int i=0; i<pl.n; i++) {
			ll z = pl.ri[i];
			problem pcp = pl;
			pcp.ri[i] -= pl.m*pl.p;
			pcp.k--;
			for (int j=0; j<pl.m; j++)
				pcp.cj[j] -= pl.p;
			sol = max(sol, solve(pcp) + z);
		}

		for (int j=0; j<pl.m; j++) {
			ll z = pl.cj[j];
			problem pcp = pl;
			pcp.cj[j] -= pl.n*pl.p;
			pcp.k--;
			for (int i=0; i<pl.n; i++)
				pcp.ri[i] -= pl.p;
			sol = max(sol, solve(pcp) + z);
		}

		return sol;
	}
};

struct solver_trial {
	basic_string<ll> get_vals(vector<int> a, int decr, int k) {
		basic_string<ll> z = {0};
		multiset<ll> ms;
		for (int x : a)
			ms.insert(x);
		for (int i=0; i<k; i++) {
			auto it = prev(ms.end());
			ll w = *it;
			z += z.back() + w;
			ms.erase(it);
			ms.insert(w - decr);
		}
		return z;
	}

	ll solve(problem p) {
		auto vr = get_vals(p.ri, p.m*p.p, p.k);
		auto vc = get_vals(p.cj, p.n*p.p, p.k);
		ll sol = -INF;
		for (int i=0; i<=p.k; i++)
			sol = max(sol, vr[i] + vc[p.k-i] - 1ll*i*(p.k-i)*p.p);
		return sol;
	}
};

problem generate_problem() {
	problem pl;
	pl.n = 2;
	pl.m = 3;
	pl.k = 4;
	pl.p = 6;
	pl.ri.resize(pl.n);
	pl.cj.resize(pl.m);
	pl.a = make_shared<vector<vector<int>>>(pl.n, vector<int>(pl.m, 0));
	for (int i=0; i<pl.n; i++)
		for (int j=0; j<pl.m; j++) {
			int x = uniform_int_distribution<int>(1, 10)(eng);
			pl.ri[i] += x;
			pl.cj[j] += x;
			(*pl.a)[i][j] = x;
		}
	return pl;
}

void print_problem(problem p) {
	cerr << p.n << ' ' << p.m << ' ' << p.k << ' ' << p.p << '\n';
	for (int i=0; i<p.n; i++)
		for (int j=0; j<p.m; j++)
			cerr << (*p.a)[i][j] << " \n"[j == p.m-1];
}

void stress() {
	while (1) {
		auto prob = generate_problem();
		ll sol = solver_backtrack().solve(prob);
		ll out = solver_trial().solve(prob);
		if (sol != out) {
			cerr << "Failed, expected=" << sol << " found=" << out << '\n';
			print_problem(prob);
			return;
		} else {
			cerr << "OK\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	problem prob = read_problem();
	// cerr << solver_backtrack().solve(prob) << '\n';
	cout << solver_trial().solve(prob) << '\n';

	// stress();
}