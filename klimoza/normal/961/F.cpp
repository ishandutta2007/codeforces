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
const double eps = 1e-7;
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

const int N = 1e6 + 7;

int p[N], c[N], pn[N], cn[N], rv[N];
int cnt[N];
int lcp[N];

int n;

void build_lcp(string s) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		int x = c[i];
		int j = p[x - 1];
		while (s[i + k] == s[j + k]) k++;
		lcp[x] = k;
		k = max(k - 1, 0);
	}
}

void radix_sort() {
	fill(cnt, cnt + n, 0);
	for (int i = 0; i < n; i++)
		cnt[c[i]]++;
	for (int i = n - 1; i > 0; i--)
		cnt[i] = cnt[i - 1];
	cnt[0] = 0;
	for (int i = 1; i < n; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++) {
		pn[cnt[c[p[i]]]] = p[i];
		cnt[c[p[i]]]++;
	}
	for (int i = 0; i < n; i++)
		p[i] = pn[i];
}

void build(string s) {
	vector<pair<char, int>> a(n);
	for (int i = 0; i < n; i++)
		a[i] = { s[i], i };
	sort(all(a));
	p[0] = a[0].second;
	c[0] = 0;
	for (int i = 1; i < n; i++) {
		p[i] = a[i].second;
		if (a[i].first == a[i - 1].first)
			c[p[i]] = c[p[i - 1]];
		else
			c[p[i]] = c[p[i - 1]] + 1;
	}
	int k = 0;
	while ((1 << k) < n) {
		for (int i = 0; i < n; i++)
			p[i] = (p[i] - (1 << k) + n) % n;
		radix_sort();
		cn[p[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (mp(c[p[i]], c[p[i] + (1 << k) % n]) == mp(c[p[i - 1]], c[p[i - 1] + (1 << k) % n]))
				cn[p[i]] = cn[p[i - 1]];
			else
				cn[p[i]] = cn[p[i - 1]] + 1;
		}
		for (int i = 0; i < n; i++)
			c[i] = cn[i];
		k++;
	}
	for (int i = 0; i < n; i++)
		rv[p[i]] = i;
	build_lcp(s);
}

const int L = 21;
int sp[N][L];
int kek[N];

void build_sp() {
	kek[1] = 0;
	for (int i = 2; i < N; i++)
		kek[i] = kek[i >> 1] + 1;
	for (int len = 0; len < L; len++) {
		for (int i = 0; i < N && i + (1 << len) - 1 < N; i++) {
			if (len == 0) sp[i][len] = lcp[i];
			else {
				sp[i][len] = min(sp[i][len - 1], sp[i + (1 << (len - 1))][len - 1]);
			}
		}
	}
}

int get(int l, int r) {
	int le = kek[r - l + 1];
	return min(sp[l][le], sp[r - (1 << le) + 1][le]);
}

void solve() {
	cin >> n;
	string s; cin >> s;
	s += "$";
	n++;
	build(s);
	build_sp();
	n--;
	vector<int> upd(n);
	for (int i = 0; i < (n / 2); i++) {
		if (s[i] != s[(n - i - 1)]) continue;
		int l = 0, r = i + 1;
		while (r - l > 1) {
			int m = r + l >> 1;
			int le = rv[i - m];
			int re = rv[n - i - 1 - m];
			if (re < le) swap(re, le);
			int t = get(le + 1, re);
			if (t >= 2 * m + 1) l = m;
			else r = m;
		}
		upd[i - l] = l;
	}
	int cur = 0;
	for (int i = 0; i < n / 2; i++) {
		cur = max(cur, upd[i]);
		if (cur) cout << 2 * cur + 1 << " ";
		else {
			if (s[i] != s[n - i - 1]) cout << -1 << " ";
			else cout << 1 << " ";
		}
		cur = max(cur - 1, 0);
	}
	if (n & 1) cout << -1 << endl;
	return;
}