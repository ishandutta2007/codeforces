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
const ld eps = 1e-7;
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
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(all(a));
		a.erase(unique(all(a)), a.end());
		set<ll> f;
		for (int i = 0; i < n; i++)
			f.insert(a[i]);	
		ll h = a.back();
		ll ans = h;
		if (h % 2 == 0 && h % 3 == 0 && h % 5 == 0 && f.find(h / 2) != f.end() && f.find(h / 5) != f.end() && f.find(h / 3) != f.end())
			ans = h / 2 + h / 3 + h / 5;
		ll kek = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (h % a[i]) {
				ans = max(ans, h + a[i]);
				for (int j = i - 1; j >= 0; j--) {
					if (h % a[j] && a[i] % a[j]) {
						ans = max(ans, h + a[i] + a[j]);
						break;
					}
				}
				break;
			}
		}
		cout << ans << endl;
	}
	return;
}