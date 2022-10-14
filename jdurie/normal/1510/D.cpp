#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin>>x;
#define F(i,l, r) for (ll i=(l); i<(r); ++i)
#define all(x) begin(x), end(x)
#define K first
#define V second

#define NN 100010

typedef pair<ld, int8_t> tp;

tp dp[NN][10];
#define DP dp[i][m]

ll a[NN];
ld la[NN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n; cin>>n;
	ll d; cin>>d;

	for (ll i=0; i<n; ++i) {
		cin>>a[i];
		la[i] = logl(a[i]);
	}

	for (ll i=0; i<=n; ++i) for (ll m=0; m<10; ++m) dp[i][m] = {INT_MIN, 0};
	dp[0][1] = {0, 0};

	for (ll i=0; i<n; ++i) {
		for (ll m=0; m<10; ++m) {
			if (DP.K==INT_MIN) continue;
			ld take = DP.K + la[i];
			ll takem = m*a[i]%10;
			dp[i+1][takem] = max(dp[i+1][takem], {take, 2*m+1});
			dp[i+1][m] =  max(dp[i+1][m], {DP.K, 2*m});
		}
	}
	ll cur = d;
	if (dp[n][cur].K==INT_MIN) {
		cout<<-1<<endl;
		return 0;
	}
	vector<ll> ans;
	for (ll i=n; i>0; --i) {
		if (dp[i][cur].V & 1) {
			ans.push_back(a[i-1]);
			cur = dp[i][cur].V/2;
		}
	}
	if (ans.empty()) {
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans.size()<<'\n';
	for (auto o:ans) cout<<o<<' ';
	cout<<endl;

}