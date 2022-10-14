// Problem: E.   
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
void dijk(vector<vector<array<ll, 2>>> g, vector<ll> &dist) {
	int n = dist.size();
	priority_queue<array<ll, 2>> pq;
	for(int i = 0; i < n; i++) pq.push({-dist[i], i});
	while(!pq.empty()) {
		auto [d, v] = pq.top();
		pq.pop();
		if(-d > dist[v]) continue;
		for(auto [i, w] : g[v]) {
			if(dist[i] > dist[v] + w) {
				pq.push({-(dist[i] = dist[v] + w), i});
			}
		}
	}
}
__int128 eval(array<ll, 2> a, ll b) {
	return a[0] + b*a[1];
}
bool check(array<ll, 2> a, array<ll, 2> b, array<ll, 2> c) {
	swap(a[0], a[1]); swap(b[0], b[1]); swap(c[0], c[1]);
	//(a[1]-b[1]) * (b[0]-c[0])  > (b[1]-c[1])* (a[0]-b[0])
	if(b[1] == c[1]) return b[0] > c[0];
	__int128 A = (a[1]-b[1])*(__int128)1*(c[0]-b[0]);
	__int128 B = (b[1]-c[1])*(__int128)1*(b[0]-a[0]);
	if(((c[0]-b[0])<0) ^ ((b[0]-a[0])<0))
		swap(A, B);
	return A > B;
	// __int128 A = a[1] - b[1], B = b[1] - c[1];
	// A *= b[0] - c[0];
	// B *= a[0] - b[0];
	// return ((b[0]-c[0]<0) ^ (a[0]-b[0]<0)) ? A < B : A > B;
}
void cht(vector<ll> &dist) {
	int n = dist.size();
	vector<array<ll, 2>> lines;
	for(int i = 0; i < n; i++) {
		array<ll, 2> line = {i*1ll*i + dist[i], -2*i};
		while(lines.size() > 1 &&
			check(end(lines)[-2], end(lines)[-1], line))
			lines.pop_back();
		if(lines.size() && lines.back()[1] == line[1])
			continue;
		lines.push_back(line);
	}
	for(int j = 0, i = 0; i < n; i++) {
		while(j+1 < lines.size() && eval(lines[j+1], i) <= eval(lines[j], i))
			j++;
		// for(auto l : lines) {
			// dist[i] = min(dist[i], eval(l, i) + i*1l*i);
			// cout << eval(l, i) + i*1l*i << " ";
		// }cout << endl;
		dist[i] = eval(lines[j], i) + i*1ll*i;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<array<ll, 2>>> g(n);
	for(int f, t, w, i = 0; i < m; i++) {
		cin >> f >> t >> w;
		g[--f].push_back({--t, w});
		g[t].push_back({f, w});
	}
	vector<ll> dist(n, 1ll<<60);
	dist[0] = 0;
	dijk(g, dist);
	for(int i = 0; i < k; i++) {
		cht(dist);
		dijk(g, dist);
	}
	for(auto i : dist) cout << i << ' ';cout << '\n';
}