#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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

const int N = 1e5 + 7;
ll x[N];
vector<int> g[N];
ll ans = 0;

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

void dfs(int v, vector<pair<ll, ll>> & p, int last = -1) {
	vector<pair<ll, ll>> cur = { {x[v], 1} };
	for (auto u : p) cur.push_back({ gcd(u.first, x[v]), u.second });
	sort(all(cur));
	for (int i = cur.size() - 2; i >= 0; i--) {
		if (cur[i].first == cur[i + 1].first) {
			cur[i].second += cur[i + 1].second;
			cur[i + 1].second = 0;
		}
	}
	vector<pair<ll, ll>> f;
	for (auto u : cur) if (u.second) {
		f.push_back(u);
		ans += (u.first * u.second) % mod;
		ans %= mod;
	}
	for (int u : g[v]) {
		if (u == last) continue;
		dfs(u, f, v);
	}
}

void solve() {
	int n; cin >> n;
	fill(x, x + n, 0);
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<pair<ll, ll>> p;
	dfs(0, p);
	cout << ans << endl;
}