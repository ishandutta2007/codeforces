#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
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
		int n; cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		string s; cin >> s;
		int t1 = 0, t2 = 0, t3 = 0;
		for (char t : s) {
			if (t == 'R') t1++;
			if (t == 'P') t2++;
			if (t == 'S') t3++;
		}
		int wn = 0;
		string ans = "";
		for (char t : s) {
			if (t == 'R') {
				t1--;
				if (b > 0) {
					b--;
					wn++;
					ans += "P";
				}
				else {
					if ((a - t3) > (c - t2)) {
						a--;
						ans += "R";
					}
					else {
						c--;
						ans += "S";
					}
				}
			}
			if (t == 'P') {
				t2--;
				if (c > 0) {
					c--;
					wn++;
					ans += "S";
				}
				else {
					if ((a - t3) > (b - t1)) {
						a--;
						ans += "R";
					}
					else {
						b--;
						ans += "P";
					}
				}
			}
			if (t == 'S') {
				t3--;
				if (a > 0) {
					a--;
					wn++;
					ans += "R";
				}
				else {
					if ((c - t2) > (b - t1)) {
						c--;
						ans += "S";
					}
					else {
						b--;
						ans += "P";
					}
				}
			}
		}
		if (2 * wn >= n) cout << "YES\n" << ans << "\n";
		else cout << "NO\n";
	}
}