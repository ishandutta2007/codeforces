#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
const int MAXN = (1 << 20);
const int MAXLOG = 20;

struct sparse_table
{
	int dp[MAXN][MAXLOG];
	int prec_lg2[MAXN], n;

	sparse_table() { memset(dp, 0, sizeof(dp)); memset(prec_lg2, 0, sizeof(prec_lg2)); n = 0; }

	void init(vector<int> &a)
	{
		n = a.size();
		for(int i = 2; i < 2 * n; i++) prec_lg2[i] = prec_lg2[i >> 1] + 1;
		for(int i = 0; i < n; i++) dp[i][0] = a[i];
		for(int j = 1; (1 << j) <= n; j++)
			for(int i = 0; i < n; i++)
				dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	}

	int query(int l, int r)
	{
		int k = prec_lg2[r - l + 1];
		return max(dp[l][k], dp[r - (1 << k) + 1][k]);
	}
};

sparse_table x;
ll n, m;
vi mo;
vector<pair<ll, ll>> he;

bool can(ll cur, ll l) {
	if(cur+l>n) return false;
	auto it = lower_bound(all(he), pair<ll, ll>{l, -1});
	if(it==he.end()) return false;
	return (it->second) >= x.query(cur, cur+l-1);
}

void solve() {
	cin >> n;
	mo.clear();
	mo.resize(n);
	for(auto &i : mo) cin >> i;
	x.init(mo);
	cin >> m;
	he.clear();
	for(ll p, s, i = 0; i < m; i++) {
		cin >> p >> s;
		he.pb({s, p});
	}
	sort(all(he));
	for(int i = (int)he.size()-2; i >= 0; i--) {
		he[i].second = max(he[i].second, he[i+1].second);
	}
	ll ans = 0, k = 0;
	while(k < n) {
		ll adv = 0;
		for(int a = 1<<17; a; a>>=1)
			if(can(k, adv+a))adv+=a;
		k +=adv;
		if(adv==0) {
			cout << "-1\n";
			return;
		}
		ans++;
	}
	cout << ans << "\n";
}
int main() {
	 ios::sync_with_stdio(0);
	 cin.tie(0);
	 cout.tie(0);
	 ll t;
	 cin >> t;
	 while(t--) solve();
	 return 0;
}