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

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
//const ll mod = 777777773;
const ll mod = 998244353;
const ll MOD = mod * mod;

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
}

const int N = 2e5 + 7;

int n;

vector<int> g[N];

int d1[N], d2[N];

void bfs(int s, int* d) {
	queue<int> f;
	f.push(s);
	for (int i = 0; i < n; i++)
		d[i] = inf0;
	d[s] = 0;
	while (!f.empty()) {
		int v = f.front();
		f.pop();
		for (int u : g[v]) {
			if (d[u] > d[v] + 1) {
				d[u] = d[v] + 1;
				f.push(u);	
			}
		}
	}
}

struct T {
	vector<int> a, t;
	T() {}
	T(int n) {
		t.resize(4 * n);
		build(0, 0, n);
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = -1;
			return;
		}
		build(2 * v + 1, l, l + r >> 1);
		build(2 * v + 2, l + r >> 1, r);
		t[v] = max(t[2 * v + 2], t[2 * v + 1]);
	}
	int get(int v, int l, int r, int vl, int vr) {
		if (l >= vr || vl >= r) return -1;
		if (vl <= l && r <= vr) return t[v];
		return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}
	void upd(int v, int l, int r, int i, int x) {
		if (i >= r || i < l) return;
		if (r - l == 1) {
			t[v] = x;
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, i, x);
		upd(2 * v + 2, l + r >> 1, r, i, x);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
};

void solve() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m, k;
	cin >> n >> m >> k;
	vector<int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(0, d1);
	bfs(n - 1, d2);
	vector<pair<int, int>> kek(k);
	for (int i = 0; i < k; i++) {
		kek[i] = { d1[a[i]], d2[a[i]] };
	}
	sort(rall(kek));
	int ans = d1[n - 1];
	int l = 1, r = ans + 1;
	//cout << "lol\n";
	//for (auto u : kek)cout << u.first << " " << u.second << endl;
	while (r - l > 1) {
		int m = l + r >> 1;
		bool fl = false;
		T t = T(n);
		//cout << l << " " << r << endl;
		for (int i = 0; i < k; i++) {
			int f = max(0, m - 1 - kek[i].first);
			int k = t.get(0, 0, n, f, n);
			//if(m == 3)	cout << k << " " << f << " " << i << endl;
			if (k == -1) {
				if (t.get(0, 0, n, kek[i].second, kek[i].second + 1) < kek[i].first)
					t.upd(0, 0, n, kek[i].second, kek[i].first);
				continue;
			}
			if (k + kek[i].second >= m - 1) {
				fl = true;
				break;
			}
			if(t.get(0,0,n, kek[i].second, kek[i].second + 1) < kek[i].first)
				t.upd(0, 0, n, kek[i].second, kek[i].first);
		}
		if (fl) l = m;
		else r = m;
	}
	cout << l << endl;
	return;
}