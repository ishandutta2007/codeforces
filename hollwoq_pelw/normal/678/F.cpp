/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

#define vl_t int64_t 
// #define vl_t long double

bool queryhull = 0;
struct line {
	// y = a * x + b;
	mutable vl_t a, b, p;
	bool operator < (const line &oth) const {
		return queryhull ? p < oth.p : a < oth.a;
	}
};


struct LineContainer : multiset<line> {
	static const vl_t inf = LLONG_MAX; 
	// static const vl_t inf = 8e18;
	vl_t div(vl_t a, vl_t b){
		return a / b - ((a ^ b) < 0 && a % b);
		// return a / b;
	}
	bool isect(iterator x, iterator y){
		if (y == end())
			return x->p = inf, 0;
		if (x->a == y->a)
			x->p = x->b > y->b ? inf : -inf;
		else
			x->p = div(y->b - x->b, x->a - y->a);
		return x->p >= y->p;
	}
	void add(vl_t a, vl_t b){
		auto z = insert({a, b, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y))
			isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	vl_t query(vl_t x) {
		if (empty()) return -inf;
		queryhull = 1;
		auto l = lower_bound({0, 0, x});
		queryhull = 0;
		return l->a * x + l->b;
	}
};

#undef vl_t

const int N = 3e5 + 5;
const int64_t inf = LLONG_MAX;

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int n, t[N], x[N], y[N];
LineContainer st[N << 2];

void update(int l, int r, int a, int b, int id = 1, int tl = 1, int tr = n) {
	if (tl > r || l > tr) return ;
	if (l <= tl && tr <= r) return st[id].add(a, b);
	int tm = tl + tr >> 1;
	update(l, r, a, b, left), update(l, r, a, b, right);
}

int64_t query(int p, int v, int id =  1, int tl = 1, int tr = n) {
	int64_t res = st[id].query(v);
	if (tl != tr) {
		int tm = tl + tr >> 1;
		res = max(res, p > tm ? query(p, v, right) : query(p, v, left));
	}
	return res;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		if (t[i] == 1) {
			cin >> x[i] >> y[i];
		}
		if (t[i] == 2) {
			cin >> x[i];
			update(x[i], i, x[x[i]], y[x[i]]);
			x[x[i]] = y[x[i]] = -2e9;
		}
		if (t[i] == 3) {
			cin >> x[i];
		}
	}
	for (int i = 1; i <= n; i++)
		if (t[i] == 1 && x[i] != -2e9)
			update(i, n, x[i], y[i]);
	for (int i = 1; i <= n; i++)
		if (t[i] == 3) {
			int64_t res = query(i, x[i]);
			if (res == -inf)
				cout << "EMPTY SET\n";
			else
				cout << res << '\n';
		}
}