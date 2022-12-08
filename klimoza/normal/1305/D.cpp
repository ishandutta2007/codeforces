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
#include <queue>
#include <complex>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 1e3 + 7;

vector<int> g[N];

bool used[N];

pair<int, int> dfs(int v, int d = 0, int last = -1) {
	pair<int, int> maxi = { d, v };
	for (int u : g[v]) {
		if (u == last || used[u]) continue;
		maxi = max(maxi, dfs(u, d + 1, v));
	}
	return maxi;
}

void col(int v, int t, int last = -1) {
	if (v == t) {
		used[v] = true;
		return;
	}
	for (int u : g[v]) {
		if (u == last) continue;
		if (used[u]) continue;
		col(u, t, v);
		if (used[u]) {
			used[v] = true;
			return;
		}
	}
}

void solve() {	
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cur = 0;
	int cnt = 0;
	while (true) {
		int f1 = dfs(cur).second;
		int f2 = dfs(f1).second;
		//cout << f1 << " " << f2 << endl;
		if (f1 == f2) {
			cnt++;
			assert(2 * cnt <= n);
			cout << "! " << f1 + 1 << endl;
			break;
		}
		cout << "? " << f1 + 1 << " " << f2 + 1 << endl;
		cin >> cur; cur--;
		col(cur, f1);
		col(cur, f2);
		used[cur] = false;
	}
	return;
}