#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
int f[maxn], t[maxn];
void add(int x, int v) {
	x++;
	for(; x < maxn; x += x&-x) f[x] += v;
}
int get(int x) {
	if(x <= 0) return 0;
	int r = 0;
	for(; x; x -= x&-x) r += f[x];
	return r;
}
int cnt[maxn];
void change(int x, int y, int V) {
	add(cnt[x], -1), add(cnt[y], -1);
	cnt[x]+=V, cnt[y]+=V;
	add(cnt[x], 1), add(cnt[y], 1);
}
int n, p;
ll ans = 0;
int x[maxn], y[maxn];
vector<int> g[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> p;
	for(int i = 0; i < n; i++) add(0, 1);
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
		change(x[i], y[i], 1);
	}
	for(int i = 1; i <= n; i++) {
		for(auto j : g[i]) {
			change(x[j], y[j], -1);
		}
		add(cnt[i], -1);
		ans += (n-1) - get(p-g[i].size());
		add(cnt[i], 1);
		for(auto j : g[i]) {
			change(x[j], y[j], 1);
		}
	}
	cout << ans/2 << endl;
}