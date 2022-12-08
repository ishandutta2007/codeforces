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

ll m, d;
ll ans = 0;

void add(ll& a, ll b) {
	a %= m;
	b %= m;
	a += b;
	if (a >= m) a -= m;
}

const int L = 31;

ll dp[L];

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> d >> m;
		ans = 0;
		ll s = 1;
		for (int j = 0; j < L; j++) {
			if ((1ll << j) > d) break;
			else if (!j) dp[j] = 1;
			else if((2ll << j) > d){
				dp[j] = (s * 1ll * (d - (1ll << j) + 1)) % m;
			}
			else {
				dp[j] = (s * 1ll * ((2ll << j) - (1ll << j))) % m;
			}
			add(s, dp[j]);
			add(ans, dp[j]);
		}
		cout << ans << endl;
	}
	return;
}