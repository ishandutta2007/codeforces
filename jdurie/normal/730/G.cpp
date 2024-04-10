#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < r; i++)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	G(n)
	vector<ll> s, d;
	F(i,0,n) { 
		G(S) G(D)
		s.push_back(S);
		d.push_back(D);
	}
	set<pair<ll, ll>> done;
	map<ll, ll> ans;
	F(i,0,n) {
		if (!i) { done.insert({s[i], d[i]}); ans[i] = s[i]; continue; }
		auto next = done.lower_bound({s[i], -1});
		bool ok = true;
		if (next != done.end())
			ok &= s[i] + d[i] - 1 < next->first;
		if (next != done.begin()) {
			next--;
			ok &= next->first + next->second -1 < s[i];
		}
		if (ok) {
			done.insert({s[i], d[i]}); ans[i] = s[i]; continue; 
		}
		if (d[i] < done.begin()->first - 1) {
			done.insert({1, d[i]}); ans[i] = 1; continue;
		}
		ll F=-1, S=-1;
		for (auto g : done) {
			auto next = done.upper_bound(g);
			
			if (next == done.end() or g.first + g.second + d[i] - 1 < (*next).first) {
				F = g.first+g.second; break;
			}
			
		}
		if (~F) { done.insert({F, d[i]}); ans[i] = F; }
	}	
	F(i,0,n) cout << ans[i] << " " << ans[i] + d[i] - 1 << '\n';
}