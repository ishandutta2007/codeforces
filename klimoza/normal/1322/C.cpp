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

#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

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
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 5e5 + 7;

vector<int> g[N];
int c[N];

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		fill(g, g + n, vector<int>());
		fill(c, c + n, 0);
		for (int i = 0; i < n; i++)
			cin >> c[i];
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b; a--; b--;
			g[b].push_back(a);
		}
		for (int i = 0; i < n; i++)
			sort(all(g[i]));
		vector<int> p(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
		sort(all(p), [&](int a, int b) {
			return g[a] < g[b]; });
		ll cur = 0;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (g[p[i]].empty()) continue;
			if (!i || g[p[i]] != g[p[i - 1]]) {
				ans = gcd(ans, cur);
				cur = c[p[i]];
			}
			else {
				cur += c[p[i]];
			}
		}
		ans = gcd(ans, cur);
		cout << ans << endl;
	}
	return;
}