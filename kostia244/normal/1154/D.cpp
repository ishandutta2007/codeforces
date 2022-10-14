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
int n, b, a, ma, mb;
vi v;
int main() {
	doin();
	cin >> n >> mb >> ma;
	a = ma, b = mb;
	v.resize(n);
	for (auto& i : v)
		cin >> i;
	for (int i = 0; i < n; i++) {
		if (a + b == 0) {
			cout << i;
			return 0;
		}
		if (v[i]) {
			if (b > 0 && a < ma) {
				b--;
				a = min(a + 1, ma);
			} else if (a > 0) {
				a--;
			} else {
				cout << i;
				return 0;
			}
		} else {
			if (a > 0) {
				a--;
			} else if (b > 0) {
				b--;
			} else {
				cout << i;
				return 0;
			}
		}
	}
	cout << n;
	return 0;
}