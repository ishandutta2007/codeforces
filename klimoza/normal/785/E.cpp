#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
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

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
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

struct T {
	vector<int> t;
	int n;
	T() {}
	T(int n) :n(n) {
		t.resize(n);
	}
	void upd(int id, int x) {
		for (int i = id; i < n; i = (i | (i + 1)))
			t[i] += x;
	}
	int get(int id) {
		int res = 0;
		for (int i = id; i >= 0; i = (i & (i + 1)) - 1)
			res += t[i];
		return res;
	}
	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

const int K = 800;
const int N = 2e5 + 7;

int a[N];
T t[N / K + 1];

int get(int l, int r, int vl, int vr) {
	if (r < l) return 0;
	if (l / K == r / K) {
		int res = 0;
		for (int i = l; i <= r; i++) {
			if (vl <= a[i] && a[i] <= vr)
				res++;
		}
		return res;
	}
	else {
		int res = 0;
		while (l % K) {
			if (vl <= a[l] && a[l] <= vr)
				res++;
			l++;
		}
		while (r % K) {
			if (vl <= a[r] && a[r] <= vr)
				res++;
			r--;
		}
		if (vl <= a[r] && a[r] <= vr)
			res++;
		for (int i = l / K; i < r / K; i++)
			res += t[i].get(vl, vr);
		return res;
	}
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	for (int i = 0; i <= N / K; i++)
		t[i] = T(n);
	for (int i = 0; i < n; i++)
		t[i / K].upd(a[i], 1);
	T cur = T(n);
	ll res = 0;
	for (int i = n - 1; i >= 0; i--) {
		res += cur.get(a[i]);
		cur.upd(a[i], 1);
	}
	while (q--) {
		int l, r;
		cin >> l >> r; l--; r--;	
		if (l > r) swap(l, r);
		if (l == r) {
			cout << res << endl;
			continue;
		}
		res -= get(l + 1, r - 1, 0, a[l]);
		res += get(l + 1, r - 1, a[l], n - 1);
		res -= get(l + 1, r - 1, a[r], n - 1);
		res += get(l + 1, r - 1, 0, a[r]);
		if (a[r] > a[l]) res++;
		else res--;
		t[l / K].upd(a[l], -1);
		t[l / K].upd(a[r], 1);
		t[r / K].upd(a[l], 1);
		t[r / K].upd(a[r], -1);
		swap(a[l], a[r]);
		cout << res << endl;
	}
	return;
}