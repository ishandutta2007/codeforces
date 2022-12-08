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

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int lst = -1;
		string s; cin >> s;
		vector<int> mem;
		int ans = 0;
		int cnt = 0;
		int f1 = 0, f2 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'W') {
				f1 = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == 'W') {
				f2 = (n - i - 1);
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == 'W') {
				ans++;
				if (i && s[i - 1] == 'W')
					ans++;
				if (lst != -1 && (i - lst) > 1) {
					mem.push_back(i - lst - 1);
				}
				cnt++;
				lst = i;
			}
		}
		if (k == 0)
			cout << ans << endl;
		else if (k >= (n - cnt))
			cout << (2 * n - 1) << endl;
		else if (cnt == 0) {
			cout << (2 * k - 1) << endl;
		}
		else {
			sort(all(mem));
			for (int i : mem) {
				if (!k) break;
				if (i <= k) {
					k -= i;
					ans += 2 * i + 1;
				}
				else {
					ans += 2 * k;
					k = 0;
				}
			}
			//cout << ans << " " << k << endl;
			if (k) {
				ans += 2 * k;
			}
			cout << ans << endl;
		}
	}
	return;
}