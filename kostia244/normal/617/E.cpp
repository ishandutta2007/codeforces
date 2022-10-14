#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 696969569;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll moid(ll x, ll y) {
	ll ans = 0;
	for (int rx, ry, l = (1 << 19); l; l >>= 1) {
		rx = (x & l) > 0, ry = (y & l) > 0;
		ans <<= 2;
		ans |= 2 * rx + (!ry);
		if (!ry) {
			if (rx) {
				x = (1 << 20) - x;
				y = (1 << 20) - y;
			}
			swap(x, y);
		}
	}
	return ans;
}
struct qq {
	int l, r, i;
	ll o;
	void get(int _i) {
		cin >> l >> r;
		l--;
		i = _i;
		o = moid(l, r);
	}
	bool operator<(const qq &rhs) const {
		return o < rhs.o;
	}
};
int n, m, k, pref[100100], cnt[1 << 20];
ll ans[100100];
ll cur = 0;
vector<qq> queries;
void add(int x) {
	if (x < 0)
		exit(33);
	cur += cnt[k ^ x];
	cnt[x]++;
}
void del(int x) {
	if (x < 0)
		exit(33);
	cnt[x]--;
	cur -= cnt[k ^ x];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(cnt, 0, sizeof cnt);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> pref[i];
		if (pref[i] > 1000000)
			exit(33);
		pref[i] ^= pref[i - 1];
	}
	queries.resize(m);
	for (int i = 0; i < m; i++)
		queries[i].get(i);
	sort(all(queries));
	int l = 1, r = 0;
	for (auto z : queries) {
		while (l < z.l)
			del(pref[l++]);
		while (l > z.l)
			add(pref[--l]);
		while (r < z.r)
			add(pref[++r]);
		while (r > z.r)
			del(pref[r--]);
		ans[z.i] = cur;
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << "\n";
}