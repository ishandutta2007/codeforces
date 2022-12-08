
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
	int n; cin >> n;
	vector<pair<int, int>> ans;
	vector<int> a(n);
	int id = -1;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		if (a[i]) {
			id = i;
			break;
		}
	}
	if (id == -1) cout << 0 << endl;
	else if (a[id] > 1) cout << -1 << endl;
	else {
		int lst = -1;
		set<int> h;
		set<int> h3;
		bool fl = true;
		for (int i = n - 1; i >= 0; i--) {
			if (!a[i]) continue;
			//cout << i << " " << h.size() << endl;
			if (a[i] == 1) {
				ans.push_back({ i, i });
				h.insert(i);
			}
			else if (a[i] == 2) {
				if (h.empty()) {
					fl = false;
					break;
				}
				ans.push_back({ *h.begin(), i });
				h.erase(h.begin());
				h3.insert(i);
			}
			else {
				if (!h3.empty()) {
					ans.push_back({ i, i });
					ans.push_back({ i, *h3.begin() });
					h3.erase(h3.begin());
					h3.insert(i);
				}
				else if (!h.empty()) {
					ans.push_back({ i, i });
					ans.push_back({ i, *h.begin() });
					h.erase(h.begin());
					h3.insert(i);
				}
				else {
					fl = false;
					break;
				}
			}
		}
		if (!fl) cout << -1 << endl;
		else {
			cout << ans.size() << endl;
			for (auto u : ans)
				cout << u.first + 1 << " " << u.second + 1 << endl;
		}
	}
	return;
}