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

const int N = 1e6 + 7;

int cnt[N];

ll mul(ll a, ll b) {
	a = a * b;
	if (a >= mod) a = a % mod;
	return a;
}

ll add(ll a, ll b) {
	if (a + b >= mod) return a + b - mod;
	else return a + b;
}

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		k >>= 1;
	}
	return res;
}

void solve() {
	fill(cnt, cnt + N, 0);
	int n; cin >> n;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		a[i].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> a[i][j];
			cnt[a[i][j]]++;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j : a[i]) {
			ll f1 = bp(n * 1LL * n % mod, mod - 2);
			f1 = mul(f1, bp(a[i].size(), mod - 2));
			ans = add(ans, mul(f1, cnt[j]));
		}
	}
	cout << ans << endl;
	return;
}