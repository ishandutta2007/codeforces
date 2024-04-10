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
#define rall(v) (v).rbegin(), (v).rend()

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

struct T {
	vector<int> t;
	vector<int> a;
	T() {}
	T(vector<int> a) : a(a) {
		t.resize(4 * a.size());
		build(0, 0, a.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = a[l];
			return;
		}
		build(2 * v + 1, l, (l + r) / 2);
		build(2 * v + 2, (l + r) / 2, r);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
	int get(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return -1;
		if (vl <= l && r <= vr) return t[v];
		return max(get(2 * v + 1, l, (l + r) / 2, vl, vr), get(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
};

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> s(n + 1, -1);
		int m; cin >> m;
		int maxi = 0;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			maxi = max(maxi, a);
			s[b] = max(s[b], a);
		}
		T t = T(s);
		T f = T(a);
		int cur = 0;
		bool fl = true;
		int ans = 0;
		while (cur < n) {
			if (maxi < a[cur]) {
				fl = false;
				break;
			}
			int l = 1, r = n - cur + 1;
			while (r - l > 1) {
				int mid = (l + r) / 2;
				int h = f.get(0, 0, n, cur, cur + mid);
				int x = t.get(0, 0, n + 1, mid, n + 1);
				if (x >= h) l = mid;
				else r = mid;
			}
			ans++;
			cur += l;
		}
		if (!fl) cout << -1 << endl;
		else cout << ans << endl;
	}
}