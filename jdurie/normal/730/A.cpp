#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < r; i++)

ll r[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin>>n;
	for (ll i=0; i<n; ++i) {
		cin>>r[i];
	}
	for (ll R=100; R>=0; --R) {
		set<pair<ll, ll>> ops;
		map<ll, ll> look;
		ll su = 0;
		vector<string> ans;
		for (ll i=0; i<n; ++i) {
			if(r[i]<R) goto fail;
			if (R!=r[i]) look[i]+=r[i]-R;
		}

		for (auto o:look) {
			su+=o.second;
			ops.insert({o.second, o.first});
		}

		#define op(x, y, z) {string s; \
			for (ll j=0; j<n; ++j) s+= (j==x || j==y || j==z) ? '1' : '0'; \
			ans.push_back(s);}
		if (R==0) {
			while (look.size()) {
				ll a = look.begin()->first;
				ll b = a==0? 1 : 0;
				look[a]--;
				if (look[a]==0) look.erase(a);
				if (look.count(b)) {look[b]--; if (look[b]==0) look.erase(b);}
				op(a, b, -1);
			}
			su=0;
		}

		while (su) {
			if (su==1) goto fail;
			if (ops.size()<2) goto fail;
			if (su%2) {
				if (ops.size()<3) goto fail;
				ll a = ops.rbegin()->second;
				ops.erase(*ops.rbegin());
				ll b = ops.rbegin()->second;
				ops.erase(*ops.rbegin());
				ll c = ops.rbegin()->second;
				ops.erase(*ops.rbegin());
				look[a]--;
				look[b]--;
				look[c]--;
				if (look[a]) ops.insert({look[a], a});
				if (look[b]) ops.insert({look[b], b});
				if (look[c]) ops.insert({look[c], c});
				op(a, b, c)
				su-=3;
			} else {
				if (ops.size()<2) goto fail;
				ll a = ops.rbegin()->second;
				ops.erase(*ops.rbegin());
				ll b = ops.rbegin()->second;
				ops.erase(*ops.rbegin());
				look[a]--;
				look[b]--;
				if (look[a]) ops.insert({look[a], a});
				if (look[b]) ops.insert({look[b], b});
				op(a, b, -1)
				su -= 2;
			}
		}
		cout<<R<<'\n';
		cout<<ans.size()<<'\n';
		for (auto a:ans)cout<<a<<'\n';
		break;


		fail:;
	}
}