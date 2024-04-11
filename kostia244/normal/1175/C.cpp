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
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
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
ll t, n, k, a[201001];
ll f(ll x) {
	vi t;
	for (int i = 0; i < n; i++)
		t.pb(abs(a[i] - x));
	sort(all(t));
	return t[k];
}
int main() {
	doin();
	cin >> t;
	while (t--) {
		ll s = 0, tm, m = LLONG_MAX, an = 0;
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i];
		for (int i = k; i < n; i++) {
			s = (a[i-k]+a[i])/2;
			tm = max(s-a[i-k], a[i]-s);
			if(tm < m)
				an = s, m = tm;
			s++;
			tm = max(s-a[i-k], a[i]-s);
			if(tm < m)
				an = s, m = tm;
		}
		cout << an << "\n";
	}
}