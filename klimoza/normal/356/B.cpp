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

mt19937 mrand(239);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1009;
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

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

void solve(){
	ll n, m; cin >> n >> m;
	string x, y; cin >> x >> y;
	ll a = x.size(), b = y.size();
	ll g = gcd(a, b);
	vector<vector<int>> t1(g, vector<int>(26));
	vector<vector<int>> t2(g, vector<int>(26));
	ll mem = n * a / g;
	for (int i = 0; i < a; i++) {
		t1[i % g][x[i] - 'a']++;
	}
	for (int i = 0; i < b; i++) {
		t2[i % g][y[i] - 'a']++;
	}
	ll cnt = n * a / lcm(a, b);
	ll ans = 0;
	for (int i = 0; i < g; i++) {
		for (int j = 0; j < 26; j++) {
			ans += t1[i][j] * 1ll * ((b / g) - t2[i][j]) * 1ll * cnt;
		}
	}
	cout << ans << endl;
	return;
}