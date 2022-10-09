// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct seg {
	int l, r, id;
	template<class T>
	auto operator< (const T& b) const {
		return r < b.r;
	}
};

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
seg a[200005];
int u[400005], ans[200005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].l >> a[i].r;
		u[2*i] = a[i].l;
		u[2*i+1] = a[i].r;
		a[i].id = i;
	}
	int m = 2*n;
	sort(u, u+m);

	for (int i=0; i<n; i++) {
		a[i].l = lower_bound(u, u+m, a[i].l) - u;
		a[i].r = lower_bound(u, u+m, a[i].r) - u;
	}

	sort(a, a+n);

	fenwick d(2*n-1, 0);

	for (int i=0; i<n; i++) {
		ans[a[i].id] = i - d(a[i].l);
		d.add(a[i].l, 1);
	}

	for (int i=0; i<n; i++)
		cout << ans[i] << '\n';
}