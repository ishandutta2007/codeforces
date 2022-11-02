#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 500005, L = 524288, inf = 1e18;
ll n, cs, a[N], s[N], mn[N], mx[N];
vector<ll> ans;

struct segtree {
	ll v[2*L];
	void upd (ll I, ll V) {
		I += L;
		while(I) {
			v[I] += V;
			I /= 2;
		}
	}
	ll get (ll S, ll E) {
		S += L; E += L;
		ll R = 0;
		while(S <= E) {
			if(S%2 == 1) R += v[S++];
			if(E%2 == 0) R += v[E--];
			S /= 2; E /= 2;
		}
		return R;
	}
} seg;

ll firstlower (ll I, ll V) {
	ll S = I, E = N+1;
	while(S<E) {
		ll M = (S+E)/2;
		a[M] < V ? E = M : S = M+1;
	}
	return S;
}

ll getval (ll I, ll V) {
	ll J = firstlower(I, V);
	return V * (J - I) + seg.get(J, n);
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		cs = (cs + a[i]) % 2;
	}
	sort(a+1, a+1+n);
	reverse(a+1, a+1+n);
	for(ll i=1;i<=n;i++) {
		seg.upd(i, a[i]);
		s[i] = s[i-1] + a[i];
	}
	for(ll i=1;i<=n;i++) {
		mn[i] = s[i] - i*(i-1) - getval(i+1, i);
		if(mn[i] > i) mn[i] = inf;
	}
	for(ll i=1;i<=n;i++) {
		mx[i] = i*(i-1) + getval(i, i) - s[i-1];
	}
	for(ll i=2;i<=n;i++) {
		mn[i] = max(mn[i], mn[i-1]);
	}
	for(ll i=n-1;i>=1;i--) {
		mx[i] = min(mx[i], mx[i+1]);
	}
	mx[n+1] = inf;
	a[0] = n+1;
	for(ll i=n;i>=0;i--) {
		ll S = max(mn[i], a[i+1]), E = min(mx[i+1], a[i]-1);
		for(ll j=S;j<=E;j++) {
			if(j%2 != cs) continue;
			ans.push_back(j);
		}
	}
	if((ll)ans.size() == 0) {
		puts("-1");
		return 0;
	}
	for(auto &T : ans) {
		printf("%lld ", T);
	}
}