#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define maxN 201000

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(i64 _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const mint& o) const {
		return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& o) { 
		v = int((i64)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
	friend mint pow(mint a, i64 p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};
 
const int MOD = 998244353;
using mi = mint<MOD,5>; // 5 is primitive root for both common mods

int n;
mi ans[maxN];
int main() {
	scanf("%d", &n);
	int m = (n + 1) / 2;
	mi v = 1, v2 = 0;
	for (int i = 1; i < m; i++) v = v * mi(i) * mi(i);
	for (int i = m; i >= 1; i--) {
		ans[i] = v - v2;
		if (i > 1) {
			v2 = v2 + v / mi(i - 1);
			v = v * mi(n + 1 - i) / mi(m + 1 - i) ;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d\n", (int)ans[i]);
}