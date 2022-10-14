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
int n, m, x, y, mid = 0, mx = 0;
vpi range, b;
int main() {
	doin();
	cin >> n >> m;
	while (m--) {
		cin >> x >> y;
		b.pb( { x, y });
	}
	sort(all(b));
	int l = 0, r, px = 0, F =0;
	vpi p { { 1, 1 } }, np;
	while (l < b.size()) {
		if (b[l].first != px + 1 && !p.empty()) {
			int lo = p.front().first;
			p.clear();
			p = { {	lo, n}};
		}
		px = b[l].first;
		r=l;
		while(r < b.size() && b[l].first == b[r].first) r++;
		int pp = 0, ls = 1;
		for(int L = l; L <= r; L++) {
			int e = (L!=r?b[L].second:n+1);
			while(pp < p.size() && p[pp].second < ls) pp++;
			if(pp < p.size() && max(ls, p[pp].first) < e)
				np.pb( {	max(ls, p[pp].first), e-1});
			ls = e+1;
		}
		p = np;
		np.clear();
		l=r;
	}
	if((px != n && !p.empty()) || p.back().second == n)
		cout << 2*n-2;
	else
		cout << -1;

}