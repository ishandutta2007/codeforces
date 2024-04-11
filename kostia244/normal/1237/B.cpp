#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
using namespace std;
using ll = int64_t;
const int maxn = 1<<25, mod = 1e9 + 7, B = 23000, R = (mod+1)/2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int t, i = 0; i < n; i++) {
		cin >> t;--t;
		a[t] = i;
	}
	for(auto &i : b) {
		cin >> i;
		i = a[--i];
	}
	auto c = b;
	for(int i = n-1; i-- > 0;) c[i] = min(c[i], c[i+1]);
	int ans = 0;
	for(int i = 0; i < n; i++) ans += b[i] != c[i];
	cout << ans << '\n';
}