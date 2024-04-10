#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int main() {
	ll a, b, c, L;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &L);
	ll res = 0;
	for (ll l = 0; l <= L; l++) {
		ll x = (a+b+c+l+1)/2;
		ll ah = x-a-1, bh = x-b-1, ch = x-c-1;
		if (ah < 0 || bh < 0 || ch < 0) continue;
		ll abl = l-ch;
		vector<ll> v;
		v.push_back(0);
		v.push_back(l);
		v.push_back(l-ah);
		v.push_back(l-bh);
		v.push_back(l-ch);
		v.push_back(l-ah-bh);
		v.push_back(l-ah-ch);
		v.push_back(l-bh-ch);
		v.push_back(l-ah-bh-ch);
		v.push_back(ah);
        int len = sz(v);
        FO(i,0,len) v.push_back(v[i]+1);
        FO(i,0,len) v.push_back(v[i]-1);
		sort(v.begin(),v.end());
		FO(i,0,sz(v)-1) {
			ll s = v[i], e = v[i+1]-1;
			if (s > e) continue;
			if (s < 0) continue;
			if (s > ah) continue;
			ll first = min(bh, l-s) - max(0ll,abl-s) + 1;
			ll last = min(bh, l-e) - max(0ll,abl-e) + 1;
			first = max(first,0ll);
			last = max(last,0ll);
			res += (e-s+1) * (first + last) / 2;
		}
	}
	printf("%lld\n", res);
}