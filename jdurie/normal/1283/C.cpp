#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
const ll NN = 200010;

set<ll> avail;
ll f[NN], lst[NN], dsu[NN];

ll d(ll i) { return dsu[i] == i ? i : dsu[i] = d(dsu[i]); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n; cin >> n;
	for(ll i = 1; i <= n; i++) {
		avail.insert(i);
		dsu[i] = lst[i] = i;
	}
	for(ll i = 1; i <= n; i++) {
		cin >> f[i];
		if(f[i]) {
			avail.erase(i);
			avail.erase(f[i]);
			ll S = d(i), T = d(f[i]);
			dsu[T] = S;
			lst[S] = lst[T];
		}
	}
	for(ll i = 1; i <= n; i++)
		if(dsu[i] == i && !f[lst[i]] && lst[i] != i)
			if(avail.size() == 1) {
				ll a = *avail.begin();
				f[a] = i;
				f[lst[i]] = a;
				avail.clear();
			} else f[lst[i]] = i; 
	ll lt = 0, ft = -1;
	for(ll a : avail) {
		if(lt) f[lt] = a;
		else ft = a;
		lt = a;
	}
	f[lt] = ft;
	for(ll i = 1; i <= n; i++)
		cout << f[i] << " ";
	cout << endl;
}