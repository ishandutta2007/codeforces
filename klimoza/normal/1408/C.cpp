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
		int n, l; cin >> n >> l;
		vector<ld> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		a.push_back(l);
		reverse(all(a)); a.push_back(0); reverse(all(a));
		n += 2;
		vector<ld> t1(n), t2(n);
		t1[0] = 0;
		ld cur = 1;
		for (int i = 1; i < n; i++) {
			t1[i] = t1[i - 1] + (a[i] - a[i - 1]) / cur;
			cur++;
		}
		t2[n - 1] = 0;
		cur = 1;
		for (int i = n - 2; i >= 0; i--) {
			t2[i] = t2[i + 1] + (a[i + 1] - a[i]) / cur;
			cur++;
		}
		bool fl = false;
		for (int i = 0; i < n; i++) {
			if (t1[i] == t2[i]) {
				cout << t1[i] << endl;
				fl = true;
				break;
			}
		}
		if (!fl) {
			for (int i = 1; i < n; i++) {
				if (t1[i] > t2[i]) {
					ld v1 = i;
					ld v2 = (n - i);
					ld ans = (t1[i - 1] * v1 + t2[i] * v2 + (a[i] - a[i - 1])) / (v1 + v2);
					cout << ans << endl;
					break;
				}
			}
		}
	}
	return;
}