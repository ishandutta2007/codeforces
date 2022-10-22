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

const int N = 2005;

int n, m, d[N][N], f[N];
char a[N][N];

struct line_t {
	int a, b;
	line_t (int _a = 0, int _b = 0)
		: a(_a), b(_b) {}
	inline int operator () (int x) { return a * x + b; }
} dq[N];

inline void solve(int * d, int n) {
	// f[i] = min d[j] + (j - i) ^ 2
	memset(f, 0x3f, sizeof f);
	
	int qh = 1, qt = 0;

	auto add = [&](const line_t &a) {
		// x(l1, l2) = (l1.b - l2.b) / (l2.a - l1.a)

		auto bad = [&](const line_t &b, const line_t &c) -> bool {
			// x(a, b) >= x(a, c)
			return 1ll * (a.b - b.b) * (c.a - a.a) >= 1ll * (a.b - c.b) * (b.a - a.a);
		};

		while (qh < qt && bad(dq[qt - 1], dq[qt]))
			qt --;
		dq[++ qt] = a;
	};
	
	for (int i = 0; i <= n; i++) {
		if (d[i] <= 1e9)
			add(line_t(- 2 * i, i * i + d[i]));
	}

	auto query = [&](int x) -> int {
		while (qh < qt && dq[qh + 1](x) <= dq[qh](x))
			qh ++;
		return dq[qh](x);
	};

	for (int i = 0; i <= n; i++)
		f[i] = min(f[i], query(i) + i * i);
}

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		cin >> a[i];
	
	memset(d, 0x3f, sizeof d);

	for (int j = 0; j <= m; j++) {
		for (int i = 0, f = -1; i <= n; i++) {
			if (a[i][j] == '1') f = i;
			if (~f) d[i][j] = min(d[i][j], (f - i) * (f - i));
		}
		for (int i = n, f = -1; i >= 0; i--) {
			if (a[i][j] == '1') f = i;
			if (~f) d[i][j] = min(d[i][j], (f - i) * (f - i));
		}
	}

	long long res = 0;
	
	for (int i = 0; i <= n; i++) {
		memset(f, 0x3f, sizeof f);

		solve(d[i], m);
		for (int j = 0; j <= m; j++)
			res += f[j];
	}

	cout << res << '\n';
}