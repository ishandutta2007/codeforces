//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
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
#include <stack>
#include <ctime>

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
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
//const ll mod = 1e9 + 7;
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

const int N = 2e5 + 2;

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
	a = get_par(a); b = get_par(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	p[b] = a;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		build(n);
		vector<int> a(n, 0);
		int cnt = 0;
		int ans = m;
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y; x--; y--;
			if (x == y) {
				ans--;
				continue;
			}
			merge(x, y);
			a[x]++;
			a[y]++;
		}
		vector<bool> used(n, false);
		int mem = 0;
		for (int i = 0; i < n; i++) {
			if (!a[i]) continue;
			if (used[get_par(i)]) continue;
			mem++;
			used[get_par(i)] = true;
		}
		used.assign(n, false);
		for (int i = 0; i < n; i++) {
			if (!a[i]) continue;
			if (used[get_par(i)]) continue;
			if (a[i] == 1) {
				mem--;
				used[get_par(i)] = true;
				continue;
			}
		}
		ans += mem;
		cout << ans << endl;
	}
	return;
}