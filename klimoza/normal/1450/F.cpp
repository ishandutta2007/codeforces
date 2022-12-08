//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
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

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
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

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		vector<bool> used(n);
		vector<pair<int, int>> kek;
		int lst = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> d(n + 1, 0);
		int sz = 0;
		used[0] = true;
		for (int i = 0; i < n; i++) {
			if (lst == -1) lst = i;
			//cout << i << " kek " << lst << endl;
			if (i != lst && a[i] == a[i - 1]) {
				d[a[lst]]++;
				d[a[i - 1]]++;
				//cout << lst << " " << i - 1 << endl;
				used[i] = true;
				sz++;
				lst = i;
			}
		}
		d[a[lst]]++;
		d[a.back()]++;
		sz++;
		ll s = 0;
		bool fl = true;
		for (int i = 0; i <= n; i++) {
			//cout << d[i] << " " << i << endl;
			if (d[i] - 2 > n - 1) {
				fl = false;
				break;
			}
			s += max(0, d[i] - sz + 1 );
		}
		//cout << s << " LOOOL\n";
		if (!fl) {
			cout << -1 << endl;
			continue;
		}
		if (s <= 2) {
			cout << sz - 1 << endl;
			continue;
		}
		vector<pair<int, int>> lol;
		for (int i = 1; i < n; i++) {
			if (used[i]) continue;
			int tmp = 1;
			if (d[a[i - 1]] > sz - 1) tmp--;
			if (d[a[i]] > sz - 1) tmp--;
			lol.push_back(mp(tmp, i));
			//cout << tmp << " " << i << endl;
		}
		sort(rall(lol));
		for (auto u : lol) {
			s -= u.first;
			sz++;
			if (s <= 2) break;
		}
		if (s > 2) cout << -1 << endl;
		else cout << sz - 1 << endl;
	}
	return;
}