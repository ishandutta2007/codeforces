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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

int ask(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int t; cin >> t;
	return t;
}

void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << "! " << 1 << endl;
		return;
	}
	vector<int> ans(n);
	int l = 1, r = 2;
	while (r <= n) {
		int t1 = ask(l, r);
		int t2 = ask(r, l);
		if (t2 > t1) {
			ans[r - 1] = t2;
		}
		else {
			ans[l - 1] = t1;
			l = r;
		}
		r++;
	}
	ans[l - 1] = n;
	cout << "! ";
	for (int i : ans)
		cout << i << " ";
	cout << endl;
	return;
}