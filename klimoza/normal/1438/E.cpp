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

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
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

const int N = 2e5 + 6;

ll p[N], a[N];

ll get(ll x) {
	if (x < 0) return 0;
	return p[x];
}

ll get(ll x, ll y) {
	if (x > y) return 0;
	return get(y) - get(x - 1);
}

bool check(ll x, ll l) {
	return (x < (1ll << l));
}

void solve() {
	fill(p, p + N, 0);
	fill(a, a + N, 0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!i)
			p[i] = a[i];
		else
			p[i] = a[i] + p[i - 1];
	}
	ll ans = 0;
	for (int l = 30; l >= 0; l--) {
		for (int i = 0; i < n; i++) {
			if ((1ll << l) & a[i]) {
				int cnt = 0;
				for (int j = i - 1; j >= 0; j--) {
					if ((1ll << l) & a[j])
						cnt++;
					if (cnt == 2) break;
					if ((1ll << l) & a[j])
						continue;
					if (check(a[i] ^ a[j], l + 1) && (a[i] ^ a[j]) == get(j + 1, i - 1)) {
						//cout << j << " kek " << i << " " << l << endl;
						ans++;
					}
				}
				cnt = 0;
				for (int j = i + 1; j < n; j++) {
					if ((1ll << l) & a[j])
						cnt++;
					if (cnt == 2) break;
					if ((1ll << l) & a[j])
						continue;
					if (check(a[i] ^ a[j], l + 1) && (a[i] ^ a[j]) == get(i + 1, j - 1)) {
						//cout << i << " " << j << " " << l << endl;
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return;
}