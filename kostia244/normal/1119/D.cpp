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
ll n, q, l, r;
vi s, diff, sum;

ll ans(ll l, ll r) {
	ll gap = r-l+1;
	if(n == 1)
		return gap;
	auto it = lower_bound(all(diff), gap);
	if(it == diff.end())
		return sum.back()+gap;
	int nless = it-diff.begin();
	return (nless ? sum[nless-1] : 0) + (n-nless)*gap;
}

int main() {
	doin();
	cin >> n;
	getv(s, n);
	sort(all(s));
	diff.resize(n);
	adjacent_difference(all(s), diff.begin());
	diff = vi(diff.begin()+1, diff.end());
	sort(all(diff));
	sum.resize(n-1);
	partial_sum(all(diff), sum.begin());
	cin >> q;
	while(q--) {
		cin >> l >> r;
		cout << ans(l, r) << " ";
	}
}