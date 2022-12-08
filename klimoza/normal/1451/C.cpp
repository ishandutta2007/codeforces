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
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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
		int n, k; cin >> n >> k;
		vector<int> c1(26, 0), c2(26, 0);
		string a, b; cin >> a >> b;
		for (char c : a) {
			c1[c - 'a']++;
		}
		for (char c : b) {
			c2[c - 'a']++;
		}
		bool fl = true;
		for (int i = 0; i < 26; i++) {
			if (c1[i] < c2[i]) {
				fl = false;
				break;
			}
			else {
				if ((c1[i] - c2[i]) % k) {
					fl = false;
					break;
				}
				if (i == 25) {
					if (c1[i] != c2[i]) {
						fl = false;
					}
					break;
				}
				int l = (c1[i] - c2[i]) / k;
				c1[i] -= l * k;
				c1[i + 1] += l * k;
			}
		}
		if (fl) cout << "Yes\n";
		else cout << "No\n";
	}
	return;
}