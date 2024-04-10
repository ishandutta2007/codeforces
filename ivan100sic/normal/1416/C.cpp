// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct fenwick {
	vector<T> a;
	T e;
	F f;

	fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

	void add(int p, const T& v) {
		for (p++; p <= (int)a.size(); p += p & -p)
			a[p-1] = f(a[p-1], v);
	}

	T operator() (int p) const {
		T v = e;
		for (; p; p -= p & -p)
			v = f(v, a[p-1]);
		return v;
	}
};

int n;
int a[300005];

ll invs(int mask) {
	vector<pair<int, int>> b(n);
	for (int i=0; i<n; i++) {
		b[i] = {a[i] ^ mask, i};
	}

	sort(begin(b), end(b));

	ll sol = 0;
	fenwick d(n+1);

	for (int i=0; i<n; i++) {
		sol += i - d(b[i].second);
		d.add(b[i].second, 1);
	}

	return sol;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	int mask = 0;
	ll ol = invs(mask);
	for (int j=29; j>=0; j--) {
		ll nu = invs(mask ^ (1 << j));
		if (nu < ol) {
			mask ^= 1 << j;
			ol = nu;
		}
	}

	cout << invs(mask) << ' ' << mask << '\n';
}