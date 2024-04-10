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
const double eps = 1e-8;
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
	vector<pair<int, int>> t;
	vector<int> a;
	T() {}
	T(vector<int> a) : a(a) {
		t.resize(4 * a.size());
		build(0, 0, a.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = { a[l], -l };
			return;
		}
		build(2 * v + 1, l, (l + r) / 2);
		build(2 * v + 2, (l + r) / 2, r);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
	pair<int, int> get(int v, int l, int r, int vl, int vr) {
		if (l >= vr || vl >= r) return { -1, -1 };
		if (vl <= l && r <= vr) return t[v];
		return max(get(2 * v + 1, l, (l + r) / 2, vl, vr), get(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
};

const int N = 5e5 + 8;
T tr;
int n;

vector<int> ans;

void dfs(int l, int r, int a, int b) {
	pair<int, int> h = tr.get(0, 0, n, l, r + 1);
	h.second *= -1;
	ans[h.second] = b;
	if (a == b) return;
	//cout << h.first << " " << h.second << endl;
	//cout << l << " " << r << " " << a << " " << b << endl;
	if (h.second == l) dfs(l + 1, r, a, b - 1);
	else if (h.second == r) dfs(l, r - 1, a, b - 1);
	else {
		int sz1 = h.second - l;
		dfs(l, l + sz1 - 1, a, a + sz1 -1);
		dfs(l + sz1 + 1, r, a + sz1, b - 1);
	}
}

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		vector<int> nxt(n);
		ans.clear(); ans.resize(n);

		for (int i = 0; i < n; i++) {
			cin >> nxt[i];
			if (nxt[i] == -1) nxt[i] = i + 2;
			nxt[i]--;
		}
		tr = T(nxt);
		dfs(0, n - 1, 1, n);
		bool fl = true;
		tr = T(ans);
		for (int i = 0; i < n; i++) {
			pair<int, int> g = tr.get(0, 0, n, i, nxt[i]);
			if (g.first > ans[i]) {
				fl = false;
				break;
			}
			if (nxt[i] != n && ans[nxt[i]] < ans[i]) {
				fl = false;
				break;
			}
		}
		if (!fl) cout << -1 << endl;
		else {
			for (int i : ans) cout << i << " ";
			cout << endl;
		}
	}
}