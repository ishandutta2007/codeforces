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
	int t; cin >> t;
	while (t--) {
		int h, g;
		cin >> h >> g;
		int n = (1 << h) - 1;
		int k = (1 << g) - 1;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int t = n - k;
		vector<int> ans;
		vector<int> sz(n + 1);
		for (int i = n ; i > 0; i--) {
			if(i > k)
			sz[i] = 1;
			if (2 * i <= n) sz[i] += sz[2 * i];
			if (2 * i + 1 <= n) sz[i] += sz[2 * i + 1];
		}
		for (int i = 0; i < t; i++) {
			int cur = 1;
			bool fl = true;
			int p = 1;
			//assert(sz[1] == (t - i));
			while (true) {
				if (2 * cur > k) break;
				if (a[2 * cur] > a[2 * cur + 1]) {
					if (sz[2 * cur]) {
						cur = 2 * cur;
					}
					else {
						p = 2 * cur + 1;
						cur = 2 * cur + 1;
					}
				}
				else {
					if (sz[2 * cur + 1]) {
						cur = 2 * cur + 1;
					}
					else {
						p = 2 * cur;
						cur = 2 * cur;
					}
				}
			}
			int x = p;
			while (x) {
				x /= 2;
				sz[x]--;
			}
			ans.push_back(p);
			while (true) {
				if (!a[p]) break;
				if (2 * p > n) {
					sz[p] = 0;
					a[p] = 0;
					break;
				}
				if (a[2 * p] > a[2 * p + 1]) {
					a[p] = a[2 * p];
					//assert(sz[p]);
					sz[p]--;
					p = 2 * p;
				}
				else {
					a[p] = a[2 * p + 1];
					//assert(sz[p]);
					sz[p]--;
					p = 2 * p + 1;
				}
			}
		}
		ll su = 0;
		/*for (int i = k + 1; i <= n; i++)
			assert(!a[i]);*/
		for (int i = 1; i <= k; i++)
			su += a[i];;
		cout << su << endl;
		for (int i : ans)
			cout << i<< " ";
		cout << endl;
	}
	return;
}