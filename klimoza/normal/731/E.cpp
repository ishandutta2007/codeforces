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

const int N = 2e5 + 7;

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	vector<ll> pref(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!i) pref[i] = a[i];
		else pref[i] = (pref[i - 1] + a[i]);
	}
	ll maxi = pref.back();
	ll mini = -pref.back();
	ll ans = maxi;
	for (int i = n - 2; i > 0; i--) {
		//cout << maxi << " " << mini << endl;
		ll f1 = -pref[i] + maxi;
		ll f2 = mini + pref[i];
		ans = max(ans, f2);
		//cout << i + 1 << " " << f1 << " " << f2 << endl;
		maxi = max(maxi, f2); mini = min(mini, f1);
	}
	cout << ans << endl;
}