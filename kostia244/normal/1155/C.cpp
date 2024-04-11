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
//	freopen("in", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
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
ll n, m, val, tval = 0, g = 0;
vi x, p;
int main() {
	doin();
	cin >> n >> m;
	x.resize(n);
	for (auto& i : x)
		cin >> i;
	p.resize(m);
	for (auto& i : p)
		cin >> i;
	for (int i = 1; i < n; i++) {
		val = x[i - 1] - x[i];
		g = __gcd((val-tval), g);
		tval = val;
	}
	for (int i = 0; i < m; i++)
		if (g % p[i] == 0) {
			cout << "YES\n";
			cout << fixed << x[0] << " " << i + 1;
			return 0;
		}

	return cout << "NO", 0;
}