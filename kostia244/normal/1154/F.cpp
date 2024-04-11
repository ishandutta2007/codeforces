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
ll n, m, k, aa, b;
vi a, dp, sum;
mii o;
int main() {
	doin();
//	cout << int(upper_bound(all(a), 5)-a.begin());
	cin >> n >> m >> k;
	a.resize(n);
	dp.resize(n);
	for (auto& i : a)
		cin >> i;
	while (m--) {
		cin >> aa >> b;
		if (aa <= k)
			o[aa] = max(o[aa], b);
	}
	sort(all(a));
	dp.resize(n + 1, 0);
	partial_sum(all(a), dp.begin() + 1);
	sum.resize(n, 0);
	partial_sum(all(a), sum.begin() + 1);
	for (int p = 0; p <= k; p++) {
		for (auto& i : o) {
			if (p < i.first)
				break;
			dp[p] = min(
					dp[p - i.first] + sum[p] - (sum[p - (i.first - i.second)]),
					dp[p]);
		}
	}
	cout << dp[k];

}