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
const ll mod = 1009;
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

void solve(){
	int n, m; cin >> n >> m;
	ll x, k, y; cin >> x >> k >> y;
	vector<int> a(n);
	map<int, int> lol;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		lol[a[i]] = i;
	}
	vector<int> b(m);
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		if (lol.find(b[i]) == lol.end()) {
			cout << -1 << endl;
			return;
		}
		p[i] = lol[b[i]];
	}
	p.push_back(n);
	reverse(all(p));
	p.push_back(-1);
	reverse(all(p));
	ll ans = 0;
	for (int i = 1; i < p.size(); i++) {
		int mem = -1;
		if (p[i] < p[i - 1]) {
			cout << -1 << endl;
			return;
		}
		if (p[i - 1] != -1) mem = max(mem, a[p[i - 1]]);
		if (p[i] != n) mem = max(mem, a[p[i]]);
		if (p[i] == p[i - 1] + 1) continue;
		int kek = -1;
		for (int j = p[i - 1] + 1; j < p[i]; j++) {
			kek = max(kek, a[j]);
		}
		ll len = p[i] - p[i - 1] - 1;
		if (len < k && kek > mem) {
			cout << -1 << endl;
			return;
		}
		if (len < k)
			ans += len * y;
		else if (kek < mem) {
			ans += min(len / k * x + (len % k) * y, len * y);
		}
		else {
			ans += min(len / k * x + (len % k) * y, x + (len - k) * y);
		}
	}
	cout << ans << endl;
	return;
}