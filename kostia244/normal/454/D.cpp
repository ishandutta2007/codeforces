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
typedef ll _I;
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
ll n, dp[101][1 << 17], pp[101][1 << 17], p[] = { 2, 3, 5, 7, 11, 13, 17, 19,
		23, 29, 31, 37, 41, 43, 47, 53, 59 };
ll m[61], ans = LLONG_MAX, ms;
vi a;
void bt(int i, int msk) {
	if (i > 1)
		bt(i - 1, msk ^ m[pp[i][msk]]);
	cout << pp[i][msk] << " ";
}
int main() {
	doin();
	cin >> n;
	getv(a, n);
	memset(dp, 10000, sizeof dp);
	m[1] = 0;
	for (int i = 2; i <= 60; i++) {
		for (int j = 0; j < 17; j++) {
			if (i % p[j] == 0)
				m[i] |= 1 << j;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int msk = 0; msk < 1 << 17; msk++) {
			for (int j = 1; j <= 60; j++) {
				if (msk & m[j])
					continue;
				if (dp[i + 1][msk | m[j]] > (dp[i][msk] + abs(a[i] - j)))
					dp[i + 1][msk | m[j]] = (dp[i][msk] + abs(a[i] - j)), pp[i
							+ 1][msk | m[j]] = j;
			}
		}
	}
	for (int msk = 0; msk < 1 << 17; msk++)
		if (ans > dp[n][msk])
			ans = dp[n][msk], ms = msk;
	bt(n, ms);
//	cout << ans;
}