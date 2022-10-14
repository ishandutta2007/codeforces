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
const int sq = 450, maxn = 1<<20;
long long get(int x, int y)
{
	long long d = 0;
	for (int s = 1 << 19; s; s >>= 1)
	{
		bool rx = x & s, ry = y & s;
		d = d << 2 | rx * 3 ^ static_cast<int>(ry);
		if (!ry)
		{
			if (rx)
			{
				x = maxn - x;
				y = maxn - y;
			}
			swap(x, y);
		}
	}
	return d;
}
struct qq {
	int l, r, i;
	ll o;
	qq(int _l, int _r, int _i) {
		l=_l, r=_r,i = _i;
		o = get(l, r);
	}
	bool operator<(const qq& r) const {
		return o<r.o;
	}
};
ll n, q, a[200100], freq[1000200], res[200200];
vector<qq> queries;

ll f(ll c) {
	return freq[c]*freq[c]*c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int l, r, i = 0; i < q; i++) {
		cin >> l >> r;
		queries.emplace_back(l, r, i);
	}
	memset(freq, 0, sizeof freq);
	sort(all(queries));
	int l = 1, r = 0;
	ll ans = 0;
	for(auto z : queries) {
		while(l < z.l) {
			ans -= f(a[l]);
			freq[a[l]]--;
			ans += f(a[l]);
			l++;
		}
		while(l > z.l) {
			l--;
			ans -= f(a[l]);
			freq[a[l]]++;
			ans += f(a[l]);
		}
		while(r < z.r){
			r++;
			ans -= f(a[r]);
			freq[a[r]]++;
			ans += f(a[r]);
		}
		while(r > z.r) {
			ans -= f(a[r]);
			freq[a[r]]--;
			ans += f(a[r]);
			r--;
		}
		res[z.i]=ans;
	}
	for(int i = 0; i < q; i++) cout << res[i] << "\n";
}