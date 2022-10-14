// Problem: D. Strange LCS
// Contest: Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/contest/1588/problem/D
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
int id(char c) {
	if(c <= 'Z') return c-'A';
	return 26+c-'a';
}
char rid(int c) {
	if(c < 26) return 'A'+c;
	return 'a'+c-26;
}
		int n;
int dist[56][1<<10], U[56][1<<10], V[56][1<<10], trans[56][1<<10][56];
int pos[12][60][2], cnt[12][60];
vector<string> s;
int GO(int c, int msk, int d) {
	if(trans[c][msk][d] >= 0) return trans[c][msk][d];
	int nmsk = 0;
	for(int i = 0; i < n; i++) {
		int tp = (msk>>i)&1;
		if(max(pos[i][d][0], pos[i][d][1]) <= pos[i][c][tp])
			return trans[c][msk][d] = 1<<20;
		else if(pos[i][d][0] <= pos[i][c][tp])
			nmsk |= 1<<i;
	}
	return trans[c][msk][d] = nmsk;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		memset(dist, -1, sizeof dist);
		memset(trans, -1, sizeof trans);
		cin >> n;
		s = vector<string>(n);
		for(auto &i : s) cin >> i;
		memset(cnt, 0, sizeof cnt);
		memset(pos, -0x4f, sizeof pos);
		map<int, int> C;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < s[i].size(); j++) {
				int x = id(s[i][j]);
				if(cnt[i][x] == 0) C[x]++;
				pos[i][x][cnt[i][x]++] = j;
			}
		}
		priority_queue<array<int, 3>> go;
		auto enq = [&](int id, int msk, int d, int u, int v) {
			if(dist[id][msk] >= d) return;
			dist[id][msk] = d;
			U[id][msk] = u;
			V[id][msk] = v;
			go.push({d, id, msk});
		};
		int best = 0, a = -1, b = -1;
		for(auto [id, cnt] : C) {
			if(cnt == n) 
				enq(id, 0, 1, 0, 0);
		}
		while(!go.empty()) {
			auto [di, id, msk] = go.top();
			go.pop();
			if(di < dist[id][msk]) continue;
			if(best < di)
				best = di, a = id, b = msk;
			for(int i = 0; i < 56; i++) {
				int nmsk = GO(id, msk, i);
				if(nmsk > (1<<10)) continue;
				enq(i, nmsk, di+1, id, msk);
			}
		}
		string ss;
		cout << best << '\n';
		while(best--) {
			ss += rid(a);
			int x = U[a][b], y = V[a][b];
			a = x, b = y;
		}
		reverse(all(ss));
		cout << ss << '\n';
	});
	
}