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
#ifdef LOCAL
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
ll n, k, t, r, s = 0, l = n, p = 0, bannum, bancnt, lvl = 0, f[100005];
map<ll, ll> cnt;
vpi a;
int main() {
	doin();
	cin >> n >> k;
	for (ll i = 1; i <= n; i++)
		cin >> t, f[i] = t, a.pb( { t, i }), cnt[t]++, s += t;
	if (s == k)
		return 0;
	l = n;
	for (auto i : cnt) {
		t = i.first;
		ll TMP = i.first - p;
		if (TMP * l <= k) {
			k -= TMP * l;
			l -= i.second;
		} else {
			ll made = p + (k / l) + 1;
			t = k % l;
			list<ll> b;
			for (auto j : a) {
				if (j.first >= i.first)
					b.pb(j.second);
			}
			while (t--) {
				if (f[b.front()] > made)
					b.pb(b.front());
				b.pop_front();
			}
			for (auto k : b)
				cout << k << " ";
			return 0;
		}
		p = t;
	}
	cout << -1;
}