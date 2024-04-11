// Problem: D. Limak and Shooting Points
// Contest: Codeforces - Codeforces Round #363 (Div. 1)
// URL: https://codeforces.com/contest/698/problem/D
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
vector<vector<vector<int>>> obs;
vector<int> die;
int mark;
int dfs(int v, int s, vector<int> &ord) {
	int S = s;
	s++;
	for(auto i : obs[v][ord[S]]) {
		if(die[i] == mark) continue;
		if(s==ord.size())
			return -1;
		s = dfs(i, s, ord);
		if(s == -1)
			return -1;
	}
	die[v] = mark;
	return s;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	const int K = 7;
	int k, n;
	cin >> k >> n;
	die.resize(n);
	vector<array<int, 2>> stones(k), bears(n);
	for(auto &[x, y] : stones)
		cin >> x >> y;
	for(auto &[x, y] : bears) {
		cin >> x >> y;
	}
	vector<array<int, 1<<K>> dp(n);
	obs = vector<vector<vector<int>>>(n, vector<vector<int>>(k));
	auto in = [&](int x, int y, int z) {
		return z >= min(x, y) && z <= max(x, y);
	};
	auto mustkill = [&](int l, int t, int o) {
		for(int z = 2;z--;)
		if(!in(bears[t][z], stones[l][z], bears[o][z]))
			return false;
		int a = bears[t][0]-stones[l][0];
		int b = bears[t][1]-stones[l][1];
		int c = bears[o][0]-bears[t][0];
		int d = bears[o][1]-bears[t][1];
		return a*1ll*d-c*1ll*b == 0;
	};
	for(int i = 0; i < n; i++) {
		for(int s = 0; s < k; s++) {
			for(int j = 0; obs[i][s].size() < k && j < n; j++) if(i != j) {
				if(mustkill(s, i, j)) {
					obs[i][s].push_back(j);
				}
			}
		}
	}
	vector<int> ord(k);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		iota(all(ord), 0);
		do {
			mark++;
			if(dfs(i, 0, ord) != -1) {
				ans++;
				break;
			}
		} while(next_permutation(all(ord)));
	}
	cout << ans << '\n';
}