#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < r; i++)

ll l[200010];

#define M 100000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, r;
	cin>>n>>r;
	ll drank = 0;
	ll over = 0;
	vector<ll> drinks;
	ll tim = 0;
	for (ll i=0;i <n; ++i) cin>>l[i];
	for (ll i=0;i <n; ++i) {
		ll t;
		cin>>t;
		if (l[i]>t) {
			cout << -1 <<'\n';
			return 0;
		}
		ll en = tim+2*l[i];

		ll cur = min(over, l[i]);
		l[i] -= cur;
		over -= cur;
		t -= cur;
		en -= cur;

		ll d = (2*l[i]-t +r-1) / r;
		if (d>0) {
			drank += d;
			over = t -2*l[i] +d*r;

			en -= (d*r-over);

			ll st = en - (d*r - over);

			while (drinks.size()!=M && d) {
				d--;
				drinks.push_back(st);
				st += r;
			}
		}
		tim = en;
	}
	cout<<drank<<endl;
	if (drank<=M) for(auto a:drinks)cout<<a<<' ';
	cout<<endl;
}