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
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
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
ll n, a[10], dp[101][10], C[110][110], s = 0, ans  = 0;

ll f(ll l, ll c) {
	if (dp[l][c] != -1)
		return dp[l][c];
	ll ans = 0;
	if (c == 0) {
		for(ll len = a[0]; len <= l; len++) {
			ans += (f(l-len, 1)*C[l-1][len])%mod;
			ans %= mod;
		}
	} else if (c == 9) {
		return dp[l][c] =  l >= a[9];
	} else {
		for(ll len = a[c]; len <= l; len++) {
			ans += (f(l-len, c+1)*C[l][len])%mod;
			ans %= mod;
		}
	}
	return dp[l][c] = ans;
}

int main() {
	memset(dp, -1, sizeof dp);
	doin();
	cin >> n;
	for (int i = 0; i < 10; i++)
		cin >> a[i], s+= a[i];
	C[0][0] = 1;
	for(ll i = 1; i <= n; C[i++][0] = 1)
		for(ll j = 1; j <= i; j++)
			(C[i][j] = C[i-1][j-1]+C[i-1][j])%=mod;
	for(ll i = max(1ll, s); i <= n; i++)
		(ans += f(i, 0))%=mod;
	cout << ans;
}