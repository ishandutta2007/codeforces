#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define dbg(x) cerr<<#x": "<<(x)<<endl
#define dbg_p(x) cerr<<#x": "<<(x).first<<' '<<(x).second<<endl
#define dbg_v(x, n) {cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<' ';cerr<<endl;}
#define all(v) v.begin(), v.end()
#define fi first
#define se second

template<typename T1, typename T2>
ostream& operator <<(ostream &out, const pair<T1, T2> &item) {
	out << '(' << item.first << ", " << item.second << ')';
	return out;
}

template<typename T>
ostream& operator <<(ostream &out, const vector<T> &v) {
	for(const auto &item : v) out << item << ' ';
	return out;
}

const int N = 1000010;

ll c[N], p[N];
pll bit[N];
vector<int> add[N], err[N];

void update(ll price, ll c) {
	for(int p = price; p < N; p += p & (-p)) {
		bit[p].fi += c;
		bit[p].se += price * c;
	}
}

ll query(ll k) {
	int p = 0;
	ll ans = 0;

	for(int step = 20; step >= 0; --step) {
		if(p + (1 << step) >= N) continue;
		if(bit[p + (1 << step)].fi <= k) {
			ans += bit[p + (1 << step)].se;
			k -= bit[p + (1 << step)].fi;
			p += (1 << step);
		}
	}
/*
	dbg("OK");
	if(bit[p + 1].fi < k) {
		dbg(p + 1);
		dbg(k);
	}

	dbg(ans);
	dbg(1LL * (p + 1) * k);*/
	return ans + 1LL * (p + 1) * min(bit[p + 1].fi, k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n, k, m, l, r;
	ll ans;

	cin >> n >> k >> m;

	for(int i = 1; i <= m; ++i) {
		cin >> l >> r >> c[i] >> p[i];
		add[l].push_back(i);
		err[r].push_back(i);
	}

	ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(auto id : add[i]) update(p[id], c[id]);

		ans += query(k);

		for(auto id : err[i]) update(p[id], -c[id]);
	}

	cout << ans << '\n';

	return 0;
}