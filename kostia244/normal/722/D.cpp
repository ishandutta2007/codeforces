#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
#include <bits/extc++.h> /** keep-include */
// To use most bits rather than just the lowest ones:
struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};//({},{},{},{},{1<<16});
int n;
int a[maxn];
bool can(int x, int rec = 0) {
	__gnu_pbds::gp_hash_table<int,int,chash> h;
	for(int i = 1; i <= n; i++) {
		int ok = 0, V = a[i];
		for(int b = 0; b < 30; b++) if((V>>b) && (V>>b)<x && !h[V>>b]) {h[V>>b] =1; ok = V>>b; break;}
		if(rec) cout << ok << " ";
		if(!ok) return false;
	}
	return 1;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 1<<30; i>>=1;) ans += i*!can(ans+i);
	can(ans+1, 1);cout << '\n';
}