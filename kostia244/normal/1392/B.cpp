#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
		ll k;
		int n;cin >> n >> k;k &= 1;
		if(!k) k += 2;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		while(k--) {
			int t = *max_element(all(a));
			for(auto &i : a) i = t-i;
		}
		for(auto i : a) cout << i << " "; cout << '\n';
	}
}