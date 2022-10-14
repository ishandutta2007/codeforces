#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pl;
typedef long double ld;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < r; i++)

#define N 110

ll n, dp[N][N], d[N];
vector<pl> pos, neg;
vector<pl> cur[N][N];

void so(vector<pl> &old) {
	sort(old.begin(), old.end(), [](pl a, pl b) {if (a.first==b.first) return a.second<b.second; return a.first>b.first;});
}

ll loc(const vector<pl> &a, ll v) {
	for (ll k=0; k<a.size(); ++k) if (a[k].second==v) return k;
}

#define DP dp[i][j]
ll r(ll i, ll j) {
	if (~DP) return DP;

	DP = 0;
	if (i<pos.size()) {
		vector<pl> old = cur[i][j];
		ll p = loc(old, pos[i].second);
		old[p].first += d[pos[i].second];
		so(old);
		ll af = loc(old, pos[i].second);
		ll del = abs(af-p);
		cur[i+1][j] = old;
		DP = max(DP, r(i+1, j)+del);
	}
	if (j<neg.size()) {
		vector<pl> old = cur[i][j];
		ll p=  loc(old, neg[j].second);
		old[p].first += d[neg[j].second];
		so(old);
		ll af=loc(old, neg[j].second);
		ll del = abs(af-p);
		cur[i][j+1] = old;
		DP = max(DP, r(i, j+1)+del);
	}
	//cout<<i<<' '<<j<<": "<<DP<<endl;
	return DP;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(dp, -1, sizeof dp);
	F(i, 0, n) {
		ll a;
		cin>>a>>d[i];
		if (d[i]<0) neg.push_back({a, i});
		else pos.push_back({a, i});
		cur[0][0].push_back({a, i});
	}
	so(pos);
	reverse(pos.begin(), pos.end());
	so(neg);
	so(cur[0][0]);
	cout<<r(0, 0)<<endl;
}