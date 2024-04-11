#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define oit ostream_iterator
#define mod 1000000007ll
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
template<typename T>
void getv1(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv1(vector<T>& v, int n, Ns ... ns) {
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		getv(v[i], ns...);
}
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
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
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
uniform_real_distribution<double> double_dist(0, 1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll dp[2020][2020], sm[2020][2020], n, k;
string s;

int main() {
	doin();
	cin >> n >> k >> s;
	dp[0][0] = sm[0][0] = 1;
	for (int i = 1; i <= n; i++) {
//		sm[i][0] = sm[i-1][0]+1;
//		dp[i][0] = 1;
		for (int j = 0; j <= k; j++) {
			dp[i][j] = (sm[i-1][j]*1ll*(s[i-1]-'a'))%mod;
			for(int pref = 0; pref < i && ((pref+1)*(n-i+1)) <= j; pref++) {
				(dp[i][j] += (dp[i-pref-1][j - (pref+1)*(n-i+1)]*1ll*('z'-s[i-1]))%mod)%=mod;
			}
			(sm[i][j] = sm[i-1][j] + dp[i][j])%=mod;
		}
	}
	cout << sm[n][k];
}