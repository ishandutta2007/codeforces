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

const int N = 1e2 + 2;

int a[N][N];

struct Item {
	pair<int, int> x, y, z;
	Item() {}
	Item(pair<int, int> x, pair<int, int> y, pair<int, int> z) : x(x), y(y), z(z) {}
};

vector<Item> ans;

void add(pair<int, int > x, pair<int, int> y, pair<int, int> z) {
	ans.push_back(Item(x, y, z));
}

void pr(Item a) {
	cout << a.x.first + 1 << " " << a.x.second + 1 << " " << a.y.first + 1 << " " << a.y.second + 1 << " " << a.z.first + 1 << " " << a.z.second + 1 << endl;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		ans.clear();
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c; cin >> c;
				a[i][j] = (c - '0');
			}
		}
		for (int i = 0; i < (n - 1); i++) {
			for (int j = 0; j < (m - 1); j++) {
				if (!a[i][j] && !a[i + 1][j]) continue;
				else if (a[i][j] && a[i + 1][j]) {
					a[i][j] ^= 1;
					a[i + 1][j] ^= 1;
					a[i][j + 1] ^= 1;
					ans.push_back(Item(mp(i, j), mp(i + 1, j), mp(i, j + 1)));
				}
				else if (a[i][j]) {
					a[i][j] ^= 1;
					a[i][j + 1] ^= 1;
					a[i + 1][j + 1] ^= 1;
					ans.push_back(Item(mp(i, j), mp(i + 1, j + 1), mp(i, j + 1)));
				}
				else if (a[i + 1][j]) {
					a[i + 1][j] ^= 1;
					a[i][j + 1] ^= 1;
					a[i + 1][j + 1] ^= 1;
					ans.push_back(Item(mp(i + 1, j), mp(i + 1, j + 1), mp(i, j + 1)));
				}
			}
		}
		for (int i = 0; i < (n - 1); i++) {
			if (!a[i][m - 2] && !a[i][m - 1]) continue;
			if (a[i][m - 2] && a[i][m - 1]) {
				a[i][m - 2] ^= 1;
				a[i][m - 1] ^= 1;
				a[i + 1][m - 1] ^= 1;
				ans.push_back(Item(mp(i, m - 2), mp(i, m - 1), mp(i + 1, m - 1)));
			}
			else if (a[i][m - 2]) {
				a[i][m - 2] ^= 1;
				a[i + 1][m - 2] ^= 1;
				a[i + 1][m - 1] ^= 1;
				ans.push_back(Item(mp(i, m - 2), mp(i + 1, m - 2), mp(i + 1, m - 1)));
			}
			else if (a[i][m - 1]) {
				a[i][m - 1] ^= 1;
				a[i + 1][m - 2] ^= 1;
				a[i + 1][m - 1] ^= 1;
				ans.push_back(Item(mp(i + 1, m - 2), mp(i, m - 1), mp(i + 1, m - 1)));
			}
		}
		if (a[n - 1][m - 2] && a[n - 1][m - 1]) {
			ans.push_back(Item(mp(n - 1, m - 2), mp(n - 2, m - 1), mp(n - 2, m - 2)));
			ans.push_back(Item(mp(n - 1, m - 1), mp(n - 2, m - 1), mp(n - 2, m - 2)));
		}
		else if (a[n - 1][m - 2]) {
			add(mp(n - 1, m - 2), mp(n - 1, m - 1), mp(n - 2, m - 1));
			add(mp(n - 2, m - 1), mp(n - 2, m - 2), mp(n - 1, m - 2));
			add(mp(n - 1, m - 1), mp(n - 1, m - 2), mp(n - 2, m - 2));
		}
		else if(a[n - 1][m - 1]) {
			add(mp(n - 1, m - 1), mp(n - 1, m - 2), mp(n - 2, m - 2));
			add(mp(n - 1, m - 1), mp(n - 1, m - 2), mp(n - 2, m - 1));
			add(mp(n - 1, m - 1), mp(n - 2, m - 1), mp(n - 2, m - 2));
		}
		cout << ans.size() << endl;
		for (auto u : ans) {
			pr(u);
		}
	}
	return;
}