#pragma GCC optimize ("Ofast")
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
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
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
ll n, m, mat[200][200], iq = 0, mx = 0, k = -1, ans = 0;
vi di, dj;

int main() {
	doin();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j], mx = max(mx, mat[i][j]);

	for (int j = 1; j < m; j++)
		dj.pb(mat[0][j] - mat[0][j - 1]);
	for (int i = 1; i < n; i++)
		di.pb(mat[i][0] - mat[i - 1][0]);
	set<ll> s;
	for (int j = 1; j < m; j++) {
		for (int i = 1; i < n; i++) {
			ll t = (mat[i][j] - mat[i][j - 1])-(mat[i - 1][j] - mat[i - 1][j - 1]);
			ans = __gcd(ans, abs(t));
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			ll t = (mat[i][j] - mat[i - 1][j])-(mat[i][j - 1] - mat[i - 1][j - 1]);
			ans = __gcd(ans, abs(t));
		}
	}
	k = ans;
	if (k == 0)
		k = mx + 1;
	if (k == -1) {
		cout << "NO\n";
		return 0;
	}
	vi a, b;
	ll v = 0;
	for (int i = 0; i < n; i++) {
		a.pb(v);
		if(i == n-1) continue;
		v = (v + di[i]);
		if (v < 0) {
			v = k - (abs(v)%k);
		}
	}
	v = mat[0][0];
	for (int i = 0; i < m; i++) {
		b.pb(v);
		if(i == m-1) continue;
		v = (v + dj[i]) % k;
		if (v < 0) {
			v = k - (abs(v)%k);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if(mat[i][j] != (a[i]+b[j])%k) {
				cout << "NO\n";
				return 0;
			}
	cout << "YES\n";
	cout << k << "\n";
	for(auto i : a) cout << i << " ";
	cout << "\n";
	for(auto i : b) cout << i << " ";

}