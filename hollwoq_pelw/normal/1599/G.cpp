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
struct point_2d {
	T x, y;
	point_2d (T _x = 0, T _y = 0)
		: x(_x), y(_y) {}

#define defop(type, op, otype) \
	friend inline type operator op (type a, const otype &b) { return a op##= b; } \
	type& operator op##= (const otype &oth)

	inline const point_2d perp() const { return point_2d(- y, x); }
	inline const point_2d operator - () const { return point_2d(-x, -y); }
	inline const point_2d operator + () const { return point_2d(+x, +y); }
	
	defop(point_2d, +, point_2d) { return *this = point_2d(x + oth.x, y + oth.y); }
	defop(point_2d, -, point_2d) { return *this = point_2d(x - oth.x, y - oth.y); }
	defop(point_2d, *, T) { return *this = point_2d(x * oth, y * oth); }
	defop(point_2d, /, T) { return *this = point_2d(x / oth, y / oth); }

#undef defop

	inline const T sqlen() const { return x * x + y * y; }
	inline friend T sqdist(const point_2d &a, const point_2d &b) { return (a - b).sqlen(); }
	inline const long double len() const { return sqrt(sqlen()); }
	inline friend long double dist(const point_2d &a, const point_2d &b) { return (a - b).len(); }

	// > 0 (same dir), == 0 (perp), < 0 (diff dir)
	inline friend T  dot (const point_2d &a, const point_2d &b) { return a.x * b.x + a.y * b.y; }
	inline friend T cross(const point_2d &a, const point_2d &b) { return a.x * b.y - a.y * b.x; }
	// > 0 (ccw), < 0 (cw), == 0 (colinear)
	inline friend T ccw(const point_2d &origin, const point_2d &lhs, const point_2d &rhs) {
		return cross(lhs - origin, rhs - origin);
	}

#define compare(op) friend bool operator op \
(const point_2d& lhs, const point_2d& rhs) { return pair(lhs.x, lhs.y) op pair(rhs.x, rhs.y); }
	compare(==) compare(!=) compare(<) compare(<=) compare(>) compare(>=)
#undef compare

	friend std::ostream& operator << (std::ostream& out, const point_2d& p) { return out << p.x << ' ' << p.y; }
	friend std::istream& operator >> (std::istream& inp, point_2d& p) { return inp >> p.x >> p.y; }
};

using point_t = point_2d<long long>;

const int N = 2e5 + 10;

int n, k;
point_t a[N], st;

void Hollwo_Pelw(){
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	st = a[-- k];

	sort(a, a + n);

	if (n >= 4) {
		for (int i = 0; i < 4; i++)
			a[i + n] = a[i];
		for (int i = 0; i < n; i++) {
			if (ccw(a[i + 0], a[i + 1], a[i + 2])
			 && ccw(a[i + 1], a[i + 2], a[i + 3])
			 && ccw(a[i + 2], a[i + 3], a[i + 4])) k = (i + 2) % n;
		}
		for (int i = k + 1; i < n; i++)
			swap(a[i - 1], a[i]);
	}

	for (int i = 0; i < n; i++)
		if (a[i] == st) k = i;

	cout << fixed << setprecision(6);

	if (k == n - 1)
		return cout << min(dist(a[n - 1], a[n - 2]), dist(a[n - 1], a[0])) + dist(a[0], a[n - 2]), (void) 0;

	long double res = dist(a[0], a[n - 2]) + min(dist(a[k], a[n - 2]) + dist(a[0], a[n - 1]), 
												 dist(a[k], a[0]) + dist(a[n - 2], a[n - 1]));

	for (int i = 0; i < n - 2; i++) {
		point_t A = a[i], B = a[i + 1], C = a[0], D = a[n - 2];
		if (i < k) swap(A, B), swap(C, D);

		res = min({res,
			dist(a[k], A) + dist(A, C) + dist(C, a[n - 1]) + dist(a[n - 1], B) + dist(B, D),
			dist(a[k], C) + dist(C, A) + dist(A, a[n - 1]) + dist(a[n - 1], B) + dist(B, D)
		});
	}

	cout << res;
}