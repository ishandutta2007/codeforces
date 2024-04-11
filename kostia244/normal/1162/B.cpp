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
//		freopen("in", "r", stdin);
//		freopen("out", "w", stdout);
#endif
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef long long ll;
typedef double ld;
typedef int _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, h, m, l, r, c, ans = 0;
int main() {
	doin();
	cin >> n >> m;
	vvi a(n, vi(m)), b(n, vi(m));
	for (auto& i : a)
		for (auto& j : i)
			cin >> j;
	for (auto& i : b)
		for (auto& j : i)
			cin >> j;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			l = a[i][j], r = b[i][j];
			a[i][j] = min(l, r);
			b[i][j] = max(l, r);
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if((i && a[i][j] <= a[i-1][j]) ||(j && a[i][j] <= a[i][j-1]))
				return cout <<"Impossible", 0;
			if((i && b[i][j] <= b[i-1][j]) || (j && b[i][j] <= b[i][j-1]))
				return cout <<"Impossible", 0;
		}
cout << "Possible";
}