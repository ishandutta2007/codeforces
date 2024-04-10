#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string t;
int n;

void mx(ll& x, ll y) {
	x = max(x, y);
}

bool moze(ll p) {
	ll q = -p;
	p = 100'000'000 - p;

	ll d0 = 0, d1 = -1e18;
	for (char k : t) { // koliko sam vec stavio
		ll n0, n1;
		if (k < 2) {
			n0 = max(d0+q+(k?q:p), d1+(k?p:q));
			n1 = max(d1+q+(k?p:q), d0+(k?q:p));
		} else {
			n0 = max(d0+q+q, d1+q);
			n1 = max(d1+q+q, d0+q);
		}

		d0 = n0;
		d1 = n1;
	}

	// append X?
	return max(d0, d1 + q) >= 0;
}

ll odd() {
	ll a = n - count(t.begin(), t.end(), char(2));
	return a * 50'000'000 / (n + (n+1) % 2);
}

ll resi_sve() {
	n = t.size();

	ll lo = 1, hi = 100'000'000, o = 0;
	while (lo <= hi) {
		ll mid = (lo+hi) >> 1;
		if (moze(mid)) {
			o = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	// odd?
	o = max(o, odd());

	return o;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	for (char c : s) {
		if (c == 'L')
			c = 0;
		else if (c == 'R')
			c = 1;
		else
			c = 2;
		if (t.size() && t.back() < 2 && t.back() == c)
			t += char(2);
		t += c;
	}
	
	ll o = -1;
	if (t[0] == t.back() && t[0] < 2) {
		// moras da dodas jednog napred ili nazad
		t += char(2);
		o = resi_sve();
		t.pop_back();
		t = string(1, 2) + t;
		o = max(o, resi_sve());
	} else {
		// ne moras da dodajes nista
		o = resi_sve();
		t = string(1, 2) + t;
		o = max(o, resi_sve());
	}

	cout << setprecision(6) << fixed << ld(o)/1e6 << '\n';
}

// RXRXXRXRLXXRLXLXLXLXLXLXLXXLXRXRXRXRXLRXRLRLXXLXLXLXLXXRXLRLXLRXRXRXRXRLXLXRXRLRLXLRLRXRXRLXLRXRXRXRL