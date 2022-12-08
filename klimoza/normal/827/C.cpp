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

double PI = acos((double)-1);
const ld eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;

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

const int N = 1e5 + 6;

int t[4][11][11][N];

void upd(int i, int d, int* tr) {
	for (int j = i; j < N; j = (j | (j + 1))) {
		tr[j] += d;
	}
}

int get(int r, int* tr) {
	int res = 0;
	for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
		res += tr[i];
	return res;
}

int get(int l, int r, int* tr) {
	return get(r, tr) - get(l - 1, tr);
}

map<char, int> f;
char s[N];

void solve() {
	string st; cin >> st;
	int n = st.size();
	for (int i = 0; i < n; i++)
		s[i] = st[i];
	f['A'] = 0; f['T'] = 1; f['G'] = 2; f['C'] = 3;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 10; j++) {
			upd(i, 1, t[f[s[i]]][j][i % j]);
		}
	}
	int q; cin >> q;
	while (q--) {
		int tp; cin >> tp;
		if (tp == 1) {
			int x; char c;
			cin >> x >> c; x--;
			for (int i = 1; i <= 10; i++) {
				upd(x, -1, t[f[s[x]]][i][x % i]);
				upd(x, 1, t[f[c]][i][x % i]);
			}
			s[x] = c;
		}
		else {
			int l, r; string e;
			cin >> l >> r >> e; l--; r--;
			int k = e.size();
			int mem = l % k;
			int ans = 0;
			for (int i = 0; i < k; i++) {
				ans += get(l, r, t[f[e[i]]][k][(mem + i) % k]);
			}
			cout << ans << endl;
		}
	}
	return;
}