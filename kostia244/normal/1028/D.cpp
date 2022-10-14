//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	string s;
	ll x;
	cin >> n;
	ll ans = 1;
	ll l = 0, r = 1ll<<30;
	set<ll> z;
	vi a;
	while (n--) {
		cin >> s >> x;
		if (s != "ADD") {
			if (x < l || x > r)
				return cout << 0, 0;
			if(x!=l&&x!=r) ans = (ans<<1)%mod;
			auto it = z.lower_bound(x);
			if (it == z.begin())
				l = 0;
			else {
				it--;
				l = *it;
				it++;
			}
			if (++it == z.end())
				r = 1ll<<30;
			else {
				r = *it;
			}
			z.erase(x);
		} else {
			a.pb(x);
			z.insert(x);
		}
	}

	ll t = 0;
	for(auto i : z) {
		if(i>l&&i<r) t++;
	}
	ans*=t+1;
	cout << (ans%mod) << "\n";
}