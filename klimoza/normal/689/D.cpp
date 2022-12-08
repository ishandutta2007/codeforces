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

struct T {
	vector<int>	a;
	vector<int> tmax;
	vector<int> tmin;
	T() {}
	T(vector<int> a) :a(a) {
		tmin.resize(4 * a.size());
		tmax.resize(4 * a.size());
		build(0, 0, a.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			tmax[v] = tmin[v] = a[l];
			return;
		}
		build(2 * v + 1, l, (l + r) / 2);
		build(2 * v + 2, (l + r) / 2, r);
		tmax[v] = max(tmax[2 * v + 1], tmax[2 * v + 2]);
		tmin[v] = min(tmin[2 * v + 1], tmin[2 * v + 2]);
	}
	int getmax(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return -2e9;
		if (vl <= l && r <= vr) {
			return tmax[v];
		}
		return max(getmax(2 * v + 1, l, (l + r) / 2, vl, vr), getmax(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
	int getmin(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return 2e9;
		if (vl <= l && r <= vr) {
			return tmin[v];
		}
		return min(getmin(2 * v + 1, l, (l + r) / 2, vl, vr), getmin(2 * v + 2, (l + r) / 2, r, vl, vr));
	}

};

T t1, t2;

void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	t1 = T(a); t2 = T(b);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) continue;
		int f1 = -1, f2 = -1;
		if (a[i] == b[i]) {
			f1 = i - 1;
		}
		else {
			int l = i, r = n;
			while (r - l > 1) {
				int mid = (l + r) / 2;
				int h1 = t1.getmax(0, 0, n, i, mid + 1);
				int h2 = t2.getmin(0, 0, n, i, mid + 1);
				if (h1 < h2) l = mid;
				else r = mid;
			}
			f1 = l;
		}
		int l = i, r = n;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			int h1 = t1.getmax(0, 0, n, i, mid + 1);
			int h2 = t2.getmin(0, 0, n, i, mid + 1);
			if (h1 <= h2) l = mid;
			else r = mid;
		}
		f2 = l;
		int h1 = t1.getmax(0, 0, n, i, f2 + 1);
		int h2 = t2.getmin(0, 0, n, i, f2 + 1);
		if (h1 != h2) continue;
		ans += f2 * 1LL - f1 * 1LL;
	}
	cout << ans << endl;
}