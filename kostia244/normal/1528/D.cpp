// Problem: D. It's a bird! No, it's a plane! No, it's AaParsa!
// Contest: Codeforces - Codeforces Round #722 (Div. 1)
// URL: https://codeforces.com/contest/1528/problem/D
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
const int N = 606;
int n, m;
vector<array<int, 2>> g[N];
priority_queue<pair<int, ll>> pq;
ll dist[N], cst[N], PENIS[N];
int vis[N], S[N][N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> m;
	memset(S, 0x3f, sizeof S);
	for(int a, b, c, i = 0; i < m; i++) {
		cin >> a >> b >> c;
		S[a][b] = c;
	}
	for(int v = 0; v < n; v++) {
		#define cst S[v]
		for(int z = 0; z < 2; z++) {
			cst[0] = min(cst[0], cst[n-1]+1);
			for(int i = 1; i < n; i++) {
				cst[i] = min(cst[i], cst[i-1]+1);
			}
		}
		#undef cst
	}
	for(int i = 0; i < n; i++) {
		memset(dist, 0x3f, sizeof dist);
		memset(vis, 0, sizeof vis);
		dist[i] = 0;
		for(int _ = n; _--;) {
			int v = 0;
			while(vis[v]) v++;
			for(int i = 0; i < n; i++) if(!vis[i] && dist[i] < dist[v]) v = i;
			vis[v] = 1;
			//cout << "CH " << v << " " << dist[v] << endl;
			
			//for(auto [to, w] : g[v]) {
				//cout << (to+dist[v])%n << " " << dist[v]+w << endl;
			//	cst[(to+dist[v])%n] = dist[v]+w;
			//}
			int i = 0, z = dist[v]%n;
			for(i = 0; i+z < n; i++)
				cst[i+z] = dist[v]+S[v][i];
			for(; i < n; i++)
				cst[i+z-n] = dist[v]+S[v][i];
			for(int x = 0; x < n; x++) {
				dist[x] = min(dist[x], cst[x]);
			}
		}
		for(int i = 0; i < n; i++) cout << dist[i] << " "; cout << '\n';
	}
}