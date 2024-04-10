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

const int N = 1e5 + 7;

vector<int> g[N];
set<int> can[N];
int col[N];

void solve() {
	int n, m;
	cin >> n >> m;
	int pa = 0, pb = 0, pc;
	vector<pair<int, int>> ed;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		ed.push_back({ u, v });
		g[u].push_back(v);
		g[v].push_back(u);
		can[u].insert(v);
		can[v].insert(u);
		if (i == 0) {
			pa = u;
			pb = v;
			col[u] = 1;
			col[v] = 2;
		}
	}
	ll sza = 1, szb = 1, szc = 0;
	if (m < 3) {
		cout << -1 << endl;
		return;
	}
	vector<int> a1, a2, a3;
	a1.push_back(pa); a2.push_back(pb);
	for (int i = 0; i < n; i++) {
		if ((i == pa) || (i == pb)) continue;
		if (can[i].find(pa) == can[i].end()) {
			col[i] = 1;
			sza++;
			a1.push_back(i);
		}
		else if (can[i].find(pb) == can[i].end()) {
			col[i] = 2;
			szb++;
			a2.push_back(i);
		}
		else {
			col[i] = 3;
			szc++;
			a3.push_back(i);
		}
	}
	if (!sza || !szb || !szc) {
		cout << -1 << endl;
		return;
	}
	if (((sza * szb) + (sza * szc) + (szb * szc)) > m) {
		cout << -1 << endl;
		return;
	}
	for (int i : a1) {
		for (int j : a2) {
			if (can[i].find(j) == can[i].end()) {
				cout << -1 << endl;
				return;
			}
		}
	}
	for (int i : a1) {
		for (int j : a3) {
			if (can[i].find(j) == can[i].end()) {
				cout << -1 << endl;
				return;
			}
		}
	}
	for (int i : a2) {
		for (int j : a3) {
			if (can[i].find(j) == can[i].end()) {
				cout << -1 << endl;
				return;
			}
		}
	}
	for (auto u : ed) {
		if (col[u.first] == col[u.second]) {
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << col[i] << " ";
	}
	cout << endl;
}