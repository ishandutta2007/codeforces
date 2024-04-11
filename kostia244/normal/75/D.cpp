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
ll n, m, bestsum = LLONG_MIN, dp[300100], arr[6000], arri = 0, l;
struct {
	ll sum, bestpref, bestsuf, sz, bs;
} arrs[60];

void investigate() {
	ll mx, cur = 0, sum = 0, prefsum = 0, bestpref, bestsuf;
	bestpref = bestsuf = mx = LLONG_MIN;
	for(ll i = 0; i < l; i++) {
		sum += arr[i];
		cur += arr[i];
		if(cur > mx) mx = cur;
		if(cur < 0) cur = 0;
	}
	if(bestsum < mx)
		bestsum = mx;
	arrs[arri].sum = sum;
	arrs[arri].sz = l;
	arrs[arri].bs = mx;
	for(ll i = 0; i < l; i++) {
		prefsum += arr[i];
		if(bestpref < prefsum)
			bestpref = prefsum;
		if(bestsuf < sum)
			bestsuf = sum;
		sum -= arr[i];
	}
	arrs[arri].bestpref = bestpref;
	arrs[arri].bestsuf = bestsuf;
	arri++;
}

int main() {
	doin();
	cin >> n >> m;
	while(n--) {
		cin >> l;
		for(ll i = 0; i < l; i++) cin >> arr[i];
		investigate();
	}
	ll mx = LLONG_MIN, cur = 0;
	for(int i = 0; i < m; i++) {
		cin >> l, l--;
		mx = max(mx, cur+arrs[l].bestpref);
		cur = max(cur+arrs[l].sum, arrs[l].bestsuf);
		mx = max(mx, cur);
		if(cur < 0) cur = 0;
		mx = max(mx, arrs[l].bs);
	}
	cout << fixed << mx << "\n";
}