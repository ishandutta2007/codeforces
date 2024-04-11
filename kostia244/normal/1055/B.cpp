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
#define mod 1234567891ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//		freopen("in", "r", stdin);
//		freopen("out", "w", stdout);
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

struct ufds {
	vi r, p, t;
	int zs, ns;
	ufds(int n) {
		ns = zs = n;
		r.resize(n + 1, 0);
		t.resize(n + 1, 0);
		p.resize(n + 1, 0);
		for (int i = 1; i <= n; i++)
			p[i] = i;
	}
	int par(int i) {
		if (p[i] == i)
			return i;
		return p[i] = par(p[i]);
	}
	void u(int i, int j) {
		l(i), l(j);
		int x = par(i), y = par(j);
		if(x == y)
			return;
		ns--;
		if(r[x] > r[y])
			p[y] = x;
		else {
			p[x] = y;
			if(r[y] == r[x])
				r[y]++;
		}
	}

	void l(int i) {
		if(t[i]) return;
		t[i] = 1;
		zs--;
	}

	int ans() {
		return ns-zs;
	}
};

int n, m, l, g[100001], t, i;
vi a;
int main() {
	doin();
	cin >> n >> m >> l;
	ufds x(n);
	getv(a, n);
	for(int i = 0; i < n; i++) a[i] -= l;
	if(a[0] > 0)
				x.l(0);
	for(int i = 1; i < n; i++) {
		if(a[i] > 0 && a[i-1] > 0)
			x.u(i, i-1);
		else if(a[i] > 0)
			x.l(i);
	}
	while(m--) {
		cin >> t;
		if(t == 0)
			cout << x.ans() << "\n";
		else {
			cin >> i >> t;
			a[--i]+=t;
			if(a[i] <= 0)
				continue;
			x.l(i);
			if(i && a[i] > 0 && a[i-1] > 0)
				x.u(i, i-1);
			if(i+1<n && a[i] > 0 && a[i+1] > 0)
				x.u(i, i+1);
		}
	}
}