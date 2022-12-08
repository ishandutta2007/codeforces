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
 
#define endl '\n'
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
mt19937 mrand(random_device{}());
 
double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;
 
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

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> a(n), b(m), p(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			p[a[i]] = i;
		}
		ll ans = 0;
		int l = -1;
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			if (l < p[b[i]]) {
				ans += 2 * 1LL * (p[b[i]] - i) + 1;
				l = p[b[i]];
			}
			else {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return;
}