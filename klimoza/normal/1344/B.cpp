/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}


const int N = 1e6 + 7;
const int M = 1e3 + 7;

int p[N], sz[N];

void build(int n) {
	for (int i = 0; i < n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}

int get_par(int k) {
	if (p[k] == k) return k;
	return p[k] = get_par(p[k]);
}

void merge(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	p[b] = a;
}

char f[M][M];
bool l[M][M], u[M][M], d[M][M], r[M][M];
bool lx[M][M], ux[M][M], dx[M][M], rx[M][M];

bool can[M][M];

int n, m;

int id(int x, int y) {
	return x * m + y;
}

int mem[N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> f[i][j];
		}
	}
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			l[i][j] = r[i][j] = u[i][j] = d[i][j] = lx[i][j] = rx[i][j] = ux[i][j] = dx[i][j] = can[i][j] = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i) ux[i][j] = ux[i - 1][j];
			if (j) lx[i][j] = lx[i][j - 1];
			if (!ux[i][j] && f[i][j] == '#') ux[i][j] = true;
			if (!lx[i][j] && f[i][j] == '#') lx[i][j] = true;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			dx[i][j] = dx[i + 1][j];
			rx[i][j] = rx[i][j + 1];
			if (!dx[i][j] && f[i][j] == '#') dx[i][j] = true;
			if (!rx[i][j] && f[i][j] == '#') rx[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (f[i][j] == '.') {
				if (ux[i][j]) d[i][j] = true;
				if (dx[i][j]) u[i][j] = true;
				if (lx[i][j]) r[i][j] = true;
				if (rx[i][j]) l[i][j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		bool fl = false;
		for (int j = 0; j < m; j++) {
			if (r[i][j]) fl = true;
			if (f[i][j] == '.') can[i][j] = true;
			can[i][j] = can[i][j] || fl;
		}
		fl = false;
		for (int j = m - 1; j >= 0; j--) {
			if (l[i][j]) fl = true;
			can[i][j] = can[i][j] || fl;
		}
	}
	for (int j = 0; j < m; j++) {
		bool fl = false;
		for (int i = 0; i < n; i++) {
			if (d[i][j]) fl = true;
			can[i][j] = can[i][j] || fl;
		}
		fl = false;
		for (int i = n - 1; i >= 0; i--)	 {
			if (u[i][j]) fl = true;
			can[i][j] = can[i][j] || fl;
		}
	}
	build(N);
	fill(mem, mem + N, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << can[i][j] << " ";
			if (can[i][j]) continue;
			if (i && !can[i - 1][j]) merge(id(i, j), id(i - 1, j));
			if (j && !can[i][j - 1]) merge(id(i, j), id(i, j - 1));
		}
		//cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (can[i][j]) continue;
			mem[get_par(id(i, j))]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (mem[i] == 0) continue;
		ans++;
	}
	for (int i = 0; i < n; i++) {
		bool kek = true;
		for (int j = 0; j < m; j++) {
			if (!can[i][j])
				kek = false;
			if (!lx[i][j] && !rx[i][j] && !ux[i][j] && !dx[i][j])
				kek = false;
		}
		if (kek) {
			cout << -1 << endl;
			return;
		}
	}
	for (int j = 0; j < m; j++) {
		bool kek = true;
		for (int i = 0; i < n; i++) {
			if (!can[i][j])
				kek = false;
			if (!lx[i][j] && !rx[i][j] && !ux[i][j] && !dx[i][j])
				kek = false;
		}
		if (kek) {
			cout << -1 << endl;
			return;
		}
	}
	cout << ans << endl;
	return;
}