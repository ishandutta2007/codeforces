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

const double PI = acos((double)-1);
const double eps = 1e-7;
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
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s; cin >> s;
		vector<pair<char, int>> kek;
		sort(all(s));
		for (int i = 0; i < n; i++) {
			if (!i || kek.back().first != s[i]) {
				kek.push_back({ s[i], 1 });
			}
			else
				kek.back().second++;
		}
		if (kek.size() == 1) {
			int x = (kek[0].second + k - 1) / k;
			for (int i = 0; i < x; i++)
				cout << s[0];
			cout << endl;
		}
		else if (kek.size() == 2 && kek[0].second == k) {
			cout << kek[0].first;
			int x = (kek[1].second + k - 1) / k;
			for (int i = 0; i < x; i++)
				cout << kek[1].first;
			cout << endl;
		}
		else {
			if (kek[0].second < k) {
				int x = k;
				for (int i = 0; i < kek.size(); i++) {
					k -= kek[i].second;
					if (k <= 0) {
						cout << kek[i].first << endl;
						break;
					}
				}
			}
			else {
				kek[0].second -= k - 1;
				for (auto u : kek) {
					for (int i = 0; i < u.second; i++)
						cout << u.first;
				}
				cout << endl;
			}
		}
	}
	return;
}