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

const int N = 32;
const int T = N - 1;
const int K = 1e6;

vector<pair<int, int>> g[N];

struct Edge {
	int u, v, d;
	Edge() {}
	Edge(int u, int v, int d) : u(u), v(v), d(d) {}
};

int id(int i) {
	return 30 - (i - 2);
}

void solve() {
	int l, r; cin >> l >> r;
	int n = N;
	g[0].push_back(mp(31, l));
	if (l != r) {
		int t = 1;
		if (l == 1)
			t = 0;
		else
			g[0].push_back(mp(1, l - 1));
		for (int i = 2; i < T; i++) { // i -> [1, 2 ^ (i - 2)]
			g[id(i)].push_back(mp(31, 1));
			for (int j = i - 1; j > 1; j--) { // j -> [1, 2 ^ (j - 2)] 
				if((1ll << (j - 2)) <= K)
					g[id(i)].push_back(mp(id(j), 1ll << (j - 2)));
			}
		}
		int x = r - l;
		int c = 0;
		for (int i = 31 - 1; i > 1; i--) {
			if (x & (1ll << (i - 2))) {
				g[t].push_back(mp(id(i), c + 1));
				c += (1ll << (i - 2));
			}
		}
	}
	vector<Edge> ans;
	for (int i = 0; i <= 31; i++) {
		for (auto u : g[i])
			ans.push_back(Edge(i + 1, u.first + 1, u.second));
	}
	cout << "YES" << endl;
	cout << n << " " << ans.size() << endl;
	for (auto u : ans)
		cout << u.u << " " << u.v << " " << u.d << endl;
	return;
}