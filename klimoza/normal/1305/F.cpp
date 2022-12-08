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
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

const int N = 1e6 + 7;

vector<int> fac(int n) {
	vector<int> t;
	for(int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) {
			t.push_back(i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		t.push_back(n);
	return t;
}

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;
	int ans = n;
	for (int it = 0; it < 20; it++) {
		int x = mrand() % n;
		vector<ll> t = fac(a[x]);
		vector<ll> t2 = fac(a[x] + 1);
		vector<ll> t3;
		if (a[x] > 1) t3 = fac(a[x] - 1);
		for (ll i : t2) t.push_back(i);
		for (ll i : t3) t.push_back(i);
		sort(all(t));
		t.erase(unique(all(t)), t.end());
		for (ll i : t) {
			ll cur = 0;
			for (ll j : a) {
				if (j < i) cur += i - j;
				else cur += min(j % i, i - j % i);
			}
			//cout << i << " " << cur << endl;
			ans = min((ll)ans, cur);
		}
	}
	cout << ans << endl;
	return;
}