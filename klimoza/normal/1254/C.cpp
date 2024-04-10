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

#define int long long

//#define endl '\n'
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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}


void solve() {
	int n; cin >> n;
	vector<int> p = { 1, 2 };
	vector<pair<int, int>> t;
	vector<int> l1, l2, r1, r2;
	for (int i = 3; i <= n; i++) {
		cout << "1 1 2 " << i << endl;
		int a; cin >> a;
		t.push_back({ a, i });
	}
	sort(all(t));
	int m1 = -1, m2 = -1;
	for (auto u : t) {
		int x = u.second;
		cout << "2 1 " << x << " 2" << endl;
		int a; cin >> a;
		if (a < 0) {
			if (m1 == -1) m1 = x;
			else {
				cout << 2 << " 1 " << x << " " << m1 << endl;
				int a; cin >> a;
				if (a < 0) {
					l2.push_back(m1);
				}
				else {
					l1.push_back(m1);
				}
				m1 = x;
			}
		}
		else {
			if (m2 == -1) m2 = x;
			else {
				cout << 2 << " 1 " << x << " " << m2 << endl;
				int a; cin >> a;
				if (a > 0) {
					r2.push_back(m2);
				}
				else {
					r1.push_back(m2);
				}
				m2 = x;
			}
		}
	}
	vector<int> ans = { 1 };
	for (int i : l1) ans.push_back(i);
	if (m1 != -1) ans.push_back(m1);
	reverse(all(l2));
	for (int i : l2) ans.push_back(i);
	ans.push_back(2);
	for (int i : r2) ans.push_back(i);
	if (m2 != -1) ans.push_back(m2);
	reverse(all(r1));
	for (int i : r1) ans.push_back(i);
	reverse(all(ans));
	for (int i = n - 2; i >= 0; i--) swap(ans[i], ans[i + 1]);
	cout << 0 << " ";
	for (int i : ans) cout << i << " ";
	cout << endl;
}