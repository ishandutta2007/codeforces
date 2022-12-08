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

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
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

const int N = 1e3 + 2;

vector<pair<int, int>> g[N];

int d[N][N];

int n;

//void djikstra(int v, int* ds) {
//	//cout << v << endl;
//	set<pair<int, int>> f;
//	for (int i = 0; i < n; i++) {
//		ds[i] = inf0;
//	}
//	ds[v] = 0;
//	for (int i = 0; i < n; i++)
//		f.insert({ ds[i], i });
//	int cnt = 0;
//	while (!f.empty()) {
//		cnt++;
//		if (cnt > n)
//			assert(false);
//		auto v = *f.begin();
//		f.erase(f.begin());
//		if (v.first == inf0) break;
//		for (auto u : g[v.second]) {
//			if (ds[u.second] > v.first + u.first) {
//				f.erase(f.find(mp(ds[u.second], u.second)));
//				ds[u.second] = v.first + u.first;
//				f.insert(mp(ds[u.second], u.second));
//			}
//		}
//	}
//}

void djikstra(int s, int* ds) {
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		ds[i] = inf0;
	ds[s] = 0;
	q.push(mp(0, s));
	while (!q.empty()) {
		int v = q.top().second, cur_d = -q.top().first;
		q.pop();
		if (cur_d > ds[v])  continue;
		for (int j = 0; j < (int)g[v].size(); ++j) {
			int to = g[v][j].second,
				len = g[v][j].first;
			if (ds[v] + len < ds[to]) {
				ds[to] = ds[v] + len;
				q.push(make_pair(-ds[to], to));
			}
		}
	}
}

int d1[N], d2[N];

void solve() {
	int  m, k; cin >> n >> m >> k;
	//n = 1e3; int m = 1e3; int k = 1e3;
	for (int i = 0; i < m; i++) {
		int x, y; int w; cin >> x >> y >> w; x--; y--;
		//int x = i;int  y = (i + 1) % n;int w = 1e3;
		g[x].push_back({ w, y });
		g[y].push_back({ w, x });
	}
	for (int i = 0; i < n; i++) {
		djikstra(i, d[i]);
		//cout << i << endl;
	}
	//cout << "what\n";
	vector<pair<int, int>> lol(k);
	ll s = 0;
	for (int i = 0; i < k; i++) {
		cin >> lol[i].first >> lol[i].second;
		lol[i].first--; lol[i].second--;
		s += d[lol[i].first][lol[i].second];
	}
	set<pair<int, int>> was;
	for (int v = 0; v < n; v++) {
		for (int j = 0; j < g[v].size(); j++) {
			pair<int, int> u = g[v][j];
			if (was.find(mp(v, u.second)) != was.end()) continue;
			was.insert(mp(v, u.second));
			was.insert(mp(u.second, v));
			int x = u.first;
			g[v][j].first = 0;
			djikstra(v, d1);
			djikstra(u.second, d2);
			ll cur = 0;
			//cout << v << endl;
			for (int j = 0; j < k; j++) {
				cur += min(d[lol[j].first][lol[j].second], min(d1[lol[j].first] + d2[lol[j].second], d2[lol[j].first] + d1[lol[j].second]));
			}
			s = min(s, cur);
			g[v][j].first = x;
		}
	}
	cout << s << endl;
	return;
}