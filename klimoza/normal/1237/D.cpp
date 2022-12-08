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

//#define int long long

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

struct T {
	vector<int> tmin;
	vector<int> tmax;
	vector<int> a;
	T() {}
	T(vector<int> a) : a(a) {
		tmin.resize(4 * a.size());
		tmax.resize(4 * a.size());
		build(0, 0, a.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			tmin[v] = tmax[v] = a[l];
			return;
		}
		build(2 * v + 1, l, (l + r) / 2);
		build(2 * v + 2, (l + r) / 2, r);
		tmin[v] = min(tmin[2 * v + 1], tmin[2 * v + 2]);
		tmax[v] = max(tmax[2 * v + 1], tmax[2 * v + 2]);
	}
	int getmin(int v, int l, int r, int vl, int vr) {
		if (l >= vr || vl >= r) return 2e9;
		if (vl <= l && r <= vr) return tmin[v];
		return min(getmin(2 * v + 1, l, (l + r) / 2, vl, vr), getmin(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
	int getmax(int v, int l, int r, int vl, int vr) {
		if (l >= vr || vl >= r) return -2e9;
		if (vl <= l && r <= vr) return tmax[v];
		return max(getmax(2 * v + 1, l, (l + r) / 2, vl, vr), getmax(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
};

int n;
T t;

int raz(int l, int r) {
	if (r < l) r += n;
	return r - l;
}

int getmax(int x, int l, int r) {
	int h = t.getmax(0, 0, n, l, r + 1);
	if (h < x) return -1;
	//cout << x << " " << l << " " << r << " CHEECK\n";
	int le = l - 1;
	int re = r;
	while (re - le > 1) {
		int mid = (le + re) / 2;
		if (t.getmax(0, 0, n, l, mid + 1) < x) le = mid;
		else re = mid;
	}
	//cout << le << endl;
	return re;
}

int getmin(int x, int l, int r) {
	int h = t.getmin(0, 0, n, l, r + 1);
	int f = 0;
	if (x % 2 == 0) f = x / 2 - 1;
	else f = x / 2;
	if (h > f) return -1;
	int le = l - 1;
	int re = r;
	while (re - le > 1) {
		int mid = (le + re) / 2;
		if (t.getmin(0, 0, n, l, mid + 1) > f) le = mid;
		else re = mid;
	}
	return re;
}

void solve() {
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	t = T(a);
	vector<int> ans(n);
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > a[maxi]) maxi = i;
	}
	int mini = -1;
	for (int i = (maxi + 1) % n; i != maxi; i = (i + 1) % n) {
		if (2 * a[i] + 1 <= a[maxi]) {
			mini = i;
			break;
		}
	}
	if (mini == -1) {
		for (int i = 0; i < n; i++) cout << -1 << " ";
		return;
	}
	ans[maxi] = raz(maxi, mini);
	for (int i = maxi - 1; i >= 0; i--) {
		int id1 = getmax(a[i], i + 1, maxi);
		int id2 = getmin(a[i], i + 1, maxi);
		if (id2 == -1 || id2 > id1) ans[i] = ans[id1] + raz(i, id1);
		else ans[i] = raz(i, id2);
	}
	for (int i = n - 1; i > maxi; i--) {
		int id1 = getmax(a[i], i + 1, n - 1);
		if (id1 == -1) id1 = getmax(a[i], 0, maxi);
		int id2 = getmin(a[i], i + 1, n - 1);
		if (id2 == -1) id2 = getmin(a[i], 0, maxi);
		//cout << i << endl;
		//cout << id1 << " " << id2 << endl;
		if (id2 == -1 || (id2 < maxi && id1 < maxi && id2 > id1) || (id2 < maxi && id1 > maxi) || (id2 > maxi && id1 > maxi && id2 > id1)) ans[i] = ans[id1] + raz(i, id1);
		else ans[i] = raz(i, id2);
	}
	for (int i : ans) cout << i << " ";
	cout << endl;
}