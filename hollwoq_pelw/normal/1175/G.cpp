/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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

#define vl_t int

bool queryhull = 0;

struct line { // y = ax + b,
	mutable vl_t a, b, p;
	bool operator < (const line &oth) const {
		return queryhull ? p < oth.p : a < oth.a;
	}
};

const vl_t inf = 2e9;

struct LineContainer : multiset<line> {
	vl_t div(vl_t a, vl_t b){
		return a / b - ((a ^ b) < 0 && a % b);
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
} cht;

#undef vl_t

const int N = 2e4 + 5;

int n, k, dp[N], ldp[N], a[N], pre[N], suf[N];

inline void addtype1(int id) {
	if (ldp[id] < inf)
		cht.add(-suf[id + 1], suf[id + 1] * id - ldp[id]);
}

inline void addtype2(int id) {
	if (ldp[id] < inf)
		cht.add(id, -ldp[id]);
}

void solve(int l, int r) {
	if (l == r) return ;
	int m = l + r >> 1;
	suf[m + 1] = 0;
	for (int i = m; i >= l; i--)
		suf[i] = max(suf[i + 1], a[i]);
	pre[m] = 0;
	for (int i = m + 1; i <= r; i++)
		pre[i] = max(pre[i - 1], a[i]);
	// let a = max(l + 1 .. mid), b = max(mid + 1 .. r);
	// dp[r] = min(dp[r], dp[l] + max(a, b) * (r - l));
	{
		// a > b 
		// dp[r] = min dp[l] + a * (r - l)
		// 		= min (dp[l] - a * l) + a * r 
		// f(X) = a * X + dp[l] - a * l
		cht.clear();
		for (int i = r, j = l; i >= m + 1; i--) {
			while (j <= m && suf[j + 1] >= pre[i])
				addtype1(j ++);
			dp[i] = min(dp[i], - cht.query(i));
		}
	}
	{
		// a < b
		// dp[r] = min dp[l] + b * (r - l)
		// 		= min (dp[l] - b * l) + b * r
		// f(X) = - X * l + dp[l]
		cht.clear();
		for (int i = m + 1, j = m; i <= r; i++) {
			while (j >= l && suf[j + 1] <= pre[i])
				addtype2(j --);
			dp[i] = min(dp[i], - cht.query(pre[i]) + i * pre[i]);
		}
	}
	solve(l, m), solve(m + 1, r);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		pre[i] = max(pre[i - 1], a[i]), dp[i] = pre[i] * i;
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++)
			ldp[j] = dp[j], dp[j] = inf;
		solve(1, n);
	}
	cout << dp[n];
}