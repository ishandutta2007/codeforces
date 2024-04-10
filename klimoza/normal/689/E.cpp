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

struct Item {
	int x, t;
	Item() {}
	Item(int x, int t) : x(x), t(t) {}
};

const int N = 2e5 + 7;

ll fac[N];

ll bp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res;
}

ll C(ll n, ll k) {
	if (k > n) return 0;
	return (((fac[n] * bp(fac[k], mod - 2)) % mod) * bp(fac[n - k], mod - 2)) % mod;
}

void solve() {
	fac[0] = 1;
	for (ll i = 1; i < N; i++) {
		fac[i] = (fac[i - 1] *1LL * i) % mod;
	}
	int n, k; cin >> n >> k;
	vector<Item> ed;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		ed.push_back({ a, -1 });
		ed.push_back({ b + 1, 1 });
	}
	sort(all(ed), [](Item a, Item b) {return make_pair(a.x, a.t) < make_pair(b.x, b.t); });
	int cnt = 0;
	ll ans = 0;
	for (int i = 0; i < ed.size() - 1; i++) {
		cnt += -ed[i].t;
		ans += (C(cnt, k) * 1LL * (ed[i + 1].x - ed[i].x)) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}