// Problem: O. Circular Maze
// Contest: Codeforces - SWERC 2021-2022 - Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1662/problem/O
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	const int L = 24;
	multitest([&](){
		vector<vector<int>> blockR(L, vector<int>(360));
		vector<vector<int>> blockO(L, vector<int>(360));
		vector<vector<int>> vis(L, vector<int>(360));
		int n;
		cin >> n;
		while(n--) {
			char C;
			cin >> C;
			if(C == 'C') {
				int r, o1, o2;
				cin >> r >> o1 >> o2;
				for(; o1 != o2; o1 = (o1+1)%360)
					blockR[r][o1] = 1;
			} else {
				int r1, r2, o;
				cin >> r1 >> r2 >> o;
				for(; r1 != r2; r1 = (r1+1))
					blockO[r1][o] = 1;
			}
		}
		queue<pair<int, int>> q;
		auto add = [&](int x, int y) {
			if(!vis[x][y]++) {
				q.push({x, y});
			}
		};
		add(0, 0);
		while(!q.empty()) {
			auto [r, o] = q.front();
			q.pop();
			if(r >= L-1) {
				cout << "YES\n";
				return;
			}
			if(!blockR[r+1][o]) {
				add(r+1, o);
			}
			if(r && !blockR[r][o]) {
				add(r-1, o);
			}
			if(!blockO[r][o]) {
				add(r, (o+359)%360);
			}
			if(!blockO[r][(o+1)%360]) {
				add(r, (o+1)%360);
			}
		}
		cout << "NO\n";
	});
	
}