// Problem:  
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1654/problem/E
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { // To use most bits rather than just the lowest ones:
	const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
	ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
};
const int N = 1e5 + 55, C = 50;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;
	int ans = 0;
	vector<int> a(n, 1);
	for(auto &i : a) cin >> i;
	for(int d = -C; d < C; d++) {
__gnu_pbds::gp_hash_table<ll,int,chash> h({},{},{},{},{1<<16});
		for(int i = 0; i < n; i++) {
			ans = max(ans, ++h[a[i]-i*d]);	
		}
	}
	vector<int> cnt(2*N);
	for(int i = 0; i < n; i++) {
		int M = 0;
		for(int j = 1; j < (N/C+1) && i+j < n; j++) {
			int d = (a[i]-a[i+j])/j;
			if(d*1ll*j==(a[i]-a[i+j]))
				M = max(M, ++cnt[N+d]);
		}
		ans = max(ans, 1+M);
		for(int j = 1; j < (N/C+1) && i+j < n; j++) {
			int d = (a[i]-a[i+j])/j;
			cnt[N+d] = 0;
		}
	}
	cout << n-ans << '\n';
}