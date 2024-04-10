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

const int N = 2e6 + 7;

vector<pair<int, int>> g[N];
int cur;

ll ans[N];
bool used[N];
int p[N];

void bfs() {
	deque<vector<int>> q;
	fill(used, used + N, false);
	ans[0] = 0;
	used[0] = true;
	fill(p, p + N, inf0);
	q.push_back({ 0 });
	while (!q.empty()) {
		auto a = q.front();
		q.pop_front();
		vector<pair<int, int>> lol;
		for (int v : a) {
			//cout << v << " " << ans[v] << endl;
			for (auto u : g[v]) {
				//cout << v << " " << u.first << endl;
				if (p[u.first] > u.second) {
					p[u.first] = u.second;
				}
			}
		}
		for (int v : a) {
			for (auto u : g[v]) {
				if (used[u.first]) continue;
				used[u.first] = true;
				ans[u.first] = (ans[v] * 1ll * 10 + p[u.first]) % mod;
				lol.push_back({ u.first, p[u.first] });
			}
		}
		sort(all(lol), [](pair<int, int> x, pair<int, int> y) {return x.second < y.second; });
		for (int i = 0; i < lol.size(); i++) {
			if (i == 0 || lol[i].second != lol[i - 1].second)
				q.push_back({ lol[i].first });
			else
				q.back().push_back(lol[i].first);
		}
	}
}

void solve() {
	int n;  cin >> n;
	cur = n;
	int m; cin >> m;
	vector<pair<int, int>> ed(m);
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		int x = i;
		if (i >= 10) {
			g[cur].push_back({ b, i % 10 });
			cur++;
			x /= 10;
		}
		while (x % 10 != x) {
			g[cur].push_back({ cur - 1 , x % 10 });
			cur++; x /= 10;
		}
		if (i < 10) {
			g[a].push_back({ b, x });
		}
		else {
			g[a].push_back({ cur - 1, x });
		}
		swap(a, b);
		 x= i;
		if (i >= 10) {
			g[cur].push_back({ b, i % 10 });
			cur++;
			x /= 10;
		}
		while (x % 10 != x) {
			g[cur].push_back({ cur - 1 , x % 10 });
			cur++; x /= 10;
		}
		if (i < 10) {
			g[a].push_back({ b, x });
		}
		else {
			g[a].push_back({ cur - 1, x });
		}
	}
	/*for (int i = 0; i < cur; i++) {
		for (auto j : g[i]) {
			cout << i << " " << j.first << " " << j.second << endl;
		}
	}*/
	fill(ans, ans + N, 0);
	bfs();
	for (int i = 1; i < n; i++)
		cout << ans[i] << endl;
	return;
}