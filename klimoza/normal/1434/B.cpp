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
//mt19937 mrand(228);

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
	int n; cin >> n;
	set<int> kek;
	vector<int> ans(2 * n);
	bool fl = true;
	vector<pair<int, int>> q = { mp(inf0, -1) };
	for (int i = 0; i < 2 * n; i++) {
		char c; cin >> c;
		if (c == '+') {
			kek.insert(i);
		}
		else {
			int x; cin >> x;
			ans[i] = -1;
			while (!q.empty() && q.back().first < x)
				q.pop_back();
			auto j = (kek.upper_bound(q.back().second));
			if (j == kek.end()) {
				fl = false;
				break;
			}
			ans[*j] = x;
			kek.erase(j);
			q.push_back(mp(x, i));
		}
	}
	if (!fl) cout << "NO" << endl;
	else {
		cout << "YES\n";
		for (int i : ans) {
			if (i == -1) continue;
			else cout << i << " ";
		}
	}
	return;
}