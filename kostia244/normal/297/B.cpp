#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1010, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dp[maxn][maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<array<int, 2>> a;
	int n, m, k;
	cin >> n >> m >> k;
	while(n--) {
		cin >> k;
		a.push_back({k, 1});
	}
	while(m--) {
		cin >> k;
		a.push_back({k, -1});
	}
	sort(all(a), greater<>());
	int cur = 0, ok = 0;
	for(int i = 0; i < a.size(); i++) {
		cur += a[i][1];
		if(i+1 == a.size() || a[i][0] != a[i+1][0]) ok |= cur > 0;
	}
	cout << (ok?"YES\n":"NO\n");
}

//    v
//...........
//    ^