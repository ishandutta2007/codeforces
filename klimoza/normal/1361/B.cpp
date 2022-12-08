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

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}

ll add(ll a, ll b) {
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

ll sub(ll a, ll b) {
	a -= b;
	if (a < 0)
		a += mod;
	return a;
}

ll mul(ll a, ll b) {
	return a * b % mod;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		vector<int> k(n);
		for (int i = 0; i < n; i++)
			cin >> k[i];
		sort(all(k));
		if (p == 1)
			cout << (n & 1) << endl;
		else {
			vector<pair<int, int>> cura;
			int curb = -1;
			for (int i = n - 1; i >= 0; i--) {
				if (curb == -1)
					curb = k[i];
				else {
					int x = k[i];
					while (true) {
						if (cura.empty() || cura.back().first != x) {
							cura.push_back({ x, 1 });
							break;
						}
						else {
							cura.back().second++;
							if (cura.back().second == p) {
								cura.pop_back();
								x++;
							}
							else {
								break;
							}
						}
					}
					if (cura.back().first == curb) {
						cura.clear();
						curb = -1;
					}
				}
			}
			if (curb == -1)
				cout << 0 << endl;
			else {
				ll kek = 0;
				for (auto u : cura)
					kek = add(kek, mul(u.second, bp(p, u.first)));
				//cout << curb << kek << endl;
				kek = sub(bp(p, curb), kek);
				cout << kek << endl;
			}
		}
	}
	return;
}