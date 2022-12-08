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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> l(m);
	ll su = 0;
	for (int i = 0; i < m; i++) {
		cin >> l[i].first;
		su += l[i].first;
	}
	if (su < n) cout << -1 << endl;
	else {
		if (m - 1 + l.back().first > n) cout << -1 << endl;
		else {
			vector<int> p(m);
			for (int i = 0; i < m; i++) {
				p[i] = i;
				if (i + l[i].first > n) {
					cout << -1 << endl;
					return;
				}
			}
			int t = n;
			for (int i = m - 1; i >= 0; i--) {
				p[i] = max(t - l[i].first, p[i]);
				t = p[i];
			}
			for (int i = 0; i < m; i++)
				cout << p[i] + 1 << " ";
			cout << endl;
		}
	}
	return;
}