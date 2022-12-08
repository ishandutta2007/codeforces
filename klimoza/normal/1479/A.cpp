//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
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

//#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

int n;

int get(int i) {
	if (i >= n || i < 0) return inf0;
	cout << "? " << (i + 1) << endl;
	int x; cin >> x;
	return x;
}

void ans(int i) {
	cout << "! " << (i + 1) << endl;
}

void solve() {
	cin >> n;
	if (n == 1) {
		cout << "! 1" << endl;
		return;
	}
	int l = 0, r = n - 2;
	if (get(l) < get(l + 1)) {
		ans(0);
		return;
	}
	if (get(r) > get(r + 1)) {
		ans(n - 1);
		return;
	}

	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (get(m) > get(m + 1))
			l = m;
		else
			r = m;
	}
	ans(l + 1);
	return;
}