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

// const int N = 1e5 + 55, mod = 1e9 + 7, M = N * 80;

// #define tm (tl + tr >> 1)
// #define left st[id].lc, tl, tm
// #define right st[id].rc, tm + 1, tr

// int d[N], pre[N], pw[N], nnode, n, m, s, t, minnode, maxnode;

// struct __initial__ {
// 	__initial__ () {
// 		pw[0] = 1;
// 		for (int i = 1; i < N; i++)
// 			pw[i] = 2ll * pw[i - 1] % mod;
// 	}
// } __init__;

// struct node {
// 	int hsh, len, f, lc = 0, rc = 0; // PST only
// 	node () {}
// 	node (int _hsh, int _len, int _f, int _lc, int _rc)
// 		: hsh(_hsh), len(_len), f(_f), lc(_lc), rc(_rc) {}
// } st[M];

// inline int merge(int lc, int rc) {
// 	st[++ nnode] = node(
// 		(1ll * st[rc].hsh * pw[st[lc].len] + st[lc].hsh) % mod,
// 		st[lc].len + st[rc].len,
// 		st[rc].f == -1 ? st[lc].f : st[rc].f, lc, rc
// 	);
// 	return nnode;
// }

// int range_copy(int l, int r, int old, int id, int tl, int tr) {
// 	if (l > tr || tl > r) return id;
// 	if (l <= tl && tr <= r) return old;
// 	return merge(
// 		range_copy(l, r, old, left),
// 		range_copy(l, r, old, right)
// 	);
// }

// int comp(int oth, int id, int tl, int tr) {
// 	if (x == y) return 0;

// }

const int N = 2002, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
const long long inf = 1e18;

int n, m, w, a[N][N], dst[2][N][N];

struct node {
	int x, y, d;
};

queue<node> q;

inline void solve(int id, int sx, int sy) {
	dst[id][sx][sy] = 0;
	q.push({sx, sy, 0});
	while (!q.empty()) {
		node c = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = c.x + dx[i], ny = c.y + dy[i], nd = c.d + 1;
			if (nx < 1 || ny < 1 || nx > n || ny > m || a[nx][ny] == -1) continue ;
			if (nd < dst[id][nx][ny])
				q.push({nx, ny, dst[id][nx][ny] = nd}); 
		}
	}
}

void Hollwo_Pelw() {
	cin >> n >> m >> w;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	memset(dst, 0x3f, sizeof dst), solve(0, 1, 1), solve(1, n, m);
	long long res = (dst[0][n][m] >= 1e9 ? inf : 1ll * dst[0][n][m] * w), mn1 = inf, mn2 = inf;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			if (a[i][j] > 0 && dst[0][i][j] < 1e9)
				mn1 = min(mn1, 1ll * dst[0][i][j] * w + a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] > 0 && dst[1][i][j] < 1e9)
				mn2 = min(mn2, 1ll * dst[1][i][j] * w + a[i][j]);
	res = min(res, mn1 + mn2);
	cout << (res > inf / 2 ? -1 : res) << '\n';
}