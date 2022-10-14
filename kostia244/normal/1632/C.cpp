// Problem: C. Strange Test
// Contest: Codeforces - Codeforces Round #769 (Div. 2)
// URL: https://codeforces.com/contest/1632/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
vector<int> vis, viss;
queue<int> q;
int a, b;
void add(int v, int d) {
	if(vis[v] == 1<<28) {
		vis[v] = d;
		q.push(v);
	}
}
void dfs(int v, int d) {
	if(v > 2*b || viss[v]) return;
	viss[v] = 1;
	if(v >= b)
		add(v, d);
	for(int z = 0; z < 20; z++)
		dfs(v|(1<<z), d);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		cin >> a >> b;
		vis.assign(2*b+2, 1<<28);
		viss.assign(2*b+2, 0);
		q = queue<int>();
		add(a, 0);
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			if(v+1 <= 2*b)
				add(v+1, vis[v]+1);
			dfs(v, vis[v]+1);
		}
		int ans = 1<<30;
		for(int i = b; i <= 2*b; i++) ans = min(ans, vis[i]+i-b);
		cout << ans << '\n';
	});
	
}