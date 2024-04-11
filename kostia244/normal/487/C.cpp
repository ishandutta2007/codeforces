#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = (1 << 20);
int n;
int bp(int a, int p) {
	int r = 1;
	while(p) {
		if(p&1) r = r*1ll*a%n;
		a = a*1ll*a%n, p>>=1;
	}
	return r;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	if(n == 1) {
		cout << "YES\n1\n";
		return 0;
	}
	if(n == 4) {
		cout << "YES\n1\n3\n2\n4\n";
		return 0;
	}
	int z =1;
	for(int i = 1; i < n; i++) z = z*1ll*i%n;
	if(!z) return cout << "NO\n", 0;
	cout << "YES\n";
	cout << "1\n";
	ll cur = 1;
	for(int i = 2; i < n; i++) {
		ll x = i*1ll*bp(cur, n-2)%n;
		cout << x%n << '\n';
		cur = cur*x%n;
	}
	cout << n << "\n";
}