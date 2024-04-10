#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

template <class T>
void read(T &v, bool sg = 0) {
	char c = getchar();
	v = 0;
	for (; !isdigit(c); c = getchar())
		if (c == '-') sg = 1;
	for (;  isdigit(c); c = getchar())
		v = v * 10 + c - '0';
	if (sg) v = -v;
}

template<class T>
void write(T v) {
	static char s[40];
	
	if (!v) return putchar(v + '0'), (void) 0;
	if (v < 0) putchar('-'), v = -v;

	int t = 0;
	while (v) s[t ++] = v % 10 + '0', v /= 10;
	while (t --) putchar(s[t]);
}

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r")){
		freopen("hollwo_pelw.inp", "r", stdin);
		freopen("hollwo_pelw.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	read(testcases);
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

using int128_t = __int128;

const int N = 1e3 + 5;

int n, m, visa[N], visb[N];
int128_t a[N], b[N];

inline int128_t gcd(int128_t a, int128_t b) {
	if (a > b) swap(a, b);
	while (a)
		b %= a, swap(a, b);
	return b;
}

struct segment_tree {
	int128_t st[1 << 12];
	int sz = 1;

	int128_t& operator [] (int x) { return st[x]; }
	const int128_t& operator [] (int x) const { return st[x]; }

	inline void build(int n, int128_t b, int128_t *a) {
		for (sz = 1; sz < n; sz <<= 1);
		fill(st, st + (sz << 1), 0);

		for (int i = 0; i < n; i++)
			st[i + sz] = b / gcd(b, a[i]);
		for (int p = sz - 1; p; p--)
			st[p] = gcd(st[p << 1], st[p << 1 | 1]);
	}

	inline void update(int p, int128_t v) {
		for (st[p += sz] = v; p >>= 1; )
			st[p] = gcd(st[p << 1], st[p << 1 | 1]);
	}
} sta[N], stb[N];

void Hollwo_Pelw(){
	read(n), read(m);
	for (int i = 0; i < n; i++) read(a[i]);
	for (int i = 0; i < m; i++) read(b[i]);

	for (int i = 0; i < n; i++)
		sta[i].build(m, a[i], b);
	for (int i = 0; i < m; i++)
		stb[i].build(n, b[i], a);

	fill(visa, visa + n, 1);
	fill(visb, visb + m, 1);

	queue<int> q;
	for (int i = 0; i < n; i++)
		if (sta[i][1] > 1)
			q.push(i + 0), visa[i] = 0;
	for (int i = 0; i < m; i++)
		if (stb[i][1] > 1)
			q.push(i + n), visb[i] = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();

		if (u < n) {

			for (int i = 0; i < m; i++) if (visb[i]) {
				stb[i].update(u, b[i]);
				if (stb[i][1] > 1)
					q.push(i + n), visb[i] = 0;
			}

		} else {
			u -= n;
			for (int i = 0; i < n; i++) if (visa[i]) {
				sta[i].update(u, a[i]);
				if (sta[i][1] > 1)
					q.push(i + 0), visa[i] = 0;
			}

		}
	}

	int sa = count(visa, visa + n, 1);
	int sb = count(visb, visb + m, 1);

	if (!sa || !sb) {
		puts("NO");
	} else {
		puts("YES");
		write(sa), putchar(' ');
		write(sb), putchar('\n');

		for (int i = 0; i < n; i++)
			if (visa[i]) write(a[i]), putchar(' ');
		putchar('\n');

		for (int i = 0; i < m; i++)
			if (visb[i]) write(b[i]), putchar(' ');
		putchar('\n');
	}
}