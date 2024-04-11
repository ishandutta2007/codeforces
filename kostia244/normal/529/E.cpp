#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 5050;
int n, k, a[maxn];
map<int, int> can;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	can[0] = 0;
	for(int i =1 ; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(!can.count(a[i]*j)) can[a[i]*j] = j;
			can[a[i]*j] = min(can[a[i]*j], j);
		}
	}
	int q, x;
	for(cin >> q; q--;) {
		cin >> x;
		int ans = 33;
		for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k && x-a[i]*j >= 0; j++) {
			if(can.count(x-a[i]*j)) ans = min(ans, j + can[x-a[i]*j]);
		}
		if(ans > k) ans = -1;
		cout << ans << '\n';
	}
}