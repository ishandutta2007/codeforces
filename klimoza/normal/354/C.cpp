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

mt19937 mrand(43);

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

const int N = 1e6 + 7;

int cnt[N];

int n, k;
int a[N];

int upd[N], val[N];

void solve() {
	fill(upd, upd + N, 0);
	fill(val, val + N, 0);
	cin >> n >> k;
	int mx = k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = min(mx, a[i]);
		upd[a[i]] += 1;
		if (a[i] >= k + 1)
			upd[a[i] - k - 1] += -1;
	}
	int c = 0;
	for (int i = N - 1; i >= 0; i--) {
		c += upd[i];
		val[i] = c;
	}
	for (int i = k + 1; i < N; i++) {
		int cnt = 0;
		for (int j = i; j < N; j += i)
			cnt += val[j];
		if (cnt == n)
			mx = i;
	}
	cout << mx << endl;
	return;

}