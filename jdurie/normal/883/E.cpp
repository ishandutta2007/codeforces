#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define F(i, l, r) for(ll i = l; i < (r); i++)
#define G(x) ll x; cin >> x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll m;
	cin>>m;
	vector<string> words;
	for (ll i=0;i<m; ++i) {
		string w;
		cin>>w;
		for (ll j=0; j<n; ++j) {
			if (s[j]!='*' && s[j]!=w[j]) goto fail;
			if (s[j]=='*') {
				if (count(s.begin(), s.end(), w[j])) goto fail;
			}
		}

		words.push_back(w);
		fail:;
	}
	ll ans = 0;
	for (char c='a'; c<='z'; ++c) {
		if (count(s.begin(), s.end(), c)) continue;
		for (auto w:words) if (count(w.begin(), w.end(), c)==0) goto fal;
		ans++;
		fal:;
	}
	cout<<ans<<endl;
}