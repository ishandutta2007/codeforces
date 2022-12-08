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
typedef complex<double> cd;
typedef vector<complex<double>> vcd;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
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

void solve() {
	int n; cin >> n;
	vector<vector<int>> a(n);
	ll a1 = 0, a2 = 0;
	vector<int> mem;
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		a[i].resize(s);
		for (int& j : a[i])
			cin >> j;
		for (int j = 0; j < s / 2; j++) {
			a1 += a[i][j];
		}
		reverse(all(a[i]));
		for (int j = 0; j < s / 2; j++)
			a2 += a[i][j];
		if (s & 1)
			mem.push_back(a[i][s / 2]);
	}
	sort(rall(mem));
	for (int i = 0; i < mem.size(); i++) {
		if (i & 1) a2 += mem[i];
		else a1 += mem[i];
	}
	cout << a1 << " " << a2 << endl;
	return;
}