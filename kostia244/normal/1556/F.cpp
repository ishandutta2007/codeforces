// Problem: F. Sports Betting
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int N = 14, mod = 1e9+7;
int n, a[N], G[1<<N], F[N][N];
void add(int &a, int b) {
	a = a+b>=mod?a+b-mod:a+b;
}
int inv(int x) {
	return x > 1 ? mod - (mod/x)*1ll*inv(mod%x)%mod : x;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			F[i][j] = a[i]*1ll*inv(a[i]+a[j])%mod;
	for(int msk = 1; msk < 1<<n; msk++) {
		G[msk] = 1;
		for(int sub = (msk-1)&msk; sub; sub = (sub-1)&msk) {
			int cur = G[sub];
			for(int i = 0; i < n; i++) if((sub>>i)&1) 
				for(int j = 0; j < n; j++) if(((msk^sub)>>j)&1) {
					cur = cur*1ll*F[i][j]%mod;
				}
			add(G[msk], mod-cur);
		}
	}
	int ans = 0;
	for(int sub = (1<<n)-1; sub; sub = sub-1) {
		int cur = G[sub];
		for(int i = 0; i < n; i++) if((sub>>i)&1) 
			for(int j = 0; j < n; j++) if(((~sub)>>j)&1) {
				cur = cur*1ll*F[i][j]%mod;
			}
		ans = (ans + cur*1ll*__builtin_popcount(sub))%mod;
	}
	cout << ans << '\n';
}