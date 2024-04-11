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
using AntonTsypko = void;
using arsijo = AntonTsypko;
using bog = arsijo;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct query {
	ll i, t;
	pi ans = { 0, 0 };
};
ll n, q, t, mx = -1, mxt = 0;
pi ans[300001];
__V<query> qs;
deque<ll> a;
int main() {
	doin();
	cin >> n >> q;
	qs.resize(q);
	for (int i = 0; i < n; i++) {
		cin >> t, a.push_back(t);
		if (t > mx)
			mx = t;
	}
	int i = 0;
	while (a[0] != mx) {
		ll f = a.front();
		a.pop_front();
		ll t = a.front();
		a.pop_front();
		ans[++i] = {f, t};
		a.push_front(max(t, f));
		a.push_back(min(f, t));
		mxt++;
	}
	int R[300000];
	int p = 0;
	for(auto i : a)
		R[p++] = i;
	while(q--) {
		cin >> t;
		if(t <= mxt)
			cout << ans[t].first << " " << ans[t].second << "\n";
		else {
			t -= mxt;
			t%=(n-1);
			if(t == 0) t = n-1;
			cout << mx << " " << R[t] << "\n";
		}
	}
}