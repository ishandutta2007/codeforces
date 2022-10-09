#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

void ss(int& l, int& r, int t) {
	int l2 = t - r;
	int r2 = t - l;
	l = l2;
	r = r2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int la, ra, ta, lb, rb, tb;
	cin >> la >> ra >> ta >> lb >> rb >> tb;

	ra++;
	rb++;

	// |A| <= |B|

	if (ra-la > rb-lb) {
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}

	int mod = gcd(ta, tb);
	int x = ((la - lb) % mod + mod) % mod;
	int sol = max(0, min(ra-la, rb-lb-x));

	ss(la, ra, ta);
	ss(lb, rb, tb);

	x = ((la - lb) % mod + mod) % mod;
	sol = max(sol, min(ra-la, rb-lb-x));

	cout << sol << '\n';
}