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
typedef int _I;
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
int n, ans = 0, cnt[400010];
vi a, b;

void y() {
	for (int i = 0; i < n; i++)
		cnt[a[i]]++;
	if (cnt[1])
		return;
	for (int i = find(all(b), 1)-b.begin(); i + 1 < n; i++)
		if (b[i] + 1 != b[i + 1])
			return;
	int p = b.back(), f = 0;
	while(p++ < n) {
		if(!cnt[p])
			return;
		cnt[b[f++]]++;
	}
	ans = f-n;
}

int main() {
	doin();
	cin >> n;
	getv(a, n);
	getv(b, n);
	for (int i = 0; i < n; i++)
		if(b[i])
		ans = max(i - b[i]+2, ans);
	y();
	cout << ans+n;
}