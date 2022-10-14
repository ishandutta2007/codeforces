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
typedef int _I;
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
ll n[3], t[] = { 0, 1, 2, 0, 2, 1, 0 };
ll ans = 0;
vi a;

ll suff(ll n[3]) {
	for (int i = 0; i < 7; i++)
		if (n[t[i]]-- < 1)
			return i;
	return 7;
}

ll bt(ll p, ll n[3]) {
	for (ll i = p; i < 7; i++)
		if (n[t[i]]-- < 1)
			return i - p;
	ll tmp = min( { n[0] / 3, n[1] / 2, n[2] / 2 });
	n[0] -= tmp * 3;
	n[1] -= tmp * 2;
	n[2] -= tmp * 2;
	return (7-p)+(tmp*7)+suff(n);
}

int main() {
//	doin();
//	cout << int(upper_bound(all(a), 5)-a.begin());
	ll tn[3];
	cin >> tn[0] >> tn[1] >> tn[2];
	ll a = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++)
			n[j] = tn[j];
		a = max(a, bt(i, n));
	}
	cout << fixed << a;
}