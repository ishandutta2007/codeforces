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


void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a1, a2;
		for (int i = 0; i < 2 * n; i++) {
			int x; cin >> x;
			if (x & 1)
				a1.push_back(i);
			else
				a2.push_back(i);
		}
		if (((int)a1.size()) & 1) {
			a1.pop_back();
			a2.pop_back();
		}
		else if (!a1.empty()) {
			a1.pop_back();
			a1.pop_back();
		}
		else {
			a2.pop_back();
			a2.pop_back();
		}
		for (int i = 0; i < a1.size(); i += 2) {
			cout << a1[i] + 1 << " " << a1[i + 1] + 1 << endl;
		}
		for (int i = 0; i < a2.size(); i += 2) {
			cout << a2[i] + 1 << " " << a2[i + 1] + 1 << endl;
		}
	}
	return;
}