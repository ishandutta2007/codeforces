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
//  freopen("input.txt", "r", stdin);
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
int n, m, t, k, p;
ll ans = LLONG_MIN;
vi rs, cs, prs, pcs, rans, cans;

int main() {
	doin();
	cin >> n >> m >> k >> p;
	rs.resize(n, 0);
	cs.resize(m, 0);
	rans.resize(k + 1, 0);
	cans.resize(k + 1, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> t, cs[j] += t, rs[i] += t;
	priority_queue<ll> a = priority_queue<ll>(rs.begin(), rs.end());
	for (int i = 1; i <= k; i++) {
		auto t = a.top();
		rans[i] = rans[i - 1] + t;
		a.pop();
		a.push(t - p*m);
	}
	a = priority_queue<ll>(cs.begin(), cs.end());
	for (int i = 1; i <= k; i++) {
		auto t = a.top();
		cans[i] = cans[i - 1] + t;
		a.pop();
		a.push(t - p*n);
	}
	for (int i = 0; i <= k; i++) {
		ans = max(ans, cans[i] + rans[k - i] - (i * 1ll * (k - i) * 1ll * p));
	}
	cout << fixed << ans;
}