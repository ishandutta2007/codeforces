#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n;
	char c = 'a';
	string s;
	cin >> n;
	while(n) {
		ll t = 1000;
		while(t*(t-1)/2 > n) t--;
		n -= t*(t-1)/2;
		while(t--) s += c;
		c++;
	}
	if(s.empty()) s = "a";
	cout << s << endl;
}