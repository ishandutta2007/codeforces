#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCALc
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct bus {
	ll s, e;
};
ll n, m, pref[100100], dp[100100], pos[100100], ans = 0;
__V<bus> a;

int main() {
	doin();
	cin >> n >> m;
	a.resize(m);
	for(auto& i : a) cin >> i.s >> i.e;
	sort(all(a), [](const bus& a, const bus& b) {
		return a.e < b.e;
	});
	for (int i = 0; i < m; i++) {
		bus tmp;
		tmp.e = a[i].s;
		auto it = lower_bound(all(a), tmp, [](const bus& a, const bus& b) {
			return a.e < b.e;
		});
		tmp.e = a[i].e;
		auto it2 = lower_bound(all(a), tmp, [](const bus& a, const bus& b) {
			return a.e < b.e;
		});
		if (it != a.end() && it2 >= a.begin()) {
			it2--;
			int pos = it-a.begin();
			int pos2 = it2-a.begin();
			dp[i] = (mod + pref[pos2] - (pos ? pref[pos-1] : 0)) % mod;
		}
		if (a[i].s == 0)
			dp[i]++;
		if(a[i].e == n) (ans += dp[i])%=mod;
		(pref[i] += dp[i]) %= mod;
		(pref[i + 1] += pref[i]) %= mod;
	}
	cout << ans;
}