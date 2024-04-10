#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second

#define NN 210
pl dp[NN][NN];
#define DP dp[i][j]

ll ps[NN][NN], c[NN][NN];

// ab is first axis, cd is second axis
ll q(ll a, ll b, ll c, ll d) {
	return ps[b][d] + ps[a][c] - ps[b][c] - ps[a][d];
}

ll n;
pl r(ll i, ll j) {
	if (~DP.K) return DP;
	
	if (i>j) return {0, -1};
	ll pass_up = q(0, i, i, j+1) + q(j+1, n, i, j+1);

	DP = {LLONG_MAX, -1};

	for (ll k=i; k<=j; ++k) {
		ll cur = pass_up+r(i, k-1).K+r(k+1, j).K;
		if (cur<DP.K) {
			DP = {cur, k};
		}
	}
	return DP;
}

ll p[NN];
void dfs(ll i, ll j, ll pa) {
	ll k=dp[i][j].V;
	if (k==-1) return;
	p[k] = pa;
	if (i!=k) dfs(i, k-1, k);
	if (i!=j) dfs(k+1, j, k);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof dp);

	cin>>n;
	for (ll i=0; i<n; ++i)
		for (ll j=0; j<n; ++j) cin>>c[i][j];

	for (ll i=0; i<n; ++i) {
		for (ll j=0; j<n; ++j) {
			ps[i+1][j+1] = ps[i][j+1] + ps[i+1][j] - ps[i][j] + c[i][j];
		}
	}

	r(0, n-1);
	dfs(0, n-1, -1);
	for (ll i=0; i<n; ++i) cout<<p[i]+1<<' ';
	cout<<endl;
}