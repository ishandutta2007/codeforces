#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
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
const int N = 2020;
int n, a[N][N], deg[N], b[N];
bool check() {
	sort(b, b+n);
	ll edges = 0;
	for(int i = 0; i+1 < n; i++) {
		edges += b[i];
		if(edges == i*(i+1)/2)
			return false;
	}
	return true;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			char c;
			cin >> c;
			a[i][j] = c-'0';
			deg[i] += a[i][j];
		}
	for(int i = 0; i < n; i++)
		b[i] = deg[i];
	if(check()) {
		cout << "0 1\n";
		return 0;
	}
	if(n < 10) {
		auto get = [&](int msk, int v) { return msk>>v & 1; };
		int ans = n+1, cnt = 0;
		for(int msk = 0; msk < 1<<n; msk++) {
			memset(b, 0, sizeof b);
			for(int u = 0; u < n; u++) {
				for(int v = 0; v < n; v++) if(a[u][v]) {
					int rev = get(msk, u)^get(msk, v);
					b[rev?v:u]++;
				}
			}
			if(!check())
				continue;
			int C = __builtin_popcount(msk);
			if(C < ans)
				ans = C, cnt = 0;
			if(ans == C)
				cnt++;
		}
		for(int i = 1; i <= ans; i++)
			cnt *= i;
		if(!cnt) cout << "-1\n";
		else cout << ans << " " << cnt << endl;
	} else {
		int ans = 0;
		for(int u = 0; u < n; u++) {
			for(int v = 0; v < n; v++) if(u != v) {
					b[v] = deg[v] + (a[v][u] == 0 ? 1 : -1);
			}
			b[u] = n-1-deg[u];
			ans += check();
		}
		cout << "1 " << ans << '\n';
	}
}