#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#include<immintrin.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<17;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e10;
__int128 s1(__int128 n) {
	return n * (n+1)/2;
}
__int128 s2(__int128 n) {
	return n * (n+1) * (2*n + 1)/6;
}
__int128 s3(__int128 n) {
	__int128 t = s1(n);
	return t*t;
}
__int128 si1m(__int128 n) {//sum i * (2i+1) == 2*i^2 - i
	return 2*s2(n) - s1(n);
}
__int128 si2p(__int128 n) {//sum i^2 * (2i+1) == 2*i^3 + i^2
	return 2*s3(n) + s2(n);
}
__int128 calc(__int128 x, __int128 y) {
	if(!x || !y) return 0;
	__int128 ans = 0;
	ans += si1m(min(x, y));
	if(x >= y) {
		ans += (x-y)*s1(y);
	} else {
		__int128 t = (s1(2*x+1) - s1(x+1))*(y-x);
		t += s1(y-x-1)*2*x;
		ans += t;
	}
	ans += si2p(min(x, y)-1);
	if(y > x) swap(x, y);
	ans += (s2(x-1) - s2(y-1))*y;
	return ans;
}
string calc(__int128 lx, __int128 rx, __int128 ly, __int128 ry) {
	--lx, --ly;
	__int128 v = calc(rx, ry) - calc(lx, ry) - calc(rx, ly) + calc(lx, ly);
	string ans = "";
	ans += to_string(ll(v%mod));
	reverse(all(ans));
	if(v >= mod) {	
		while(ans.size() < 10) ans += "0";
		ans += "...";
	}
	reverse(all(ans));
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		ll xl, xr, yl, yr;
		cin >> xl >> yl >> xr >> yr;
		cout << calc(yl, yr, xl, xr) << '\n';
	}
}