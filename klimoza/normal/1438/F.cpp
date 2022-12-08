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

//#define endl '\n'


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

const int Q = 420;

int cnt = 0;

int n;

int ask(int x, int y, int z) {
	cnt++;
	if (cnt >= (n + Q)) assert(false);
	cout << "? " << x << " " << y << " " << z << endl;
	int t; cin >> t;
	if (t == -1)
		assert(false);
	t--;
	return t;
}

void solve() {
	int h; cin >> h;
	n = (1 << h) - 1;
	vector<pair<int, int>> kek(n);
	for (int i = 0; i < n; i++)
		kek[i] = mp(0, i);
	for (int i = 0; i < Q; i++) {
		int x = mrand() % n;
		int y = x;
		while (y == x) {
			y = mrand() % n;
		}
		int z = x;
		while (z == x || z == y) {
			z = mrand() % n;
		}
		int t = ask(x + 1, y + 1, z + 1);
		kek[t].first++;
	}
	sort(rall(kek));
	int c1 = kek[0].second;
	int c2 = kek[1].second;	
	for (int i = 0; i < n; i++) {
		if (i == c1 || i == c2) continue;
		int t = ask(i  + 1, c1 + 1, c2 + 1);
		if (t == i) {
			cout << "! " << t + 1 << endl;
			break;
		}
	}
	return;
}