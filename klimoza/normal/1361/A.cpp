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
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(239);

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

const int N = 5e5 + 7;

int cur[N];
int goal[N];
bool used[N];

vector<int> g[N];

void solve() {
	int n, m;
	cin >> n >> m;
	fill(cur, cur + N, 0);
	for (int i = 0; i < m;i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<pair<int, int>> mem;
	for (int i = 0; i < n; i++) {
		cin >> goal[i];
		goal[i]--;
		mem.push_back({ goal[i], i });
	}
	sort(all(mem));
	for(int v = 0; v < n; v++)
		for (int u : g[v]) {
			if (goal[v] == goal[u]) {
				cout << -1 << endl;
				return;
			}
		}
	for (auto u : mem) {
		used[u.second] = true;
		if (cur[u.second] != u.first) {
			cout << -1 << endl;
			return;
		}
		for (int v : g[u.second]) {
			if (cur[v] == u.first && !used[v])
				cur[v]++;
		}
	}
	for (auto u : mem)
		cout << u.second + 1 << " ";
	return;
}