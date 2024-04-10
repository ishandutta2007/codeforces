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

const int N = 2e5 + 6;

int a[2][N];

vector<pair<int ,int>> g[N];
int val[N];
bool used[N];

int cnt = 0;
int sz = 0;

bool mem = true;

vector<int> cur;

void dfs(int v) {
	sz++; cnt += val[v];
	used[v] = true;
	cur.push_back(v);
	for (auto u : g[v]) {
		if (used[u.first]) {
			if (val[u.first] != (val[v] ^ u.second)) {
				mem = false;
				return;
			}
			continue;
		}
		val[u.first] = (val[v] ^ u.second);
		dfs(u.first);
	}
}

void solve(){
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vector<pair<int, int>>> kek(n, vector<pair<int, int>>());
		cur.clear();
		for (int i = 0; i < n; i++) {
			g[i].clear(); used[i] = false; val[i] = 0;
			cin >> a[0][i];
			a[0][i]--;
			kek[a[0][i]].push_back({ i, 0 });
		}
		for (int i = 0; i < n; i++) {
			cin >> a[1][i];
			a[1][i]--;
			kek[a[1][i]].push_back({ i, 1 });
		}
		bool fl = true;
		for (int i = 0; i < n; i++) {
			if (kek[i].size() != 2) {
				fl = false;
				break;
			}
		}
		mem = true;
		if (!fl) {
			cout << -1 << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (kek[i][0].second == kek[i][1].second) {
					g[kek[i][0].first].push_back({ kek[i][1].first, 1 });
					g[kek[i][1].first].push_back({ kek[i][0].first, 1 });
				}
				else {
					g[kek[i][0].first].push_back({ kek[i][1].first, 0 });
					g[kek[i][1].first].push_back({ kek[i][0].first, 0 });
				}
			}
			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (!used[i]) {
					val[i] = 0;
					dfs(i);
					ans += min(cnt, sz - cnt);
					if ((sz - cnt) < cnt) {
						for (int i : cur)
							val[i] ^= 1;
					}
					cur.clear();
					cnt = 0; sz = 0;
				}
			}
			if (!mem) {
				cout << -1 << endl;
			}
			else {
				cout << ans << endl;
				for (int i = 0; i < n; i++) {
					if (val[i])
						cout << i + 1 << " ";
				}
				cout << endl;
			}
		}
	}
	return;
}