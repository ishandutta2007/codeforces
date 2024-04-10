#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
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

ll foo(ll n) {
	return (n * (n - 1) / 2) % mod;
}

void solve() {

	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	vector<int> rv(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		rv[p[i]] = i;
	}
	vector<ll> id;
	ll sum = 0;
	for (int i = n; i > n - k; i--) {
		sum += i;
		id.push_back(rv[i]);
	}
	sort(all(id));
	ll cur = 1;
	for (int i = 1; i < id.size(); i++) {
		cur = cur * 1ll * (id[i] - id[i - 1]) % mod;
	}
	cout << sum << " " << cur << endl;
	return;
}