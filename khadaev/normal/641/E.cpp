#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

map<int, int> ans;

void sett(vector<int> &tree, int pos, int val) {
	int sz = tree.size() / 2;
	pos += sz;
	tree[pos] = val;
	while (pos > 1) {
		pos /= 2;
		tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	}
}

int get(vector<int> &tree, int pos) {
	int sz = tree.size() / 2;
	int l = sz, r = pos + sz;
	int sum = 0;
	while (l < r) {
		if (r % 2 == 0) {
			sum += tree[r];
		}
		r  = (r - 1) / 2;
		l /= 2;
	}
	if (l == r) sum += tree[l];
	return sum;
}

void solve(vector<tuple<int, int, int>> &qs) {
	vector<int> times;
	for (auto q : qs) times.eb(get<1>(q));
	sort(all(times));
	map<int, int> comp;
	forn(i, 0, times.size()) comp[times[i]] = i;
	int sz = 1;
	while (sz < times.size()) sz *= 2;
	vector<int> tree(2 * sz);
	for (auto q : qs) {
		int pos = comp[get<1>(q)];
		if (get<0>(q) == 1) {
			sett(tree, pos, tree[pos + sz] + 1);
		} else if (get<0>(q) == 2) {
			sett(tree, pos, tree[pos + sz] - 1);
		} else {
			ans[get<2>(q)] = get(tree, pos);
		}
		//trace(tree);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, vector<tuple<int, int, int>>> q;
	forn(i, 0, n) {
		int a, t, x;
		cin >> a >> t >> x;
		q[x].eb(a, t, i);
	}
	for (auto p : q) solve(p.second);
	for (auto p : ans) cout << p.second << '\n';
	return 0;
}