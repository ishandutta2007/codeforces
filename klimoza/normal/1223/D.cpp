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
#include <complex>

#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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
	int q;
	cin >> q;
	while (q--) {
		int n; cin >> n;
		vector<bool> canmin(n + 5);
		vector<bool> canplus(n + 5);
		vector<int> a(n);
		vector<int> f(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		f = a;
		sort(all(f));
		vector<int> nm(n + 5);
		nm[f[0]] = 1;
		int id = 1;
		for (int i = 1; i < n; i++) {
			if (f[i] == f[i - 1]) continue;
			nm[f[i]] = nm[f[i - 1]] + 1;
			id++;
		}
		for (int i = 0; i < n; i++)  a[i] = nm[a[i]];
		set<int> cur;
		for (int i = n - 1; i >= 0; i--) {
			if (cur.find(a[i] + 1) != cur.end()) canplus[a[i]] = true;
			if (cur.find(a[i] - 1) != cur.end()) canmin[a[i]] = true;
			cur.insert(a[i]);
			//cout << canplus[a[i]] << " " << canmin[a[i]] << " " << a[i] << endl;
		}
		int ans = 0;
		int cc = 1;
		for (int i = 1; i < n; i++) {
			if (canplus[i] && !canmin[i + 1]) cc++;
			else {
				ans = max(ans, cc);
				cc = 1;
			}
		}
		ans = max(ans, cc);
		cout << id - ans << endl;
	}
}