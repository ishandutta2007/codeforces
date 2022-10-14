#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vector<int> g[maxn];
int bc[maxn];
void bip(int v, int col) {
	bc[v] = col;
	for(auto &i : g[v]) {
		if(!bc[i]) {
			bip(i, col^3);
		}
		if(bc[v] == bc[i]) {
			cout << "NO\n";
			exit(0);
		}
	}
}
vector<array<int, 3>> edges;
int lst;
#define maxx max
#define max xxxx
#define min yyy
int max(int a, int b) {
	if(b > a) lst = 1;
	return b > a ? b : a;
}
int min(int a, int b) {
	if(b < a) lst = 1;
	return b < a ? b : a;
}
int bfs(int s, int rec = 0) {
	vector<int> mn(n+1, 0), mx(n+1, 1<<30);
	mx[s] = 0;
	for(int it = 0; it < n; it++) {
		lst = 0;
		for(auto [f, x, y] : edges) {
			if(f) {//y > x
				mn[y] = max(mn[y], mn[x]+1);
				mx[y] = min(mx[y], mx[x]+1);
				mn[x] = max(mn[x], mn[y]-1);
				mx[x] = min(mx[x], mx[y]-1);
			} else {
				mn[y] = max(mn[y], mn[x]-1);
				mx[y] = min(mx[y], mx[x]+1);
				mn[x] = max(mn[x], mn[y]-1);
				mx[x] = min(mx[x], mx[y]+1);
			}
		}
	}
	if(lst) return -1;
	for(int i = 1; i <= n; i++) if(mn[i] > mx[i]) return -1;
	int ans = 0;
	for(int i = 1; i <= n; i++) ans =maxx(ans, mx[i]);
	if(rec) {
		cout << "YES\n";
		cout << ans << '\n';
		for(int i =1 ; i <= n; i++) cout << mx[i] << " "; cout << '\n';
		exit(0);
	}
	return ans;
}
#undef max
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int f, t, z, i = 0; i < m; i++) {
		cin >> f >> t >> z;
		g[f].push_back(t);
		g[t].push_back(f);
		edges.push_back({z, f, t});
	}
	bip(1, 1);
	sort(all(edges));
	array<int, 2> ans = {-1, -1};
	for(int i = 1; i <= n; i++)
		ans = max(ans, {bfs(i), i});
	if(ans[0] == -1) {
		cout << "NO\n";
		return 0;
	}
	bfs(ans[1], 1);
}