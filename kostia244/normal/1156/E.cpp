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
		cin >> i, f(i);
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
int n, pos[200007], sparse[19][200005], logg[200005], p = 0;
vi a;
set<pi> s;
void sparsebuild() {
	int t = -1;
	for (int i = 1; i <= n; i++)
		logg[i] = (i & -i) == i ? ++t : t;
	for (int l = 0; (1 << l) <= n; l++) {
		for (int i = 0; i < n; i++) {
			sparse[l][i] = (
					l == 0 ?
							a[i] :
							max(sparse[l - 1][i],
									(i + (1 << (l - 1))) < n ?
											sparse[l - 1][i + (1 << (l - 1))] :
											0));
		}
	}
}

int sparsemax(int i, int j) {
	int k = logg[j - i];
	return max(sparse[k][i], sparse[k][j - (1 << k)]);
}

int g(int l, int r, int lb, int ub, int c) {
	int ans = 0, inv;
	for (; l < r; l++) {
		inv = c - a[l];
		if (pos[inv] >= lb && pos[inv] < ub)
			ans++, s.insert( { min(l, pos[inv]), max(l, pos[inv]) });
	}
	return ans;
}

int f(int i, int j) {
	if (j - i < 3)
		return 0;
	int mx = sparsemax(i, j), x, y;
	p = pos[mx];
	if (p - i < j - p - 1)
		y = g(i, p, p + 1, j, mx);
	else
		y = g(p + 1, j, i, p, mx);
	return y + f(i, p) + f(p + 1, j);
}

int main() {
	doin();
	cin >> n;
	getv(a, n, [p](int& i) {
		pos[i] = p++;
	});
	sparsebuild();
	f(0, n);
	cout << s.size();
}