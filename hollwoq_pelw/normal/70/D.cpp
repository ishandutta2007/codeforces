#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

template <class T>
struct point_t {
	T x, y;
	point_t (T _x = 0, T _y = 0)
		: x(_x), y(_y) {}

#define defop(type, op, otype) \
	friend inline type operator op (type a, const otype &b) { return a op##= b; } \
	type& operator op##= (const otype &oth)

	defop(point_t, +, point_t) { return *this = point_t(x + oth.x, y + oth.y); }
	defop(point_t, -, point_t) { return *this = point_t(x - oth.x, y - oth.y); }
	defop(point_t, *, T) { return *this = point_t(x * oth, y * oth); }
	defop(point_t, /, T) { return *this = point_t(x / oth, y / oth); }

#undef defop

	inline const T sqlen() const { return x * x + y * y; }
	inline friend T sqdist(const point_t &a, const point_t &b) { return (a - b).sqlen(); }
	inline const double len() const { return sqrt(sqlen()); }
	inline friend double dist(const point_t &a, const point_t &b) { return (a - b).dist(); }

	// > 0 (same dir), == 0 (perp), < 0 (diff dir)
	inline friend T  dot (const point_t &a, const point_t &b) { return a.x * b.x + a.y * b.y; }
	inline friend T cross(const point_t &a, const point_t &b) { return a.x * b.y - b.x * a.y; }
	// > 0 (ccw), < 0 (cw), == 0 (colinear)
	inline friend T ccw(const point_t &origin, const point_t &lhs, const point_t &rhs) {
		return cross(lhs - origin, rhs - origin);
	}
	// rotate 90 deg
	inline const point_t& perp() const { return point_t(- y, x); }

#define compare(op) friend bool operator op \
(const point_t& lhs, const point_t& rhs) { return pair(lhs.x, lhs.y) op pair(rhs.x, rhs.y); }
	compare(==) compare(!=) compare(<) compare(<=) compare(>) compare(>=)
#undef compare
};

struct hull_t {
	const long long inf = 1e9;
	using PT = point_t<long long>;
	
	set<PT> st;

	inline void add(const PT &p) {
		if (query(p)) return ;

		st.insert(p);

		auto it = st.find(p);
		
		while (next(it) != st.end() && next(it) -> x == p.x) st.erase(next(it));
		while (next(it) != st.end() && next(next(it)) != st.end()
			&& ccw(*it, *next(it), *next(next(it))) >= 0) st.erase(next(it));

		while (it != st.begin() && prev(it) -> x == p.x) st.erase(prev(it));
		while (it != st.begin() && prev(it) != st.begin()
			&& ccw(*prev(prev(it)), *prev(it), *it) >= 0) st.erase(prev(it));
	}

	inline bool query(const PT &p) {
		if (st.empty()) return 0;
		if (st. begin() -> x > p.x) return 0;
		if (st.rbegin() -> x < p.x) return 0;

		auto it = st.lower_bound(point_t(p.x, -inf));

		if (it -> x == p.x)
			return p.y <= it -> y;
		return ccw(p, *prev(it), *it) <= 0;
	}

	inline void add(int x, int y) { add(PT(x, y)); }
	inline bool query(int x, int y) { return query(PT(x, y)); }
} uhull, lhull;

void Hollwo_Pelw(){
	int q; cin >> q;

	for (int t, x, y; q --; ) {
		cin >> t >> x >> y;
		if (t == 1) {
			uhull.add(+x, +y), lhull.add(-x, -y);
		} else {
			cout << (uhull.query(+x, +y) && lhull.query(-x, -y) ? "YES\n" : "NO\n");
		}
	}
}