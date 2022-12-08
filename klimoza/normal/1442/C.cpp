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

#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());
//mt19937 mrand(228);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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
const int L = 18;

vector<int> g[N];
vector<pair<int, ll>> bg[N * L];
ll d[N * L];

int id(int x, int l) {
	return x + l * N;
}

void djikstra(int s, ll* cd, vector<pair<int, ll>>* cg) {
	fill(cd, cd + N * L, inf);
	cd[s] = 0;
	priority_queue<pair<ll, int>> q;
	q.push(mp(cd[s], s));
	while (!q.empty()) {
		int v = q.top().second, w = -q.top().first;
		q.pop();
		if (w > cd[v])
			continue;
		for (pair<int, ll> u : cg[v]) {
			if (cd[u.first] > w + u.second) {
				cd[u.first] = w + u.second;
				q.push(mp(-cd[u.first], u.first));
			}
		}
	}
}

vector<pair<int, pair<int, int>>> ng[N * 2];
pair<int, int> nd[N * 2];

pair<int, int> operator+(pair<int, int> x, pair<int, int> y) {
	return mp(x.first + y.first, x.second + y.second);
}

pair<int, int> operator-(pair<int, int> x, pair<int, int> y) {
	return mp(x.first - y.first, x.second - y.second);
}

void djikstra(int s, pair<int, int>* cd, vector<pair<int, pair<int, int>>>* cg) {
	fill(cd, cd + N * 2, mp(inf, inf));
	cd[s] = mp(0, 0);
	priority_queue<pair<pair<int, int>, int>> q;
	q.push(mp(cd[s], s));
	while (!q.empty()) {
		int v = q.top().second;
		pair<int, int> w = mp(0,0)-q.top().first;
		q.pop();
		if (w > cd[v])
			continue;
		for (pair<int, pair<int, int>> u : cg[v]) {
			if (cd[u.first] > w + u.second) {
				cd[u.first] = w + u.second;
				q.push(mp(mp(0, 0)-cd[u.first], u.first));
			}
		}
	}
}

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1)
			res = (res * a) % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (L - 1); j++) {
			bg[id(i, j)].push_back({ id(i,j + 1), 1ll << j });
		}
		for (int j = 0; j < L; j++) {
			for (int u : g[i]) {
				if (j % 2 == 0)
					bg[id(i, j)].push_back({ id(u, j), 1 });
				else
					bg[id(u, j)].push_back({ id(i, j), 1 });
			}
		}
	}
	djikstra(0, d, bg);
	ll ans = inf;
	for (int j = 0; j < L; j++)
		ans = min(ans, d[id(n - 1, j)]);
	if (ans != inf)
		cout << ans << endl;
	else {
		for (int i = 0; i < n; i++) {
			ng[i].push_back(mp(i + N, mp(1, 0)));
			ng[i + N].push_back(mp(i, mp(1, 0)));
			for (int u : g[i]) {
				ng[i].push_back(mp(u, mp(0, 1)));
				ng[u + N].push_back(mp(i + N, mp(0, 1)));
			}
		}
		djikstra(0, nd, ng);
		pair<int, int> ans = min(nd[n - 1], nd[n - 1 + N]);
		cout << (ans.second + bp(2, ans.first) - 1 + mod) % mod << endl;
	}
	return;
}