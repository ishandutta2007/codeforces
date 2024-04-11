// Problem: D. Swap Pass
// Contest: Codeforces - Codeforces Round #715 (Div. 1)
// URL: https://codeforces.com/contest/1508/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	vector<array<ll, 3>> a;
	cin >> n;
	vector<int> srt;
	vector<array<int, 2>> ops;
	a.resize(n);
	for(auto &[a, b, i] : a)
		cin >> a >> b >> i;
	dsu d(n+1);
	for(int i = 0; i < n; i++) {
		if(1+i != a[i][2]) {
			srt.push_back(i);
			d.join(a[i][2], i+1);
		}
	}
	if(!srt.size()) return cout << "0\n", 0;
	int z = srt.back(); srt.pop_back();
	auto up = [&](int x) {
		return a[x][1]-a[z][1] > 0 || (a[x][1]-a[z][1] == 0 && a[x][0]-a[z][0] >= 0);
	};
	auto dot = [&](int x, int y) {
		return (a[x][0]-a[z][0])*(a[y][1]-a[z][1])-(a[x][1]-a[z][1])*(a[y][0]-a[z][0]);
	};
	sort(all(srt), [&](int x, int y) {
		if(up(x) != up(y)) return up(x) < up(y);
		return dot(x, y) > 0;
	});
	srt.push_back(srt[0]);
	for(int i = 1; i < srt.size(); i++) {
		if(dot(srt[i-1], srt[i]) <= 0) continue;
		if(d.join(a[srt[i-1]][2], a[srt[i]][2])) {
			ops.push_back({srt[i-1], srt[i]});
			swap(a[srt[i-1]][2], a[srt[i]][2]);
		}
	}
	while(a[z][2] != z+1) {
		ops.push_back({z, a[z][2]-1});
		swap(a[z][2], a[a[z][2]-1][2]);
	}
	for(int i = 0; i < n; i++) if(a[i][2] != i+1) exit(69);
	cout << ops.size() << '\n';
	for(auto &[x, y] : ops) cout << 1+x << " " << 1+y << '\n';
}