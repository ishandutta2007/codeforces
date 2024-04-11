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
#ifdef LOCAL
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
int n, k;
vi q, s, p, t, tp, rp;

void next(vi& v) {
	for (int i = 1; i <= n; i++)
		t[q[i]] = v[i];
	v.swap(t);
}
void rnext(vi& v) {
	for (int i = 1; i <= n; i++)
		t[i] = v[q[i]];
	v.swap(t);
}

int main() {
	doin();
	cin >> n >> k;
	t.resize(n + 1, 0);
	q.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> q[i];
	s.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	p.resize(n + 1, 0);
	tp.resize(n + 1, 0);
	rp.resize(n + 1, 0);
	for (int i = 1; i <= n; i++)
		p[i] = i, tp[i] = i, rp[i] = i;
	next(tp);
	rnext(rp);
	if (s == p)
		return cout << "NO", 0;
	int t = 0;
	while (t++ < k && s != p)
		next(p);
	t--;
	if (s == p && ((k - t) & 1) == 0 && (t == k || t > 1 || rp != s))
		return cout << "YES", 0;

	for (int i = 1; i <= n; i++)
		p[i] = i;
	t = 0;
	while (t++ < k && s != p)
		rnext(p);
	t--;
	if (s == p && ((k - t) & 1) == 0 && (t == k || t > 1 || tp != s))
		return cout << "YES", 0;
	cout << "NO";

}