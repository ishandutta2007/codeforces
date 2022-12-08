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
	int q; cin >> q;
	while(q--)
	solve();
	return 0;
}

const int N = 3e5 + 7;

vector<int> g[N];
int one[N];

int cntDP(int v, int last = -1) {
	int ans = 0;
	for (int u : g[v]) {
		if (u != last) {
			ans = max(ans, cntDP(u, v));
		}
	}
	if (g[v].size() == 1 && last != -1) {
		one[v] = 1;
		return 1;
	}
	if (g[v].size() == 0) {
		one[v] = 1;
		return 1;
	}
	int maxi1 = 0;
	int maxi2 = 0;
	for (int u : g[v]) {
		if (u == last) continue;
		if (one[u] > maxi1) {
			maxi2 = maxi1;
			maxi1 = one[u];
		}
		else if (one[u] > maxi2) {
			maxi2 = one[u];
		}
	}
	if (last != -1) {
		one[v] = (g[v].size() - 2) + maxi1 + 1;
		//cout << v + 1 << " : " << ans << " " << one[v] << endl;
		if (g[v].size() == 2) maxi2 = 1;
		return max(ans, one[v] + maxi2);
	}
	else {
		one[v] = (g[v].size() - 1) + maxi1 + 1;
		if (g[v].size() == 1) maxi2 = 1;
		return max(ans, one[v] + maxi2 - 1);
	}
}

void solve() {
	int n; cin >> n;
	fill(g, g + n, vector<int>());
	fill(one, one + n, 0);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cout << cntDP(0) << endl;
}