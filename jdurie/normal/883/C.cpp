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

ll f, T;
ll t[5], a[5], p[5];
ll totp[5];


long long int calc(ll one, ll two) {
	ll mo = (T + totp[one]-1)/(totp[one]); 
	long long int ans = LLONG_MAX;
	for (ll i=0; i<=mo; ++i) {
		ll fone = min(totp[one]*i, T);
		ll bytes = fone/t[one];
		ll tim = T - fone;
		ll b = f - bytes;

		if (tim/t[two] < b) continue;

		if (t[0] <= t[two] or tim/t[0] >= b) {
			if (tim/t[0] >= b) ans = min(ans, i*((long long int)p[one]));
			continue;
		}
		// k*t2 + (b-k)*t0 <= tim
		ll k =(-tim + b * t[0] + (t[0] - t[two]-1)) / (-t[two]+t[0]);
		/*if (i == 1) {
			cout << "k: " << k << endl;
			cout << one << " " << two << endl;
			cout << "tim: " << tim << endl;
			cout << "bytes: " << b << endl;
		}*/
		ll cost = p[two] * ((k + a[two] - 1) / a[two]);
		if (k * t[two] + (b - k) * t[0] <= tim)
			ans = min(ans, i * ((long long int)p[one]) + cost);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>f>>T>>t[0];
	a[0] = 1;
	p[0] = 0;
	cin>>a[1]>>t[1]>>p[1];
	cin>>a[2]>>t[2]>>p[2];
	totp[0] = min((long long int) 10*T, ((long long int)a[0])*t[0]);
	totp[1] = min((long long int) 10*T, ((long long int)a[1])*t[1]);
	totp[2] = min((long long int) 10*T, ((long long int)a[2])*t[2]);
	ll one = t[1]<t[0] ? 1 : 0;
	ll two = t[2]<t[0] ? 2 : 0;
	//if (t[one]<t[two]) swap(one, two);
	long long int ans = min(calc(one, two), calc(two, one));
	if (ans==LLONG_MAX) cout<<-1<<endl;
	else cout<<ans<<endl;
}