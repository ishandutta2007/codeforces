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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t; cin>>t;
	while (t--) {
		ll n; cin>>n;
		map<ll, ll> a;
		for (ll i=0; i<n; ++i) {
			ll b, d; cin>>b>>d;
			a[d]=max(a[d], b);
		}
		if (a.size()==10) {
			ll ans=0;
			for (auto o:a) ans+=o.V;
			cout<<ans<<'\n';
		} else cout<<"MOREPROBLEMS\n";
	}
}