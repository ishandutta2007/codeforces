#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
typedef unsigned uint;
using namespace std;
char gc() {
   static char buf[1 << 16], *S, *T;
   if(S == T) T = (S = buf) + fread(buf, 1, 1 << 16, stdin);
   return S == T ? EOF : *S ++;
}
template<class T> void read(T &x) {
   x = 0; bool na = 0; char c = gc();
   for(; c < '0' || c > '9'; c = gc()) na |= c == '-';
   for(; c >= '0' && c <= '9'; c = gc()) x = x * 10 + (c & 15);
   if(na) x = -x;
}
const int N = 1 << 20 | 10;
int h, g, a[N], d[N] = {-1}, f[N];
vector<int> G[N];
bool use[N];
ll ans;
bool cmp(int x, int y) {
	return a[x] < a[y];
}
void solve(int u) {
	d[u] = d[u >> 1] + 1; G[u].clear();
	if(d[u] == h - 1) { G[u].pb(u); return ; }
	solve(u << 1); solve(u << 1 | 1);
	uint pos = 0;
	for(uint i = 0; i < G[u << 1].size(); i ++) {
		while(pos < G[u << 1 | 1].size() && cmp(G[u << 1 | 1][pos], G[u << 1][i])) {
			G[u].pb(G[u << 1 | 1][pos ++]);
		}
		G[u].pb(G[u << 1][i]);
	}
	while(pos < G[u << 1 | 1].size()) G[u].pb(G[u << 1 | 1][pos ++]);
	G[u].push_back(u);
	if(d[u] < g) {
		int lim = d[u] == g - 1 ? 0 : max(f[u << 1], f[u << 1 | 1]);
		vector<int>::iterator it = G[u].begin(); 
		while(a[*it] < lim) it ++;
		use[*it] = 1; f[u] = a[*it]; ans += f[u];
		G[u].erase(G[u].begin(), it + 1);
	}
}
int main() {
//	freopen("input.cpp", "r", stdin);
	int t; read(t);
	while(t --) {
		read(h); read(g);
		int n = (1 << h) - 1; ans = 0;
		for(int i = 1; i <= n; i ++) read(a[i]);
		fill(use + 1, use + n + 1, 0);
		solve(1);
		printf("%lld\n", ans);
		for(int i = n; i >= 1; i --)
			if(!use[i]) printf("%d ", i);
		putchar('\n');
	} 
	return 0;
}