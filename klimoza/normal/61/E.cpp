#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod = 998244353;

mt19937 mrand(random_device{} ());

const int N = 1e6 + 7;

int t[N];

void upd(int i, int x) {
	for (int l = i; l < N; l = (l | (l + 1))) {
		t[l] += x;
	}
}

int get(int i) {
	if (i < 0) return 0;
	int res = 0;
	for (int l = i; l >= 0; l = (l & (l + 1)) - 1) {
		res += t[l];
	}
	return res;
}

int ask(int l, int r) {
	return get(r) - get(l - 1);
}

map<int, int> num;

signed main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	vector<int> b = a;
	sort(all(b));
	for (int i = 0; i < n; i++) {
		num[b[i]] = i;
	}
	vector<ll> l(n), r(n);
	for (int i = 0; i < n; i++) {
		l[i] = ask(num[a[i]] + 1, n);
		upd(num[a[i]], 1);
	}
	fill(t, t + n, 0);
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		r[i] = ask(0, num[a[i]] - 1);
		upd(num[a[i]], 1);
		ans += l[i] * r[i];
	}
	cout << ans << endl;
	return 0;
}