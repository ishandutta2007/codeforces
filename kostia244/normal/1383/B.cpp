#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 1<<20, mod = 119<<23|1;
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t, n;
	cin >> t;
	while(t--) {
		cin >>n;
		vector<int> a(n);
		int x = 0;
		for(auto &i : a) cin >> i, x ^= i;
		if(x == 0) {
			cout << "DRAW\n";
			continue;
		}
		int h = 0;
		while((2<<h) <= x) h++;
		x = 0;
		for(auto &i : a) x += (i>>h)&1;
		if(x%4 == 1) {
			cout << "WIN\n";
		} else {
			if((a.size()-x)&1) cout << "WIN\n";
			else cout << "LOSE\n";
		}
	}
}