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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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
		vector<pair<ll, ll>> a(n);
		vector<vector<int>> h(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
			h[a[i].first].push_back(a[i].second);
		}
		sort(all(a));
		vector<int> c(n);
		for (auto u : a) c[u.first]++;
		vector<int> pref(n);
		pref[0] = 0;
		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1] + c[i - 1];
		}
		multiset<ll> nt;
		ll ans = 0;
		int cnt = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (auto t : h[i]) nt.insert(t);
			if (pref[i] + cnt >= i) {
				continue;
			}
			else {
				int ed = i - pref[i] - cnt;
				for (int j = 0; j < ed; j++) {
					int f = *nt.begin();
					nt.erase(nt.begin());
					ans += f;
					cnt++;
				}
			}
		}
		cout << ans << endl;
	}
}