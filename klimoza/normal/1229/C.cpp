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
const int K = 600;

vector<int> g[N];
int d[N];
ll cntl[N];
ll cntb[N];

void solve() {
	int n, m; cin >> n >> m;
	fill(d, d + n, 0);
	fill(cntl, cntl + n, 0);
	fill(cntb, cntb + n, 0);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		d[a]++; d[b]++;
		if (a > b) {
			cntl[a]++; cntb[b]++;
			g[b].push_back(a);
		}
		else {
			cntl[b]++; cntb[a]++;
			g[a].push_back(b);
		}
	}
	ll tot = 0;
	for (int i = 0; i < n; i++) {
		tot += cntl[i] * cntb[i];
	}
	cout << tot << endl;
	int h; cin >> h;
	for(int q = 0; q  < h; q++) {
		int t; cin >> t; t--;
		tot -= cntl[t] * cntb[t];
		cntl[t] = d[t]; cntb[t] = 0;
		for (int u : g[t]) {
			tot -= cntl[u] * cntb[u];
			cntl[u]--;
			cntb[u]++;
			tot += cntl[u] * cntb[u];
			g[u].push_back(t);
		}
		g[t].clear();
		cout << tot << endl;
	}
}